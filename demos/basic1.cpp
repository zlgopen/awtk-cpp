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

class WindowBasic {
 public:
  WindowBasic(TWidget win) : win(win) {
    this->win = win;
  }

  ~WindowBasic() {
  }

  static bool Open(void) {
    TWidget win = TWindow::Open("basic");
    TWidget inc = win.Lookup("inc", TRUE);
    TWidget dec = win.Lookup("dec", TRUE);
    TWidget quit = win.Lookup("quit", TRUE);
    WindowBasic* basic = new WindowBasic(win);

    inc.On(
        EVT_CLICK,
        [](void* ctx, event_t* e) -> ret_t { return static_cast<WindowBasic*>(ctx)->Inc(); },
        basic);

    dec.On(
        EVT_CLICK,
        [](void* ctx, event_t* e) -> ret_t { return static_cast<WindowBasic*>(ctx)->Dec(); },
        basic);

    quit.On(
        EVT_CLICK,
        [](void* ctx, event_t* e) -> ret_t { return static_cast<WindowBasic*>(ctx)->Quit(); },
        basic);

    win.On(
        EVT_WINDOW_OPEN,
        [](void* ctx, event_t* e) -> ret_t {
          static_cast<WindowBasic*>(ctx)->OnOpen();
          return RET_OK;
        },
        basic);

    win.On(
        EVT_WINDOW_CLOSE,
        [](void* ctx, event_t* e) -> ret_t {
          static_cast<WindowBasic*>(ctx)->OnClose();
          delete static_cast<WindowBasic*>(ctx);
          return RET_OK;
        },
        basic);

    return true;
  }

  ret_t OnOpen(void) {
    log_debug("OnOpen\n");
    return RET_OK;
  }

  ret_t OnClose(void) {
    log_debug("OnClose\n");
    return RET_OK;
  }

  ret_t Quit(void) {
    return TGlobal::Quit();
  }

  ret_t Inc(void) {
    TWidget win = this->win;
    TWidget bar1 = win.Lookup("bar1", TRUE);
    TWidget bar2 = win.Lookup("bar2", TRUE);

    bar1.AddValue(10);
    bar2.AddValue(10);

    return RET_OK;
  }

  ret_t Dec(void) {
    TWidget win = this->win;
    TWidget bar1 = win.Lookup("bar1", TRUE);
    TWidget bar2 = win.Lookup("bar2", TRUE);

    bar1.AddValue(-10);
    bar2.AddValue(-10);

    return RET_OK;
  }

 private:
  TWidget win;
};

bool Application::Init(void) {
  return WindowBasic::Open();
}

bool Application::Exit(void) {
  log_debug("application_exit\n");

  return true;
}

#include "demo_main.cpp"
