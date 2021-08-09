/**
 * File:   window_dialog1.cpp
 * Author: AWTK Develop Team
 * Brief:  dialog1 window
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

#include "window_dialog1.hpp"

ret_t WindowDialog1::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);

    if (strstr(name, "quit") != NULL) {
      this->Quit();
    } else if (strstr(name, "back_to_home") != NULL) {
      this->BackToHome();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowDialog1::OnHookEvents() {
  this->OnChild(EVT_CLICK, "quit");
  this->OnChild(EVT_CLICK, "back_to_home");

  return TAppWindow::OnHookEvents();
}

ret_t WindowDialog1::OnInit(TRequestPtrRef request, bool first_time) {
  return RET_OK;
}

WINDOW_REGISTER("dialog1", WindowDialog1, TRUE);
