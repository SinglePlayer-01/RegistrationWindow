#include<Windows.h>

#include"RegistrationWindow.h"

LRESULT RegistrationWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		// 
	case WM_CREATE:
	{
		Create_Factory();
		GetClientRect(m_hwnd, &rc);
		edit_Login = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 65, 220, 26, m_hwnd, NULL, NULL, NULL);
		edit_Password = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 165, 220, 26, m_hwnd, NULL, NULL, NULL);
		edit_RepeatPassword = CreateWindow(L"EDIT", NULL, WS_CHILD , 178.5, 265, 220, 26, m_hwnd, NULL, NULL, NULL);

		ShowWindow(edit_Login, SW_SHOW);
		ShowWindow(edit_Password, SW_SHOW);
		ShowWindow(edit_RepeatPassword, SW_SHOW);

		// Creating the font we need
		HFONT hFont = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");

		// Set your font
		SendMessage(edit_Login, WM_SETFONT, (WPARAM)hFont, TRUE);
		SendMessage(edit_Password, WM_SETFONT, (WPARAM)hFont, TRUE);
	}

	return 0;

	case WM_PAINT:

		Draw_WallPaper();

		return 0;

	// 
	case WM_DESTROY:
		Discard_GraphicResource();
		Discard_WriteResource();
		DeleteObject(hFont);

		return 0;


	case WM_COMMAND:

		switch (HIWORD(wParam))
		{
		case EN_CHANGE:
			ShowWindow(HWND(lParam), SW_HIDE);
			ShowWindow(HWND(lParam), SW_SHOW);
			SetFocus(HWND(lParam));
			break;
		}
		return 0;
	case WM_CTLCOLORBTN:
	case WM_CTLCOLOREDIT:
	case WM_CTLCOLORSTATIC:
		SetBkMode(HDC(wParam), TRANSPARENT);
		return LRESULT(HBRUSH(GetStockObject(NULL_BRUSH)));


	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
