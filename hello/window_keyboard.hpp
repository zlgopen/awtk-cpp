﻿
/**
 * File:   window_keyboard.hpp
 * Author: AWTK Develop Team
 * Brief:  keyboard window
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

#ifndef TK_WINDOW_KEYBOARD_H
#define TK_WINDOW_KEYBOARD_H

#include "app_window.hpp"
#include "window_keyboard_ui.hpp"

class WindowKeyboard : public TAppWindow {
 public:
  WindowKeyboard(TWidget win) : TAppWindow(win) {
    this->ui.Init(win);
  }

 public:
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();
  virtual ret_t OnHookEvents();
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  virtual ret_t OnInit(TRequestPtrRef request, bool first_time);
private:
  WindowKeyboardUI ui;
};

#endif /*TK_WINDOW_KEYBOARD_H*/
