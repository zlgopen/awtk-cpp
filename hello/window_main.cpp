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
      TAppWindow::Open("button");
    } else if (strstr(name, "basic") != NULL) {
      TRequestPtr req(new TRequest([](TAppWindow* target) -> void {
        TWidget bar1 = target->Lookup("bar1");
        log_debug("value=%d\n", bar1.GetValue());
      }));

      req->Set("value", 66);
      TAppWindow::Open("basic", false, std::move(req));
    } else if (strstr(name, "edit") != NULL) {
      TAppWindow::Open("edit");
    } else if (strstr(name, "keyboard") != NULL) {
      TAppWindow::Open("keyboard");
    } else if (strstr(name, "gauge") != NULL) {
      TAppWindow::Open("gauge");
    } else if (strstr(name, "list_view") != NULL) {
      TAppWindow::Open("list_view");
    } else if (strstr(name, "slide_view") != NULL) {
      TAppWindow::Open("slide_view");
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowMain::OnHookEvents() {
  this->OnChild(EVT_CLICK, "open:button");
  this->OnChild(EVT_CLICK, "open:basic");
  this->OnChild(EVT_CLICK, "open:edit");
  this->OnChild(EVT_CLICK, "open:gauge");
  this->OnChild(EVT_CLICK, "open:keyboard");
  this->OnChild(EVT_CLICK, "open:list_view");
  this->OnChild(EVT_CLICK, "open:slide_view");

  return TAppWindow::OnHookEvents();
}

ret_t WindowMain::OnInit(TRequestPtrRef request, bool first_time) {
  return RET_OK;
}

WINDOW_REGISTER("main", WindowMain, TRUE);
