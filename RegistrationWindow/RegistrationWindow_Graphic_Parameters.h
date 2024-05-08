#pragma once

#include<d2d1.h>

D2D1_COLOR_F color_wallpaper_1  = D2D1::ColorF((UINT32)RGB(92, 53, 50));
D2D1_COLOR_F color_wallpaper_2  = D2D1::ColorF((UINT32)RGB(66, 28, 0));
D2D1_COLOR_F color_enterField_1 = D2D1::ColorF((UINT32)RGB(190, 230, 4));
D2D1_COLOR_F color_enterField_2 = D2D1::ColorF((UINT32)RGB(238, 150, 4));
D2D1_COLOR_F color_LineBar_1    = D2D1::ColorF((UINT32)RGB(185, 238, 4));
D2D1_COLOR_F color_LineBar_2    = D2D1::ColorF((UINT32)RGB(72, 67, 59));

// WallPaper element - Cyrcles
D2D1_ELLIPSE wallpaper_circle_1 = D2D1::Ellipse(D2D1::Point2F(280, 0), 160, 160);
D2D1_ELLIPSE wallpaper_circle_2 = D2D1::Ellipse(D2D1::Point2F(500, 230), 95, 95);
D2D1_ELLIPSE wallpaper_circle_3 = D2D1::Ellipse(D2D1::Point2F(290, 240), 82, 82);
D2D1_ELLIPSE wallpaper_circle_4 = D2D1::Ellipse(D2D1::Point2F(150, 300), 42, 42);
D2D1_ELLIPSE wallpaper_circle_5 = D2D1::Ellipse(D2D1::Point2F(75, 240), 36, 36);
D2D1_ELLIPSE wallpaper_circle_6 = D2D1::Ellipse(D2D1::Point2F(50, 310), 20, 20);
D2D1_ELLIPSE wallpaper_circle_7 = D2D1::Ellipse(D2D1::Point2F(70, 80), 70, 70);

// LineBar element
D2D1_ELLIPSE LineBar_circle_1   = D2D1::Ellipse(D2D1::Point2F(190, 335), 15, 15);
D2D1_ELLIPSE LineBar_circle_2   = D2D1::Ellipse(D2D1::Point2F(310, 335), 15, 15);
D2D1_ELLIPSE LineBar_circle_3   = D2D1::Ellipse(D2D1::Point2F(430, 335), 15, 15);

// Colors for wallpaper's ellipses
D2D1_COLOR_F color_wallpaper_ellipse_1 = D2D1::ColorF((UINT32)RGB(70, 39, 38));
D2D1_COLOR_F color_wallpaper_ellipse_2 = D2D1::ColorF((UINT32)RGB(57, 31, 29));
D2D1_COLOR_F color_wallpaper_ellipse_3 = D2D1::ColorF((UINT32)RGB(62, 35, 33));
D2D1_COLOR_F color_wallpaper_ellipse_4 = D2D1::ColorF((UINT32)RGB(66, 37, 35));
D2D1_COLOR_F color_wallpaper_ellipse_5 = D2D1::ColorF((UINT32)RGB(73, 40, 38));
D2D1_COLOR_F color_wallpaper_ellipse_6 = D2D1::ColorF((UINT32)RGB(73, 41, 39));
D2D1_COLOR_F color_wallpaper_ellipse_7 = D2D1::ColorF((UINT32)RGB(78, 43, 41));

// Coordinats for text
D2D1_RECT_F Frame_1_rect_text_login = D2D1::RectF(286.5, 16, 350.5, 42);
D2D1_RECT_F Frame_1_rect_text_Password = D2D1::RectF(265.5, 115, 372.5, 143);
D2D1_RECT_F Frame_1_rect_text_RepeatPassword = D2D1::RectF(228.5, 214, 418.5, 242);
D2D1_RECT_F Frame_1_rect_text_Registration = D2D1::RectF(68, 263, 206, 274);
D2D1_RECT_F Frame_1_rect_text_Help = D2D1::RectF(451, 244, 300, 290);
D2D1_RECT_F Frame_2_rect_text_EmailAdress = D2D1::RectF(170, 65, 460, 90);
D2D1_RECT_F Frame_2_rect_text_ConfirmYourAddress = D2D1::RectF(180, 165, 430, 190);

// Coordinats for Round Rect
D2D1_RECT_F Frame_1_rect_EnterField_Login = D2D1::RectF(158.5, 50, 463.5, 95);
D2D1_RECT_F Frame_1_rect_EnterField_Password = D2D1::RectF(158.5, 152, 463.5, 197);
D2D1_RECT_F Frame_1_rect_EnterField_RepeatPassword = D2D1::RectF(158.5, 254, 463.5, 299);
D2D1_ROUNDED_RECT Frame_1_enterField_Login = D2D1::RoundedRect(Frame_1_rect_EnterField_Login, 30, 30);
D2D1_ROUNDED_RECT Frame_1_enterField_Password = D2D1::RoundedRect(Frame_1_rect_EnterField_Password, 30, 30);
D2D1_ROUNDED_RECT Frame_1_enterField_RepeatPassword = D2D1::RoundedRect(Frame_1_rect_EnterField_RepeatPassword, 30, 30);

D2D1_RECT_F Frame_2_rect_EnterField_Login = D2D1::RectF(158.5, 100, 463.5, 145);
D2D1_RECT_F Frame_2_rect_EnterField_Password = D2D1::RectF(158.5, 202, 463.5, 247);
D2D1_ROUNDED_RECT Frame_2_enterField_Login = D2D1::RoundedRect(Frame_2_rect_EnterField_Login, 30, 30);
D2D1_ROUNDED_RECT Frame_2_enterField_Password = D2D1::RoundedRect(Frame_2_rect_EnterField_Password, 30, 30);