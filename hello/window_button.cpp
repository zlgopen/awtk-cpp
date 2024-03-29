﻿
/**
 * File:   window_button.cpp
 * Author: AWTK Develop Team
 * Brief:  button window
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

#include "window_button.hpp"
#include "window_button_ui.hpp"

void WindowButton::OnOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowButton::OnWillOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowButton::OnClose() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowButton::OnToBackGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowButton::OnToForeGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

ret_t WindowButton::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK || e.GetType() == EVT_LONG_PRESS) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    } else if (strstr(name, "fullscreen") != NULL) {
      TWindow win = TWindow::Cast(this->GetWindow());
      win.SetFullscreen(!win.GetFullscreen());
    } else if (strstr(name, "open:dialog1") != NULL) {
      this->Open("dialog1", true, NULL);
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowButton::OnHookEvents() {
  this->OnChild(EVT_LONG_PRESS, "open:dialog1");
  this->OnChild(EVT_CLICK, "fullscreen");
  this->OnChild(EVT_CLICK, "close");

  return TAppWindow::OnHookEvents();
}

ret_t WindowButton::OnInit(TRequestPtrRef request, bool first_time) {
/*
  TODO: initialize widget at here
  int value = request->GetInt("value", 10);
  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);
*/
  return RET_OK;
}

WINDOW_REGISTER("button", WindowButton, TRUE);
