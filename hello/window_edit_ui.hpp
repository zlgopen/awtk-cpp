
/**
 * File:   window_edit_ui.hpp
 * Author: AWTK Develop Team
 * Brief:  edit window ui
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
#ifndef TK_WINDOW_EDIT_UI_H
#define TK_WINDOW_EDIT_UI_H

#include "awtk_cpp.hpp"

class WindowEditUI {
public:
  WindowEditUI() {};
  ~WindowEditUI() {} 
public:
  TScrollView view;
  TScrollBar bar;
  TButton close;

public:
 void Init(TWidget win, TAppWindow* app_win) {
    this->view = TScrollView::Cast(win.Lookup("view", TRUE));
    this->bar = TScrollBar::Cast(win.Lookup("bar", TRUE));
    this->close = TButton::Cast(win.Lookup("close", TRUE));

    return;
 }
};
#endif /*TK_WINDOW_EDIT_UI_H*/
