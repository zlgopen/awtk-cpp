/**
 * File:   app_window.hpp
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

#ifndef TK_APP_WINDOW_H
#define TK_APP_WINDOW_H

#include "window_factory.hpp"

class TAppWindow {
 public:
  TAppWindow(TWidget win) : mWindow(win) {
  }

public:
  ret_t OnRequest(TRequestPtrRef request, bool first_time);

 public: /*virtual*/
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();

  virtual ret_t OnHookEvents();
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  virtual ret_t OnInit(TRequestPtrRef request, bool first_time);

 public: /*helper*/
  ret_t Back();
  ret_t Quit();
  ret_t BackToHome();

  static ret_t CloseForce(const char* name);
  static bool isWindowOpen(const char* name);

  ret_t Open(const char* name);
  ret_t Open(const char* name, bool close_current, TRequestPtr request);
  ret_t SwitchTo(const char* name, bool close_current, TRequestPtr request);

  TWidget Lookup(const char* name);
  uint32_t On(event_type_t etype);
  uint32_t OnChild(event_type_t etype, const char* name);

  static ret_t OpenFirst(const char* name, TRequestPtr request);

 public:
  virtual ~TAppWindow() {
    log_debug("~TAppWindow\n");
  }

  TWidget& GetWindow() const {
    return mWindow;
  }

 private:
  mutable TWidget mWindow;
  TRequestPtr mRequest;

 private:
  TAppWindow(const TAppWindow& other);
  TAppWindow& operator=(const TAppWindow& other);
};

#endif /*TK_APP_WINDOW_H*/
