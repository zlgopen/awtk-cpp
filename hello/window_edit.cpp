
/**
 * File:   window_edit.cpp
 * Author: AWTK Develop Team
 * Brief:  edit window
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

#include "window_edit.hpp"
#include "window_edit_ui.hpp"

void WindowEdit::OnOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowEdit::OnWillOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowEdit::OnClose() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowEdit::OnToBackGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowEdit::OnToForeGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

ret_t WindowEdit::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowEdit::OnHookEvents() {
/*
 * TODO: hook events at here
 */
  this->OnChild(EVT_CLICK, "close");

  return TAppWindow::OnHookEvents();
}

ret_t WindowEdit::OnInit(TRequestPtrRef request, bool first_time) {
/*
  TODO: initialize widget at here
  int value = request->GetInt("value", 10);
  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);
*/
  return RET_OK;
}

WINDOW_REGISTER("edit", WindowEdit, TRUE);
