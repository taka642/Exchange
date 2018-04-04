#include <Windows.h>
#include "ExchangeConstant.h"

/*
 * ウィンドウプロシージャ
 */
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0L;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

/*
 * ウィンドウクラスの登録
 */
bool exchangeWindowRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEX wndClassEx =
	{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WindowProcedure,
		0,
		0,
		hInstance,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		APPLICATION_NAME,
		LoadIcon(NULL, IDI_APPLICATION)
	};

	if (RegisterClassEx(&wndClassEx) == 0) return false;
	return true;
}

/*
 * ウィンドウの生成
 */
bool createExchangeWindow(HINSTANCE hInstance) {
	HWND hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		APPLICATION_NAME,
		APPLICATION_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hWnd == NULL) return false;

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	return true;
}

/*
 * メイン
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int CmdShow) {

	if (!exchangeWindowRegisterClass(hInstance)) return 1;

	if (!createExchangeWindow(hInstance)) return 1;

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}