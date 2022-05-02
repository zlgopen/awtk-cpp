/**
 * File:   button.cpp
 * Author: AWTK Develop Team
 * Brief:  button demo
 *
 * Copyright (c) 2018 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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
 * 2019-12-21 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk_cpp.hpp"
#include "application.hpp"

static ret_t ClickToQuit(void* ctx, event_t* e) {
  TGlobal::Quit();

  return RET_OK;
}

bool Application::Init(void) {
  TWidget win = TWindow::CreateDefault();
  TWidget ok = TButton::Create(win, 0, 0, 0, 0);

  ok.SetTextW(L"quit");
  ok.SetSelfLayoutParams("center", "middle", "50%", "30");

  ok.On(EVT_CLICK, ClickToQuit, NULL);

  return true;
}

bool Application::Exit(void) {
  log_debug("application_exit\n");

  return true;
}

#include "demo_main.cpp"
