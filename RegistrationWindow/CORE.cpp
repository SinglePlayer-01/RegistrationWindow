// Skeleton of the project
#include<windows.h>
// Graphics libraries
#include<d2d1.h>
#include<dwrite.h>
// Network library
//#include<WinSock2.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")
//#pragma comment(lib, "Ws2_32.lib")

#include"RegistrationWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	RegistrationWindow log;

	if (!log.Create(L"LoginWindow", WS_BORDER, NULL, 500, 500, 650, 400, NULL, NULL))	return 0;

	ShowWindow(log.Window(), SW_SHOW);

	MSG msg = {	};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}