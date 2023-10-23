
#pragma once

#include <functional>
#include <mutex>

// The OpaqueObject class has been designed to hide its implementation from users - it uses
// PImpl and dynamic memory allocation. OpaqueObject subclasses should provide a static
// Create() function to create new objects. The implementation of OpaqueObject, and the
// implementation of the data classes, can be changed without breaking ABI as long as all
// exported functions maintain their contract.

// TODO: The locking in this implementation is probably broken.

namespace OpaqueObject {

	enum class AllocMode {
		DEFER,
		NOW,
	};

	template<typename T>
	class Obj {
	private:
		class Imp;
		Imp* imp;
		static T* defaultAllocFunc();
		static void defaultFreeFunc(T*);
		void freeData(std::unique_lock<std::mutex>& myLock);
	protected:
		T* data();
	public:
		typedef std::function<T*()> AllocFunc;
		typedef std::function<void(T*)> FreeFunc;
		// Constructors
		Obj(AllocFunc allocFunc, FreeFunc freeFunc, AllocMode allocMode);
		Obj(AllocMode allocMode);
		Obj();
		Obj(const Obj<T>& other);
		Obj(Obj<T>&& other) noexcept;
		// Operators
		Obj<T>& operator=(Obj<T>&& other) noexcept;
		Obj<T>& operator=(const Obj<T>& other);
		// Destructor
		~Obj();
	};

	template<typename T>
	class Obj<T>::Imp {
	public:
		std::mutex lock{};
		size_t refCount = 1;
		AllocFunc allocFunc;
		FreeFunc freeFunc;
		T* data;
	};

	template<typename T>
	void Obj<T>::freeData(std::unique_lock<std::mutex>& myLock) {
		if (--imp->refCount == 0) {
			T* data = imp->data;
			if (data != nullptr) {
				imp->freeFunc(data);
			}
			myLock.unlock();
			delete imp;
		}
	}

	template<typename T>
	T* Obj<T>::defaultAllocFunc() {
		return new T{};
	}

	template<typename T>
	void Obj<T>::defaultFreeFunc(T* data) {
		delete data;
	}

	template<typename T>
	T* Obj<T>::data() {
		return imp->data;
	}

	template<typename T>
	Obj<T>::Obj(AllocFunc allocFunc, FreeFunc freeFunc, AllocMode allocMode) {
		imp = new Obj<T>::Imp{};
		imp->allocFunc = allocFunc;
		imp->freeFunc = freeFunc;
		if (allocMode == AllocMode::NOW) {
			imp->data = allocFunc();
		}
	}

	template<typename T>
	Obj<T>::Obj(AllocMode allocMode)
		: Obj(&defaultAllocFunc, &defaultFreeFunc, allocMode)
	{}

	// Default Constructor
	template<typename T>
	Obj<T>::Obj()
		: Obj(&defaultAllocFunc, &defaultFreeFunc, AllocMode::DEFER)
	{}

	// Copy Constructor
	template<typename T>
	Obj<T>::Obj(const Obj<T>& other)
		: Obj<T>()
	{
		std::unique_lock<std::mutex> lk1(imp->lock, std::defer_lock);
		std::unique_lock<std::mutex> lk2(other.imp->lock, std::defer_lock);
		std::lock(lk1, lk2);

		imp = other.imp;
		++imp->refCount;
	}

	// Move Constructor
	template<typename T>
	Obj<T>::Obj(Obj<T>&& other) noexcept
		: Obj<T>()
	{
		std::unique_lock<std::mutex> lk1(imp->lock, std::defer_lock);
		std::unique_lock<std::mutex> lk2(other.imp->lock, std::defer_lock);
		std::lock(lk1, lk2);

		imp = other.imp;
		other.imp = nullptr;
	}

	// Copy Operator
	template<typename T>
	Obj<T>& Obj<T>::operator=(const Obj<T>& other) {

		std::unique_lock<std::mutex> lk1(imp->lock, std::defer_lock);
		std::unique_lock<std::mutex> lk2(other.imp->lock, std::defer_lock);
		std::lock(lk1, lk2);

		freeData(lk1);
		imp = other.imp;
		++imp->refCount;

		return *this;
	}

	// Move Operator
	template<typename T>
	Obj<T>& Obj<T>::operator=(Obj<T>&& other) noexcept {

		std::unique_lock<std::mutex> lk1(imp->lock, std::defer_lock);
		std::unique_lock<std::mutex> lk2(other.imp->lock, std::defer_lock);
		std::lock(lk1, lk2);

		freeData(lk1);
		imp = other.imp;
		other.imp = nullptr;

		return *this;
	}

	// Destructor
	template<typename T>
	Obj<T>::~Obj() {
		Imp *const impCopy = imp;
		if (impCopy != nullptr) {
			std::unique_lock<std::mutex> lk1{impCopy->lock};
			freeData(lk1);
		}
	}
}

#define OpaqueObjectBoilerplateDef(className)                                             \
	className(AllocFunc allocFunc, FreeFunc freeFunc, OpaqueObject::AllocMode allocMode); \
	className(OpaqueObject::AllocMode allocMode);                                         \
	EXPORT className();                                                                   \
	EXPORT className(const className& other);                                             \
	EXPORT className(className&& other) noexcept;                                         \
	EXPORT className& operator=(className&& other) noexcept;                              \
	EXPORT className& operator=(const className& other);                                  \
	EXPORT ~className();

#define OpaqueObjectBoilerplateImp(className, dataClassName)                                        \
	className::className(AllocFunc allocFunc, FreeFunc freeFunc, OpaqueObject::AllocMode allocMode) \
		: OpaqueObject::Obj<dataClassName>(allocFunc, freeFunc, allocMode) {}                       \
	                                                                                                \
	className::className(OpaqueObject::AllocMode allocMode)                                         \
		: OpaqueObject::Obj<dataClassName>(allocMode) {}                                            \
	                                                                                                \
	EXPORT className::className()                                                                   \
		: OpaqueObject::Obj<dataClassName>() {}                                                     \
	                                                                                                \
	EXPORT className::className(const className& other)                                             \
		: OpaqueObject::Obj<dataClassName>(other) {}                                                \
	                                                                                                \
	EXPORT className::className(className&& other) noexcept                                         \
		: OpaqueObject::Obj<dataClassName>(other) {}                                                \
	                                                                                                \
	EXPORT className& className::operator=(className&& other) noexcept {                            \
		OpaqueObject::Obj<dataClassName>::operator=(other);                                         \
		return *this;                                                                               \
	}                                                                                               \
	                                                                                                \
	EXPORT className& className::operator=(const className& other) {                                \
		OpaqueObject::Obj<dataClassName>::operator=(other);                                         \
		return *this;                                                                               \
	}                                                                                               \
	                                                                                                \
	EXPORT className::~className() {}
