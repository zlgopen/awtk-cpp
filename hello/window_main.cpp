/**
 * File:   window_main.cpp
 * Author: AWTK Develop Team
 * Brief:  main window
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

#include "window_main.hpp"
#include "window_button.hpp"
#include "window_basic.hpp"
#include "window_edit.hpp"

ret_t WindowMain::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);

    if (strstr(name, "button") != NULL) {
      WindowButton::Open(this, NULL);
    } else if (strstr(name, "basic") != NULL) {
      TRequestPtr req(new TRequest([](TAppWindow* target) -> void {
        TWidget bar1 = target->Lookup("bar1");
        log_debug("value=%d\n", bar1.GetValue());
      }));

      req->Set("value", 66);
      WindowBasic::Open(this, std::move(req));
    } else if (strstr(name, "edit") != NULL) {
      WindowEdit::Open(this, NULL);
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowMain::OnRequest(TRequestPtrRef request, bool first_time) {
  if (first_time) {
    this->OnChild(EVT_CLICK, "open:button");
    this->OnChild(EVT_CLICK, "open:basic");
    this->OnChild(EVT_CLICK, "open:edit");
    this->OnChild(EVT_CLICK, "open:gauge");
  }

  return TAppWindow::OnRequest(request, first_time);
}

ret_t WindowMain::Open(TAppWindow* caller, TRequestPtr request) {
  WindowMain* win = new WindowMain(TWindow::Open("main"));

  win->OnRequest(request, true);

  return RET_OK;
}
