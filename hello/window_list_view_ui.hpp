
/**
 * File:   window_list_view_ui.hpp
 * Author: AWTK Develop Team
 * Brief:  list_view window ui
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
#ifndef TK_WINDOW_LIST_VIEW_UI_H
#define TK_WINDOW_LIST_VIEW_UI_H

#include "awtk_cpp.hpp"

class WindowListViewUI {
public:
  WindowListViewUI() {};
  ~WindowListViewUI() {} 
public:
  TButton open_list_view_d;
  TButton open_list_view_d_f;
  TButton open_list_view_m;
  TButton open_list_view_vh;
  TButton open_list_view_h;
  TButton open_list_view_h1;
  TButton open_list_view_auto_resize;
  TButton open_image_list;
  TButton open_select1;
  TButton open_selectm;
  TButton close;

public:
 void Init(TWidget win, TAppWindow* app_win) {
    this->open_list_view_d = TButton::Cast(win.Lookup("open:list_view_d", TRUE));
    this->open_list_view_d_f = TButton::Cast(win.Lookup("open:list_view_d_f", TRUE));
    this->open_list_view_m = TButton::Cast(win.Lookup("open:list_view_m", TRUE));
    this->open_list_view_vh = TButton::Cast(win.Lookup("open:list_view_vh", TRUE));
    this->open_list_view_h = TButton::Cast(win.Lookup("open:list_view_h", TRUE));
    this->open_list_view_h1 = TButton::Cast(win.Lookup("open:list_view_h1", TRUE));
    this->open_list_view_auto_resize = TButton::Cast(win.Lookup("open:list_view_auto_resize", TRUE));
    this->open_image_list = TButton::Cast(win.Lookup("open:image_list", TRUE));
    this->open_select1 = TButton::Cast(win.Lookup("open:select1", TRUE));
    this->open_selectm = TButton::Cast(win.Lookup("open:selectm", TRUE));
    this->close = TButton::Cast(win.Lookup("close", TRUE));

    return;
 }
};
#endif /*TK_WINDOW_LIST_VIEW_UI_H*/
