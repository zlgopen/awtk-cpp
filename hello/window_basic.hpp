/**
 * File:   window_basic.hpp
 * Author: AWTK Develop Team
 * Brief:  basic window
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

#ifndef TK_WINDOW_BASIC_H
#define TK_WINDOW_BASIC_H

#include "awtk_cpp.hpp"
#include "app_window.hpp"

class WindowBasic : public TAppWindow {
 public:
  WindowBasic(TWidget win) : TAppWindow(win) {
  }

 public:
  virtual ret_t OnHookEvents();
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  virtual ret_t OnInit(TRequestPtrRef request, bool first_time);
};

#endif /*TK_WINDOW_BASIC_H*/
