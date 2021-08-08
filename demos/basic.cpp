/**
 * File:   basic.cpp
 * Author: AWTK Develop Team
 * Brief:  basic demo
 *
 * Copyright (c) 2021 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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

#include "awtk_cpp.hpp"
#include "application.hpp"

static ret_t OnQuit(void* ctx, event_t* e) {
  TPointerEvent evt = TPointerEvent::Cast(e);

  printf("click: %d %d\n", evt.GetX(), evt.GetY());
  TGlobal::Quit();

  return RET_OK;
}

static ret_t OnInc(void* ctx, event_t* e) {
  TWidget button = TWidget(WIDGET(e->target));
  TWindow win = TWindow::Cast(button.GetWindow());

  TWidget bar1 = win.Lookup("bar1", TRUE);
  TWidget bar2 = win.Lookup("bar2", TRUE);

  bar1.AddValue(10);
  bar2.AddValue(10);

  return RET_OK;
}

static ret_t OnDec(void* ctx, event_t* e) {
  TWidget button = TWidget(WIDGET(e->target));
  TWindow win = TWindow::Cast(button.GetWindow());

  TWidget bar1 = win.Lookup("bar1", TRUE);
  TWidget bar2 = win.Lookup("bar2", TRUE);

  bar1.AddValue(-10);
  bar2.AddValue(-10);

  return RET_OK;
}

bool Application::Init(void) {
  TWidget win = TWindow::Open("basic");
  TWidget inc = win.Lookup("inc", TRUE);
  TWidget dec = win.Lookup("dec", TRUE);
  TWidget quit = win.Lookup("quit", TRUE);

  inc.On(EVT_CLICK, OnInc, NULL);
  dec.On(EVT_CLICK, OnDec, NULL);
  quit.On(EVT_CLICK, OnQuit, NULL);

  return true;
}

bool Application::Exit(void) {
  log_debug("application_exit\n");

  return true;
}

#include "demo_main.cpp"
