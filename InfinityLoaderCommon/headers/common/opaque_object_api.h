
#pragma once

#define OpaqueObjectBoilerplateAPIDef(className)             \
	IMPORT className();                                      \
	IMPORT className(const className& other);                \
	IMPORT className(className&& other) noexcept;            \
	IMPORT className& operator=(className&& other) noexcept; \
	IMPORT className& operator=(const className& other);     \
	IMPORT ~className();
