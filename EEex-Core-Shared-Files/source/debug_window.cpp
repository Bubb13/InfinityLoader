
#include <d3d9.h>

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "implot.h"

#include "im_rolling_line_graph.hpp"

///////////////
// Constants //
///////////////

static constexpr ImVec4 clear_color { 0.45f, 0.55f, 0.60f, 1.00f };

/////////////
// Globals //
/////////////

//-----------//
// DX9 State //
//-----------//

ImRollingLineGraph<TimeType> rollingScrollDeltaX { "Delta X", "Seconds ago", "Exact Map Units", 5000000, 1000000 };
ImRollingLineGraph<TimeType> rollingScrollDeltaY { "Delta Y", "Seconds ago", "Exact Map Units", 5000000, 1000000 };

ImRollingLineGraph<TimeType> rollingFlipTime { "Flip Time", "Seconds ago", "Microseconds", 5000000, 1000000 };
ImRollingLineGraph<TimeType> rollingTimeBetweenFlipEnds { "Time Between Flip Ends", "Seconds ago", "Microseconds", 5000000, 1000000 };

ImRollingLineGraph<TimeType> rollingTimeBetweenFullUpdates { "Time Between Full Updates", "Seconds ago", "Microseconds", 5000000, 1000000 };

//-----------//
// DX9 State //
//-----------//

static LPDIRECT3D9 g_pD3D = nullptr;
static LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;
static bool g_DeviceLost = false;
static UINT g_ResizeWidth = 0;
static UINT g_ResizeHeight = 0;
static D3DPRESENT_PARAMETERS g_d3dpp = {};
static HWND g_WindowHandle = NULL;

//////////////////////
// Helper Functions //
//////////////////////

static bool createDeviceD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == nullptr)
	{
		return false;
	}

	// Create the D3DDevice
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate

	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{
		return false;
	}

	return true;
}

static void cleanupDeviceD3D()
{
	if (g_pd3dDevice)
	{
		g_pd3dDevice->Release();
		g_pd3dDevice = nullptr;
	}

	if (g_pD3D)
	{
		g_pD3D->Release();
		g_pD3D = nullptr;
	}
}

static void resetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);

	if (hr == D3DERR_INVALIDCALL)
	{
		IM_ASSERT(0);
	}

	ImGui_ImplDX9_CreateDeviceObjects();
}

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
static LRESULT WINAPI debugWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Forward declare message handler from imgui_impl_win32.cpp
	extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
	{
		return true;
	}

	switch (msg)
	{
		case WM_SIZE:
		{
			if (wParam == SIZE_MINIMIZED)
			{
				return 0;
			}

			g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
			g_ResizeHeight = (UINT)HIWORD(lParam);
			return 0;
		}
		case WM_SYSCOMMAND:
		{
			if ((wParam & 0xFFF0) == SC_KEYMENU) // Disable ALT application menu
			{
				return 0;
			}

			break;
		}
		case WM_DESTROY:
		{
			g_WindowHandle = NULL;
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

/////////////
// Drawing //
/////////////

static void drawGraphWindow()
{
	ImGui::Begin("Frame Timings");
	rollingFlipTime.Draw(getTime());
	rollingTimeBetweenFlipEnds.Draw(getTime());
	rollingTimeBetweenFullUpdates.Draw(getTime());
	ImGui::End();

	ImGui::Begin("Scroll Deltas");
	rollingScrollDeltaX.Draw(getTime());
	rollingScrollDeltaY.Draw(getTime());
	ImGui::End();
}

////////////////////
// Initialization //
////////////////////

static DWORD runDebugWindow()
{
	//////////////////////////////////////////////////////////
	// Make process DPI aware and obtain main monitor scale //
	//////////////////////////////////////////////////////////

	ImGui_ImplWin32_EnableDpiAwareness();
	float main_scale = ImGui_ImplWin32_GetDpiScaleForMonitor(MonitorFromPoint(POINT{ 0, 0 }, MONITOR_DEFAULTTOPRIMARY));

	///////////////////////////////
	// Create application window //
	///////////////////////////////

	WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, debugWindowProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
	RegisterClassExW(&wc);
	g_WindowHandle = CreateWindowW(wc.lpszClassName, L"EEex Debug Window", WS_OVERLAPPEDWINDOW, 100, 100, (int)(1280 * main_scale), (int)(800 * main_scale), nullptr, nullptr, wc.hInstance, nullptr);

	/////////////////////////
	// Initialize Direct3D //
	/////////////////////////

	if (!createDeviceD3D(g_WindowHandle))
	{
		cleanupDeviceD3D();
		UnregisterClassW(wc.lpszClassName, wc.hInstance);
		return 1;
	}

	/////////////////////
	// Show the window //
	/////////////////////

	ShowWindow(g_WindowHandle, SW_SHOWDEFAULT);
	UpdateWindow(g_WindowHandle);

	/////////////////////////
	// Setup ImGui context //
	/////////////////////////

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImPlot::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	///////////////////////
	// Setup ImGui style //
	///////////////////////

	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	/////////////////////////
	// Setup ImGui scaling //
	/////////////////////////

	ImGuiStyle& style = ImGui::GetStyle();
	style.ScaleAllSizes(main_scale);        // Bake a fixed style scale. (until we have a solution for dynamic style scaling, changing this requires resetting Style + calling this again)
	style.FontScaleDpi = main_scale;        // Set initial font scale. (in docking branch: using io.ConfigDpiScaleFonts=true automatically overrides this for every window depending on the current monitor)

	////////////////////////////////////////////
	// Setup ImGui Platform/Renderer backends //
	////////////////////////////////////////////

	ImGui_ImplWin32_Init(g_WindowHandle);
	ImGui_ImplDX9_Init(g_pd3dDevice);

	////////////////
	// Load fonts //
	////////////////

	// - If fonts are not explicitly loaded, Dear ImGui will select an embedded font: either AddFontDefaultVector() or AddFontDefaultBitmap().
	//   This selection is based on (style.FontSizeBase * style.FontScaleMain * style.FontScaleDpi) reaching a small threshold.
	// - You can load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - If a file cannot be loaded, AddFont functions will return a nullptr. Please handle those errors in your code (e.g. use an assertion, display an error and quit).
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use FreeType for higher quality font rendering.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//style.FontSizeBase = 20.0f;
	//io.Fonts->AddFontDefaultVector();
	//io.Fonts->AddFontDefaultBitmap();
	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf");
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf");
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf");
	//IM_ASSERT(font != nullptr);

	//////////////////////
	// Main thread loop //
	//////////////////////

	bool done = false;

	while (!done)
	{
		//////////////////
		// Message loop //
		//////////////////

		MSG msg;
		while (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				done = true;
			}
		}

		if (done)
		{
			break;
		}

		/////////////////////////////
		// Handle lost D3D9 device //
		/////////////////////////////

		if (g_DeviceLost)
		{
			HRESULT hr = g_pd3dDevice->TestCooperativeLevel();

			if (hr == D3DERR_DEVICELOST)
			{
				Sleep(10);
				continue;
			}

			if (hr == D3DERR_DEVICENOTRESET)
			{
				resetDevice();
			}

			g_DeviceLost = false;
		}

		////////////////////////////////////////////////////////////////////////////
		// Handle window resize (we don't resize directly in the WM_SIZE handler) //
		////////////////////////////////////////////////////////////////////////////

		if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
		{
			g_d3dpp.BackBufferWidth = g_ResizeWidth;
			g_d3dpp.BackBufferHeight = g_ResizeHeight;
			g_ResizeWidth = g_ResizeHeight = 0;
			resetDevice();
		}

		//////////////////////
		// Draw ImGui frame //
		//////////////////////

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		// Custom drawing
		drawGraphWindow();

		ImGui::EndFrame();

		//////////////////////
		// Clear background //
		//////////////////////

		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*clear_color.w*255.0f), (int)(clear_color.y*clear_color.w*255.0f), (int)(clear_color.z*clear_color.w*255.0f), (int)(clear_color.w*255.0f));
		g_pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);

		////////////////////////
		// Render via DirectX //
		////////////////////////

		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}

		//////////////////////
		// Flip via DirectX //
		//////////////////////

		HRESULT result = g_pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);

		if (result == D3DERR_DEVICELOST)
		{
			g_DeviceLost = true;
		}
	}

	/////////////
	// Cleanup //
	/////////////

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImPlot::DestroyContext();
	ImGui::DestroyContext();

	cleanupDeviceD3D();
	DestroyWindow(g_WindowHandle);
	UnregisterClassW(wc.lpszClassName, wc.hInstance);

	return 0;
}

static DWORD WINAPI debugWindowThread(LPVOID lpParam)
{
	return runDebugWindow();
}

void CreateDebugWindow()
{
	CreateThread(nullptr, 0, debugWindowThread, nullptr, 0, nullptr);
}

bool IsDebugWindowOpen()
{
	return g_WindowHandle != NULL;
}
