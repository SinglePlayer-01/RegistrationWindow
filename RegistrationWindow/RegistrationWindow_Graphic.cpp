#include<Windows.h>

#include<d2d1.h>
#include<dwrite.h>

#include"RegistrationWindow.h"
#include"RegistrationWindow_Graphic_Parameters.h"

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void RegistrationWindow::Discard_GraphicResource()
{
    SafeRelease(&m_pFactory_graphic);
    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pStopcollection);
    SafeRelease(&m_pGradBrush_wallpaper);
    SafeRelease(&m_pGradBrush_enterfield);
    SafeRelease(&m_pSolBrus_text);

    SafeRelease(&m_pSolBrus_ellipse_1);
    SafeRelease(&m_pSolBrus_ellipse_2);
    SafeRelease(&m_pSolBrus_ellipse_3);
    SafeRelease(&m_pSolBrus_ellipse_4);
    SafeRelease(&m_pSolBrus_ellipse_5);
    SafeRelease(&m_pSolBrus_ellipse_6);
    SafeRelease(&m_pSolBrus_ellipse_7);

    SafeRelease(&m_pSolBrush_LineBar_1);
    SafeRelease(&m_pSolBrush_LineBar_2);
    SafeRelease(&m_pSolBrush_LineBar_Number);
}

void RegistrationWindow::Discard_WriteResource()
{
    SafeRelease(&m_pFactory_text);
    SafeRelease(&m_pTextFormat_1);
    SafeRelease(&m_pTextFormat_2);
}

HRESULT RegistrationWindow::Create_Factory()
{
    HRESULT hr = S_OK;
    if (D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory_graphic) == S_FALSE)
    {
        return hr = S_FALSE;
    }
    if (DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_pFactory_text)) == S_FALSE)
    {
        return hr = S_FALSE;
    }
    return hr;
}

HRESULT RegistrationWindow::Create_GraphicResource()
{
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect(m_hwnd, &rc);

    if (m_pRenderTarget == NULL)
    {
        hr = m_pFactory_graphic->CreateDCRenderTarget(&props, &m_pRenderTarget);

        // Create Linear gradient brush for WallPaper
        if (hr == S_OK)
        {
            D2D1_GRADIENT_STOP stop[2];
            stop[0].color = color_wallpaper_1;
            stop[0].position = 0.0f;
            stop[1].color = color_wallpaper_2;
            stop[1].position = 1.0f;

            m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pStopcollection);

            hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(rc.right, rc.bottom)), m_pStopcollection, &m_pGradBrush_wallpaper);
        }
        // Create Linear gradient brush for EnterFields
        if (hr == S_OK)
        {
            D2D1_GRADIENT_STOP stop[2];
            stop[0].color = color_enterField_1;
            stop[0].position = 0.0f;
            stop[1].color = color_enterField_2;
            stop[1].position = 1.0f;

            m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pStopcollection);

            hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(110, 0), D2D1::Point2F(376, 0)), m_pStopcollection, &m_pGradBrush_enterfield);
        }
        // Create SolidColor brushes for wallpaper
        if (hr == S_OK)
        {
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_1, &m_pSolBrus_ellipse_1);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_2, &m_pSolBrus_ellipse_2);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_3, &m_pSolBrus_ellipse_3);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_4, &m_pSolBrus_ellipse_4);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_5, &m_pSolBrus_ellipse_5);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_6, &m_pSolBrus_ellipse_6);
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_7, &m_pSolBrus_ellipse_7);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_pSolBrus_text);

            m_pRenderTarget->CreateSolidColorBrush(color_LineBar_1, &m_pSolBrush_LineBar_1);
            m_pRenderTarget->CreateSolidColorBrush(color_LineBar_2, &m_pSolBrush_LineBar_2);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_pSolBrush_LineBar_Number);
        }
        // Create DWriteFactory and resources
        if (hr == S_OK)
        {
            m_pFactory_text->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 24.0f, L"en-us", &m_pTextFormat_1);
            m_pFactory_text->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &m_pTextFormat_2);

            m_pTextFormat_1->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_1->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_2->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_2->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
    }
    return hr;
}

void RegistrationWindow::Draw_WallPaper()
{
    HRESULT hr = Create_GraphicResource();
    if (hr == S_OK)
    {
        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        m_pRenderTarget->BindDC(hdc, &rc);
        m_pRenderTarget->BeginDraw();
        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, rc.right, rc.bottom), m_pGradBrush_wallpaper);
        m_pRenderTarget->FillEllipse(wallpaper_circle_1, m_pSolBrus_ellipse_1);
        m_pRenderTarget->FillEllipse(wallpaper_circle_2, m_pSolBrus_ellipse_2);
        m_pRenderTarget->FillEllipse(wallpaper_circle_3, m_pSolBrus_ellipse_3);
        m_pRenderTarget->FillEllipse(wallpaper_circle_4, m_pSolBrus_ellipse_4);
        m_pRenderTarget->FillEllipse(wallpaper_circle_5, m_pSolBrus_ellipse_5);
        m_pRenderTarget->FillEllipse(wallpaper_circle_6, m_pSolBrus_ellipse_6);
        m_pRenderTarget->FillEllipse(wallpaper_circle_7, m_pSolBrus_ellipse_7);

        m_pRenderTarget->FillRoundedRectangle(enterField_Login, m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRoundedRectangle(enterField_Password, m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRoundedRectangle(enterField_RepeatPassword, m_pGradBrush_wallpaper);

        m_pRenderTarget->DrawRoundedRectangle(enterField_Login, m_pGradBrush_enterfield);
        m_pRenderTarget->DrawRoundedRectangle(enterField_Password, m_pGradBrush_enterfield);
        m_pRenderTarget->DrawRoundedRectangle(enterField_RepeatPassword, m_pGradBrush_enterfield);

        m_pRenderTarget->DrawText(L"Login", ARRAYSIZE(L"Login"), m_pTextFormat_1, rect_text_login, m_pSolBrus_text);
        m_pRenderTarget->DrawText(L"Password", ARRAYSIZE(L"Password"), m_pTextFormat_1, rect_text_Password, m_pSolBrus_text);
        m_pRenderTarget->DrawText(L"Repeat Password", ARRAYSIZE(L"Repeat Password"), m_pTextFormat_1, rect_text_RepeatPassword, m_pSolBrus_text);

        m_pRenderTarget->DrawLine(D2D1::Point2F(190, 335), D2D1::Point2F(430, 335), m_pSolBrush_LineBar_2, 5.0f);
        m_pRenderTarget->FillEllipse(LineBar_circle_1, m_pSolBrush_LineBar_1);
        m_pRenderTarget->FillEllipse(LineBar_circle_2, m_pSolBrush_LineBar_2);
        m_pRenderTarget->FillEllipse(LineBar_circle_3, m_pSolBrush_LineBar_2);
        m_pRenderTarget->DrawText(L"1", ARRAYSIZE(L"1"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_1.point.x - 15, LineBar_circle_1.point.y - 15, LineBar_circle_1.point.x + 15, LineBar_circle_1.point.y + 15), m_pSolBrush_LineBar_Number);
        m_pRenderTarget->DrawText(L"2", ARRAYSIZE(L"2"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_2.point.x - 15, LineBar_circle_2.point.y - 15, LineBar_circle_2.point.x + 15, LineBar_circle_2.point.y + 15), m_pSolBrush_LineBar_Number);
        m_pRenderTarget->DrawText(L"3", ARRAYSIZE(L"3"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_3.point.x - 15, LineBar_circle_3.point.y - 15, LineBar_circle_3.point.x + 15, LineBar_circle_3.point.y + 15), m_pSolBrush_LineBar_Number);

        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);

    }
}
