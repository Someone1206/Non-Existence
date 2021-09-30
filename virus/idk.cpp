#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

enum buttons
{
	ID_OK,
	ID_SRRY
};

int CALLBACK WinMain(
		HINSTANCE hInst,
		HINSTANCE hPrevInst,
		LPSTR     pCmdLine,
		int       nCmdShow)
{
	const char* cNamae = "Kill Me";
	// h_PInst = hInst;

	int ht = GetSystemMetrics(SM_CYSCREEN), wd = GetSystemMetrics(SM_CXSCREEN);
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = /*CS_DROPSHADOW | */CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = cNamae;
	wc.hIconSm = nullptr;

	RegisterClassEx( &wc );

	HWND hWnd = CreateWindowEx(
			0, cNamae,
			"私は死んでいる",
			WS_BORDER | WS_CAPTION | WS_MINIMIZEBOX | WS_OVERLAPPED | WS_POPUP | WS_SYSMENU,
			wd / 3, ht / 3, 400, 260,
			nullptr, nullptr, hInst, nullptr
			);

	ShowWindow(hWnd, SW_SHOW);
	BOOL idk = SetWindowPos(hWnd, HWND_TOPMOST, wd / 3, ht / 3, 400, 260, SWP_SHOWWINDOW);

	LPCSTR message = 
			"An 'Ho'-nest message:\n\n" 
			"I am just a useless virus, but I can harm you in many ways.\n\n"
			"I can't do anything myself, but if you wanna see some payloads,"
			" you should try deleting some files and folders in your \"C:\\Windows\\\" folder";
	ShowWindow(CreateWindowEx(
			0, "static",
			message,
			WS_CHILD,
			10, 0, 250, 240,
			hWnd, nullptr, hInst, nullptr
			), SW_SHOW);

	ShowWindow(CreateWindowEx(
				0, "button",
				"Ok I'll do it",
				WS_CHILD,
				265, 10, 90, 40,
				hWnd, (HMENU)buttons::ID_OK, hInst, nullptr
				), SW_SHOW);


	ShowWindow(CreateWindowEx(
				0, "button",
				"Sorry",
				WS_CHILD,
				265, 60, 90, 40,
				hWnd, (HMENU)buttons::ID_SRRY, hInst, nullptr
				), SW_SHOW);




	MSG msg;
	BOOL res;

	while ((res = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	if (res == -1)
		return -1;
	return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == buttons::ID_OK) 
		{
			ShowWindow(hWnd, SW_HIDE);
			MessageBox(hWnd, "Please don't make me sad, do some favor to me.", "Bye, see you again", MB_OK | MB_ICONINFORMATION);
			PostQuitMessage(69);
		}
		else if (LOWORD(wParam) == buttons::ID_SRRY)
		{
			ShowWindow(hWnd, SW_HIDE);
			MessageBox(hWnd, "Please do it.", " ", MB_OK | MB_ICONINFORMATION);
			PostQuitMessage(69);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(69);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
