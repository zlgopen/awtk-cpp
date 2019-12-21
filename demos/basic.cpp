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

#include <string>
#include "awtk_cpp.hpp"
#include "application.hpp"

using std::string;

static ret_t OpenWindow(const char* name);

static ret_t OnClick(void* ctx, event_t* e) {
  TWidget w = TWidget(WIDGET(e->target));
  TWindow win = TWindow::cast(w.GetWindow());

  string name = w.GetName();
  if(name == "close") {
    win.Close();
  } else if(name == "exit") {
    TGlobal::Quit();
  } else if(name.find("open:") == 0) {
    OpenWindow(name.substr(5).c_str());
  }

  return RET_OK;
}

static ret_t OnWidget(void* ctx, const void* data) {
  TWidget w = TWidget(WIDGET(data));

  if(w.GetName() != NULL) {
    w.On(EVT_CLICK, OnClick, NULL);
  }

  return RET_OK;
}

static ret_t OpenWindow(const char* name) {
  
  TWindow::Open(name).Foreach(OnWidget, NULL);

  return RET_OK;
}

bool Application::Init(void) {
  OpenWindow("main");
  return true;
}

bool Application::Exit(void) {
  log_debug("application_exit\n");

  return true;
}

#include "demo_main.cpp"
