
/**
 * File:   window_button_ui.hpp
 * Author: AWTK Develop Team
 * Brief:  button window ui
 *
 * Copyright (c) 2018 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2021-08-08 Li XianJing <xianjimli@hotmail.com> created
 *
 */
#ifndef TK_WINDOW_BUTTON_UI_H
#define TK_WINDOW_BUTTON_UI_H

#include "awtk_cpp.hpp"

class WindowButtonUI {
public:
  WindowButtonUI() {};
  ~WindowButtonUI() {} 
public:
  TButton open_dialog1;
  TButton unload_image;
  TButton fullscreen;
  TButton close;

public:
 void Init(TWidget win, TAppWindow* app_win) {
    this->open_dialog1 = TButton::Cast(win.Lookup("open:dialog1", TRUE));
    this->unload_image = TButton::Cast(win.Lookup("unload_image", TRUE));
    this->fullscreen = TButton::Cast(win.Lookup("fullscreen", TRUE));
    this->close = TButton::Cast(win.Lookup("close", TRUE));

    return;
 }
};
#endif /*TK_WINDOW_BUTTON_UI_H*/
