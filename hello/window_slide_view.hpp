﻿
/**
 * File:   window_slide_view.hpp
 * Author: AWTK Develop Team
 * Brief:  slide_view window
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

#ifndef TK_WINDOW_SLIDE_VIEW_H
#define TK_WINDOW_SLIDE_VIEW_H

#include "app_window.hpp"
#include "window_slide_view_ui.hpp"

class WindowSlideView : public TAppWindow {
 public:
  WindowSlideView(TWidget win) : TAppWindow(win) {
    this->ui.Init(win, this);
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
  WindowSlideViewUI ui;
};

#endif /*TK_WINDOW_SLIDE_VIEW_H*/
