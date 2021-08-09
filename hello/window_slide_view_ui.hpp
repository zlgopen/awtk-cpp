
/**
 * File:   window_slide_view_ui.hpp
 * Author: AWTK Develop Team
 * Brief:  slide_view window ui
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
#ifndef TK_WINDOW_SLIDE_VIEW_UI_H
#define TK_WINDOW_SLIDE_VIEW_UI_H

#include "awtk_cpp.hpp"

class WindowSlideViewUI {
public:
  WindowSlideViewUI() {};
  ~WindowSlideViewUI() {} 
public:
  TWindow slide_view;
  TScrollView scroll_view;
  TButton open_slide_view_h;
  TButton open_slide_view_h1;
  TButton open_slide_view_h2;
  TButton open_slide_view_v;
  TButton open_slide_view_v1;
  TButton open_slide_view_v2;
  TButton open_slide_view_h_loop;
  TButton open_slide_view_v_loop;
  TButton open_auto_play___device_orientation__auto_play;
  TButton open_slide_view_remove;
  TButton open_slide_view_remove_loop;
  TButton close;

public:
 void Init(TWidget win, TAppWindow* app_win) {
    this->slide_view = TWindow::Cast(win.Lookup("slide_view", TRUE));
    this->scroll_view = TScrollView::Cast(win.Lookup("scroll_view", TRUE));
    this->open_slide_view_h = TButton::Cast(win.Lookup("open:slide_view_h", TRUE));
    this->open_slide_view_h1 = TButton::Cast(win.Lookup("open:slide_view_h1", TRUE));
    this->open_slide_view_h2 = TButton::Cast(win.Lookup("open:slide_view_h2", TRUE));
    this->open_slide_view_v = TButton::Cast(win.Lookup("open:slide_view_v", TRUE));
    this->open_slide_view_v1 = TButton::Cast(win.Lookup("open:slide_view_v1", TRUE));
    this->open_slide_view_v2 = TButton::Cast(win.Lookup("open:slide_view_v2", TRUE));
    this->open_slide_view_h_loop = TButton::Cast(win.Lookup("open:slide_view_h_loop", TRUE));
    this->open_slide_view_v_loop = TButton::Cast(win.Lookup("open:slide_view_v_loop", TRUE));
    this->open_auto_play___device_orientation__auto_play = TButton::Cast(win.Lookup("open:auto_play_${device_orientation},auto_play", TRUE));
    this->open_slide_view_remove = TButton::Cast(win.Lookup("open:slide_view_remove", TRUE));
    this->open_slide_view_remove_loop = TButton::Cast(win.Lookup("open:slide_view_remove_loop", TRUE));
    this->close = TButton::Cast(win.Lookup("close", TRUE));

    return;
 }
};
#endif /*TK_WINDOW_SLIDE_VIEW_UI_H*/
