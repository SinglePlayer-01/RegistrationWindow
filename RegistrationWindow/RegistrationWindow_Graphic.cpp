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
    SafeRelease(&m_pTextFormat_3);
    SafeRelease(&m_pTextFormat_4);
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
            m_pFactory_text->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 18.0f, L"en-us", &m_pTextFormat_2);
            m_pFactory_text->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &m_pTextFormat_3);
            m_pFactory_text->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 18.0f, L"en-us", &m_pTextFormat_4);


            m_pTextFormat_1->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_1->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_2->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_2->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_3->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
            m_pTextFormat_3->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_4->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
            m_pTextFormat_4->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
    }
    return hr;
}

void RegistrationWindow::Draw_First_Frame()
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

        m_pRenderTarget->FillRoundedRectangle(Frame_1_enterField_Login, m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRoundedRectangle(Frame_1_enterField_Password, m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRoundedRectangle(Frame_1_enterField_RepeatPassword, m_pGradBrush_wallpaper);

        m_pRenderTarget->DrawRoundedRectangle(Frame_1_enterField_Login, m_pGradBrush_enterfield, 2.0f);
        m_pRenderTarget->DrawRoundedRectangle(Frame_1_enterField_Password, m_pGradBrush_enterfield,2.0f);
        m_pRenderTarget->DrawRoundedRectangle(Frame_1_enterField_RepeatPassword, m_pGradBrush_enterfield, 2.0f);

        m_pRenderTarget->DrawText(L"Login", ARRAYSIZE(L"Login"), m_pTextFormat_1, Frame_1_rect_text_login, m_pSolBrus_text);
        m_pRenderTarget->DrawText(L"Password", ARRAYSIZE(L"Password"), m_pTextFormat_1, Frame_1_rect_text_Password, m_pSolBrus_text);
        m_pRenderTarget->DrawText(L"Repeat Password", ARRAYSIZE(L"Repeat Password"), m_pTextFormat_1, Frame_1_rect_text_RepeatPassword, m_pSolBrus_text);

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

void RegistrationWindow::Draw_Second_Frame()
{

        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        m_pRenderTarget->BindDC(hdc, &rc);
        m_pRenderTarget->BeginDraw();
        
        // Draw WallPaper
        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, rc.right, rc.bottom), m_pGradBrush_wallpaper);
        m_pRenderTarget->FillEllipse(wallpaper_circle_1, m_pSolBrus_ellipse_1);
        m_pRenderTarget->FillEllipse(wallpaper_circle_2, m_pSolBrus_ellipse_2);
        m_pRenderTarget->FillEllipse(wallpaper_circle_3, m_pSolBrus_ellipse_3);
        m_pRenderTarget->FillEllipse(wallpaper_circle_4, m_pSolBrus_ellipse_4);
        m_pRenderTarget->FillEllipse(wallpaper_circle_5, m_pSolBrus_ellipse_5);
        m_pRenderTarget->FillEllipse(wallpaper_circle_6, m_pSolBrus_ellipse_6);
        m_pRenderTarget->FillEllipse(wallpaper_circle_7, m_pSolBrus_ellipse_7);
        
        // Draw enterfields
        m_pRenderTarget->FillRoundedRectangle(Frame_2_enterField_Login, m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRoundedRectangle(Frame_2_enterField_Password, m_pGradBrush_wallpaper);
        m_pRenderTarget->DrawRoundedRectangle(Frame_2_enterField_Login, m_pGradBrush_enterfield, 2.0f);
        m_pRenderTarget->DrawRoundedRectangle(Frame_2_enterField_Password, m_pGradBrush_enterfield, 2.0f);

        // Draw text under enterfieldes
        m_pRenderTarget->DrawText(L"Email adress", ARRAYSIZE(L"Email adress"), m_pTextFormat_1, Frame_2_rect_text_EmailAdress, m_pSolBrus_text);
        m_pRenderTarget->DrawText(L"Confirm your address", ARRAYSIZE(L"Confirm your address"), m_pTextFormat_1, Frame_2_rect_text_ConfirmYourAddress, m_pSolBrus_text);

        // Draw linier bar
        m_pRenderTarget->DrawLine(D2D1::Point2F(190, 335), D2D1::Point2F(430, 335), m_pSolBrush_LineBar_2, 5.0f);
        m_pRenderTarget->DrawLine(D2D1::Point2F(190, 335), D2D1::Point2F(310, 335), m_pSolBrush_LineBar_1, 5.0f);
        m_pRenderTarget->FillEllipse(LineBar_circle_1, m_pSolBrush_LineBar_1);
        m_pRenderTarget->FillEllipse(LineBar_circle_2, m_pSolBrush_LineBar_1);
        m_pRenderTarget->FillEllipse(LineBar_circle_3, m_pSolBrush_LineBar_2);
        m_pRenderTarget->DrawText(L"1", ARRAYSIZE(L"1"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_1.point.x - 15, LineBar_circle_1.point.y - 15, LineBar_circle_1.point.x + 15, LineBar_circle_1.point.y + 15), m_pSolBrush_LineBar_Number);
        m_pRenderTarget->DrawText(L"2", ARRAYSIZE(L"2"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_2.point.x - 15, LineBar_circle_2.point.y - 15, LineBar_circle_2.point.x + 15, LineBar_circle_2.point.y + 15), m_pSolBrush_LineBar_Number);
        m_pRenderTarget->DrawText(L"3", ARRAYSIZE(L"3"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_3.point.x - 15, LineBar_circle_3.point.y - 15, LineBar_circle_3.point.x + 15, LineBar_circle_3.point.y + 15), m_pSolBrush_LineBar_Number);

        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);

}

void RegistrationWindow::Draw_Third_Frame()
{
    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &rc);
    m_pRenderTarget->BeginDraw();

    // Draw WallPaper
    m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, rc.right, rc.bottom), m_pGradBrush_wallpaper);
    m_pRenderTarget->FillEllipse(wallpaper_circle_1, m_pSolBrus_ellipse_1);
    m_pRenderTarget->FillEllipse(wallpaper_circle_2, m_pSolBrus_ellipse_2);
    m_pRenderTarget->FillEllipse(wallpaper_circle_3, m_pSolBrus_ellipse_3);
    m_pRenderTarget->FillEllipse(wallpaper_circle_4, m_pSolBrus_ellipse_4);
    m_pRenderTarget->FillEllipse(wallpaper_circle_5, m_pSolBrus_ellipse_5);
    m_pRenderTarget->FillEllipse(wallpaper_circle_6, m_pSolBrus_ellipse_6);
    m_pRenderTarget->FillEllipse(wallpaper_circle_7, m_pSolBrus_ellipse_7);

    // Draw incstuction for users
    m_pRenderTarget->DrawText(L"A verification code has been sent to the email address you provided:", ARRAYSIZE(L"A verification code has been sent to the email address you provided:"), m_pTextFormat_3, Frame_3_rect_text_Instruction_1, m_pSolBrus_text);
    m_pRenderTarget->DrawText(L"EmailAddress@gmail.com", ARRAYSIZE(L"EmailAddress@gmail.com"), m_pTextFormat_3, Frame_3_rect_text_Instruction_2, m_pGradBrush_enterfield);
    m_pRenderTarget->DrawText(L"Please check your inbox and enter the code below to complete your registration", ARRAYSIZE(L"Please check your inbox and enter the code below to complete your registration"), m_pTextFormat_3, Frame_3_rect_text_Instruction_3, m_pSolBrus_text);

    // Draw text under verificate
    m_pRenderTarget->DrawText(L"Enter your verification code", ARRAYSIZE(L"Enter your verification code"), m_pTextFormat_4, Frame_3_rect_text_EnterVerificationCode, m_pSolBrus_text);

    // Draw enter field for Verificate code
    m_pRenderTarget->FillRoundedRectangle(Frame_3_enterField_VerifiCode, m_pGradBrush_wallpaper);
    m_pRenderTarget->DrawRoundedRectangle(Frame_3_enterField_VerifiCode, m_pGradBrush_enterfield, 2.0f);

    // Draw linier bar
    m_pRenderTarget->DrawLine(D2D1::Point2F(190, 335), D2D1::Point2F(430, 335), m_pSolBrush_LineBar_2, 5.0f);
    m_pRenderTarget->DrawLine(D2D1::Point2F(190, 335), D2D1::Point2F(430, 335), m_pSolBrush_LineBar_1, 5.0f);
    m_pRenderTarget->FillEllipse(LineBar_circle_1, m_pSolBrush_LineBar_1);
    m_pRenderTarget->FillEllipse(LineBar_circle_2, m_pSolBrush_LineBar_1);
    m_pRenderTarget->FillEllipse(LineBar_circle_3, m_pSolBrush_LineBar_1);
    m_pRenderTarget->DrawText(L"1", ARRAYSIZE(L"1"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_1.point.x - 15, LineBar_circle_1.point.y - 15, LineBar_circle_1.point.x + 15, LineBar_circle_1.point.y + 15), m_pSolBrush_LineBar_Number);
    m_pRenderTarget->DrawText(L"2", ARRAYSIZE(L"2"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_2.point.x - 15, LineBar_circle_2.point.y - 15, LineBar_circle_2.point.x + 15, LineBar_circle_2.point.y + 15), m_pSolBrush_LineBar_Number);
    m_pRenderTarget->DrawText(L"3", ARRAYSIZE(L"3"), m_pTextFormat_2, D2D1::RectF(LineBar_circle_3.point.x - 15, LineBar_circle_3.point.y - 15, LineBar_circle_3.point.x + 15, LineBar_circle_3.point.y + 15), m_pSolBrush_LineBar_Number);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}

//////////////////////////////////////////////////////////////////

void CustomButton::Discard_GraphicResource()
{
    SafeRelease(&m_pFactory_graphic);
    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pStopcollection);
    SafeRelease(&m_pGradBrush_wallpaper);
    SafeRelease(&m_pSolBrus);
}

HRESULT CustomButton::Create_Factory()
{
    HRESULT hr = S_OK;
    if (D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory_graphic) == S_FALSE)
    {
        return hr = S_FALSE;
    }
    return hr;
}

HRESULT CustomButton::Create_GraphicResource()
{
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect(m_hwnd, &rc);

    if (m_pRenderTarget == NULL)
    {
        hr = m_pFactory_graphic->CreateDCRenderTarget(&props, &m_pRenderTarget);
        RECT rc;
        GetClientRect(m_hwnd, &rc);
        // Create Linear gradient brush for WallPaper
        if (hr == S_OK)
        {
            D2D1_GRADIENT_STOP stop[2];
            stop[0].color = color_enterField_1;
            stop[0].position = 0.0f;
            stop[1].color = color_enterField_2;
            stop[1].position = 1.0f;

            m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pStopcollection);

            hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(rc.right, rc.bottom)), m_pStopcollection, &m_pGradBrush_wallpaper);
        }
        // Create SolidColor brushes for wallpaper
        if (hr == S_OK)
        {
            m_pRenderTarget->CreateSolidColorBrush(color_wallpaper_ellipse_1, &m_pSolBrus);
        }
    }
    return hr;
}

void CustomButton::Draw_Button()
{
    HRESULT hr = Create_GraphicResource();
    if (hr == S_OK)
    {
        RECT rc;
        GetClientRect(m_hwnd, &rc);

        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        m_pRenderTarget->BindDC(hdc, &rc);
        m_pRenderTarget->BeginDraw();
        
        m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(rc.right / 2, rc.bottom / 2), rc.right / 2 - 2, rc.bottom / 2 - 2), m_pGradBrush_wallpaper,4);
        m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rc.right / 2, rc.bottom / 2), rc.right / 2 - 2 , rc.bottom / 2 - 2), m_pSolBrus);
        m_pRenderTarget->DrawLine(D2D1::Point2F(10, 24), D2D1::Point2F(40, 24), m_pGradBrush_wallpaper, 3);
        m_pRenderTarget->DrawLine(D2D1::Point2F(40, 24), D2D1::Point2F(25, 32), m_pGradBrush_wallpaper, 3);
        m_pRenderTarget->DrawLine(D2D1::Point2F(40, 24), D2D1::Point2F(25, 16), m_pGradBrush_wallpaper, 3);

        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);

    }
}