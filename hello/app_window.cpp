/**
 * File:   app_window.cpp
 * Author: AWTK Develop Team
 * Brief:  base class of app window
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

#include "app_window.hpp"

void TAppWindow::OnOpen() {
  log_debug("%s: %s\n", __FUNCTION__, mWindow.GetName());
}

void TAppWindow::OnWillOpen() {
  log_debug("%s: %s\n", __FUNCTION__, mWindow.GetName());
}

void TAppWindow::OnClose() {
  log_debug("%s: %s\n", __FUNCTION__, mWindow.GetName());
}

void TAppWindow::OnToBackGround() {
  log_debug("%s: %s\n", __FUNCTION__, mWindow.GetName());
}

void TAppWindow::OnToForeGround() {
  log_debug("%s: %s\n", __FUNCTION__, mWindow.GetName());
}
  
ret_t TAppWindow::SwitchTo(const char* name, bool close_current) {
  if(TAppWindow::isWindowOpen(name)) {
    widget_t* target = widget_child(window_manager(), name);
    widget_t* curr = window_manager_get_top_window(window_manager());
     
    return window_manager_switch_to(window_manager(), curr, target, close_current); 
  }

  return RET_FAIL;
}

bool TAppWindow::isWindowOpen(const char* name) {
  return widget_child(window_manager(), name) != NULL;
}

ret_t TAppWindow::OnEvent(TWidget& target, TEvent& e) {
  switch (e.GetType()) {
    case EVT_WINDOW_WILL_OPEN: {
      this->OnOpen();
      break;
    }
    case EVT_WINDOW_OPEN: {
      this->OnWillOpen();
      break;
    }
    case EVT_WINDOW_CLOSE: {
      if (mRequest != NULL) {
        mRequest->OnTargetClose(this);
      }
      this->OnClose();
      delete this;

      break;
    }
    case EVT_WINDOW_TO_BACKGROUND: {
      this->OnToBackGround();
      break;
    }
    case EVT_WINDOW_TO_FOREGROUND: {
      this->OnToForeGround();
      break;
    }
    default:
      break;
  }

  return RET_OK;
}

ret_t TAppWindow::Back() {
  return mWindow.Back();
}

ret_t TAppWindow::BackToHome() {
  return mWindow.BackToHome();
}

uint32_t TAppWindow::On(event_type_t etype) {
  TWidget target = mWindow;

  return target.On(
      etype,
      [](void* ctx, event_t* e) -> ret_t {
        TEvent evt = TEvent(e);
        TWidget target = TWidget(WIDGET(e->target));
        return static_cast<TAppWindow*>(ctx)->OnEvent(target, evt);
      },
      this);
}

TWidget TAppWindow::Lookup(const char* name) {
  return mWindow.Lookup(name, TRUE);
}

uint32_t TAppWindow::OnChild(event_type_t etype, const char* name) {
  TWidget target = this->Lookup(name);

  return target.On(
      etype,
      [](void* ctx, event_t* e) -> ret_t {
        TEvent evt = TEvent(e);
        TWidget target = TWidget(WIDGET(e->target));
        return static_cast<TAppWindow*>(ctx)->OnEvent(target, evt);
      },
      this);
}

void TAppWindow::HookEvents() {
  this->On(EVT_WINDOW_OPEN);
  this->On(EVT_WINDOW_WILL_OPEN);
  this->On(EVT_WINDOW_CLOSE);
  this->On(EVT_WINDOW_TO_BACKGROUND);
  this->On(EVT_WINDOW_TO_FOREGROUND);

  return;
}
