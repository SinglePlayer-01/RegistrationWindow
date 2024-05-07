#pragma once

// Skeleton of the project
#include<windows.h>
// Graphics libraries
#include<d2d1.h>
#include<dwrite.h>
// Network library
//#include<WinSock2.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

#include"BaseWindow.h"

//#pragma comment(lib, "Ws2_32.lib")

class CustomButton : public BaseWindow<CustomButton>
{
	// Direct2D Graphic
	ID2D1Factory* m_pFactory_graphic;
	ID2D1DCRenderTarget* m_pRenderTarget;
	ID2D1GradientStopCollection* m_pStopcollection;
	ID2D1LinearGradientBrush* m_pGradBrush_wallpaper;
	ID2D1SolidColorBrush* m_pSolBrus;

	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), 0, 0, D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);

	HRESULT Create_Factory();
	HRESULT Create_GraphicResource();
	void	Draw_Button();
	void	Discard_GraphicResource();

public:
	PCWSTR	ClassName() const { return L"LoginWindow class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

class RegistrationWindow : public BaseWindow<RegistrationWindow>
{
	CustomButton button;

	HFONT hFont;

	RECT rc;

	// HWND for our interface's
	HWND edit_Login;
	HWND edit_Password;
	HWND edit_RepeatPassword;
	HWND Button_next;

	int Frame_count = NULL;

	// Direct2D Graphic
	ID2D1Factory* m_pFactory_graphic;
	ID2D1DCRenderTarget* m_pRenderTarget;
	ID2D1GradientStopCollection* m_pStopcollection;
	ID2D1LinearGradientBrush* m_pGradBrush_wallpaper;
	ID2D1LinearGradientBrush* m_pGradBrush_enterfield;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_1;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_2;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_3;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_4;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_5;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_6;
	ID2D1SolidColorBrush* m_pSolBrus_ellipse_7;
	ID2D1SolidColorBrush* m_pSolBrus_text;

	ID2D1SolidColorBrush* m_pSolBrush_LineBar_1;
	ID2D1SolidColorBrush* m_pSolBrush_LineBar_2;
	ID2D1SolidColorBrush* m_pSolBrush_LineBar_Number;

	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), 0, 0, D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);

	// DirectWrite text
	IDWriteFactory* m_pFactory_text;
	IDWriteTextFormat* m_pTextFormat_1;
	IDWriteTextFormat* m_pTextFormat_2;

	// Graphic our functions
	HRESULT Create_Factory();
	HRESULT Create_GraphicResource();
	void	Draw_First_Frame();
	void	Draw_Second_Frame();
	void	Discard_GraphicResource();
	void	Discard_WriteResource();

public:
	PCWSTR	ClassName() const { return L"LoginWindow class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};

