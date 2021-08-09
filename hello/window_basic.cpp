/**
 * File:   window_basic.cpp
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

#include "window_basic.hpp"

ret_t WindowBasic::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);

    if (strstr(name, "inc_value") != NULL) {
      this->Lookup("bar1").AddValue(10);
      this->Lookup("bar2").AddValue(10);
    } else if (strstr(name, "dec_value") != NULL) {
      this->Lookup("bar1").AddValue(-10);
      this->Lookup("bar2").AddValue(010);
    } else if (strstr(name, "switch_to:main") != NULL) {
      this->SwitchTo("main", false, NULL);
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowBasic::OnRequest(TRequestPtrRef request, bool first_time) {
  int value = request->GetInt("value", 10);

  if (first_time) {
    this->OnChild(EVT_CLICK, "inc_value");
    this->OnChild(EVT_CLICK, "dec_value");
    this->OnChild(EVT_CLICK, "switch_to:main");
  }

  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);

  return TAppWindow::OnRequest(request, first_time);
}

WINDOW_REGISTER("basic", WindowBasic, TRUE);

