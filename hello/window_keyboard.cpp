﻿
/**
 * File:   window_keyboard.cpp
 * Author: AWTK Develop Team
 * Brief:  keyboard window
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

#include "window_keyboard.hpp"
#include "window_keyboard_ui.hpp"

void WindowKeyboard::OnOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowKeyboard::OnWillOpen() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowKeyboard::OnClose() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowKeyboard::OnToBackGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

void WindowKeyboard::OnToForeGround() {
  log_debug("%s: %s\n", __FUNCTION__, this->GetWindow().GetName());
}

ret_t WindowKeyboard::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowKeyboard::OnHookEvents() {
/*
 * TODO: hook events at here
 */
  this->OnChild(EVT_CLICK, "close");

  return TAppWindow::OnHookEvents();
}

ret_t WindowKeyboard::OnInit(TRequestPtrRef request, bool first_time) {
/*
  TODO: initialize widget at here
  int value = request->GetInt("value", 10);
  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);
*/
  return RET_OK;
}

WINDOW_REGISTER("keyboard", WindowKeyboard, TRUE);
