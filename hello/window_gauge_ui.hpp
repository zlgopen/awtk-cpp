
/**
 * File:   window_gauge_ui.hpp
 * Author: AWTK Develop Team
 * Brief:  gauge window ui
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
#ifndef TK_WINDOW_GAUGE_UI_H
#define TK_WINDOW_GAUGE_UI_H

#include "awtk_cpp.hpp"

class WindowGaugeUI {
public:
  WindowGaugeUI() {};
  ~WindowGaugeUI() {} 
public:
  TButton start;
  TButton pause;
  TButton stop;
  TButton close;

public:
 void Init(TWidget win) {
    this->start = TButton::Cast(win.Lookup("start", TRUE));
    this->pause = TButton::Cast(win.Lookup("pause", TRUE));
    this->stop = TButton::Cast(win.Lookup("stop", TRUE));
    this->close = TButton::Cast(win.Lookup("close", TRUE));

    return;
 }
};
#endif /*TK_WINDOW_GAUGE_UI_H*/
