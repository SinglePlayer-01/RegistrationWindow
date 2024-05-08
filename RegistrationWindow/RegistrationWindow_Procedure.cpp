#include<Windows.h>

#include"RegistrationWindow.h"

#include"CustomMessage.h"

LRESULT RegistrationWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		// 
	case WM_CREATE:
	{
		Create_Factory();
		GetClientRect(m_hwnd, &rc);
		Frame_count = 1;

			Frame_1_edit_Login = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 65, 220, 26, m_hwnd, NULL, NULL, NULL);
			Frame_1_edit_Password = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 165, 220, 26, m_hwnd, NULL, NULL, NULL);
			Frame_1_edit_RepeatPassword = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 265, 220, 26, m_hwnd, NULL, NULL, NULL);

			Frame_2_edit_EmailAddress = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 116, 220, 26, m_hwnd, NULL, NULL, NULL);
			Frame_2_edit_ConfiemAddress = CreateWindow(L"EDIT", NULL, WS_CHILD, 178.5, 215, 220, 26, m_hwnd, NULL, NULL, NULL);

			Frame_3_edit_Verification = CreateWindow(L"EDIT", NULL, WS_CHILD, 60, 266, 220, 26, m_hwnd, NULL, NULL, NULL);

			button.Create(NULL, WS_CHILD, NULL, 470, 254, 48, 48, m_hwnd, NULL);
			Button_next = button.Window();

			ShowWindow(Frame_1_edit_Login, SW_SHOW);
			ShowWindow(Frame_1_edit_Password, SW_SHOW);
			ShowWindow(Frame_1_edit_RepeatPassword, SW_SHOW);
			ShowWindow(Button_next, SW_SHOW);

		// Creating the font we need
		
		HFONT hFont = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");

		// Set your font
		SendMessage(Frame_1_edit_Login, WM_SETFONT, (WPARAM)hFont, TRUE);
		SendMessage(Frame_1_edit_Password, WM_SETFONT, (WPARAM)hFont, TRUE);
		SendMessage(Frame_1_edit_RepeatPassword, WM_SETFONT, (WPARAM)hFont, TRUE);
	}

	return 0;

	case WM_PAINT:

		switch (Frame_count)
		{
			case 1:
				Draw_First_Frame();
			return 0;

			case 2:
				DestroyWindow(Frame_1_edit_Login);
				DestroyWindow(Frame_1_edit_Password);
				DestroyWindow(Frame_1_edit_RepeatPassword);
				ShowWindow(Frame_2_edit_EmailAddress, SW_SHOW);
				ShowWindow(Frame_2_edit_ConfiemAddress, SW_SHOW);

				Draw_Second_Frame();
			return 0;
			
			case 3:
				ShowWindow(Frame_2_edit_EmailAddress, SW_HIDE);
				ShowWindow(Frame_2_edit_ConfiemAddress, SW_HIDE);
				DestroyWindow(Frame_2_edit_EmailAddress);
				DestroyWindow(Frame_2_edit_ConfiemAddress);
				ShowWindow(Frame_3_edit_Verification, SW_SHOW);

				Draw_Third_Frame();
			return 0;
		}
		

		return 0;

	// 
	case WM_DESTROY:
		Discard_GraphicResource();
		Discard_WriteResource();
		DeleteObject(hFont);

		return 0;

	case WM_MOUSEMOVE:
	{
		POINT p;
		HCURSOR cursor_1 = LoadCursor(NULL, IDC_ARROW);

		GetCursorPos(&p);
		if (WindowFromPoint(p) == m_hwnd)
		{
			SendMessage(Frame_2_edit_EmailAddress, WM_KILLFOCUS, (WPARAM)m_hwnd, NULL);
			SendMessage(Frame_2_edit_ConfiemAddress, WM_KILLFOCUS, (WPARAM)m_hwnd, NULL);
			SetCursor(cursor_1);
		}
	}
	return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			case Redraw_Frame_1_2:
			{
				RECT rc;
				Frame_count++;
				GetClientRect(m_hwnd, &rc);
				InvalidateRect(m_hwnd, NULL, FALSE);
				RedrawWindow(m_hwnd, &rc, NULL, RDW_UPDATENOW);
			}
			return 0;

			
		}
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
		SetTextColor(HDC(wParam),(COLORREF)RGB(255, 255, 255));
		SetBkMode(HDC(wParam), TRANSPARENT);
		return LRESULT(HBRUSH(GetStockObject(NULL_BRUSH)));


	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

LRESULT CustomButton::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
			Create_Factory();
		return 0;

		case WM_PAINT:
			Draw_Button();
		return 0;

		case WM_LBUTTONDOWN:
		{
			POINT p;

			GetCursorPos(&p);
			if (WindowFromPoint(p) == m_hwnd)
			{
				SendMessage(GetParent(m_hwnd), WM_COMMAND, Redraw_Frame_1_2, NULL);
			}
		}
		return 0;

		case WM_MOUSEMOVE:
		{
			POINT p;
			HCURSOR cursor_1 = LoadCursor(NULL, IDC_HAND);

			GetCursorPos(&p);
			if (WindowFromPoint(p) == m_hwnd)
			{
				SetCursor(cursor_1);
			}
		}
		return 0;

		case WM_DESTROY:
			Discard_GraphicResource();
		return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}