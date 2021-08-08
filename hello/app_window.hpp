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

#include "request.hpp"

class TAppWindow {
 public:
  TAppWindow(TWidget win, TRequestPtrRef request) : mWindow(win), mRequest(request) {
    this->HookEvents();
  }

 public: /*virtual*/
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();

  virtual ret_t OnEvent(TWidget& target, TEvent& e);

 public: /*helper*/
  ret_t Back();
  ret_t BackToHome();

  static ret_t CloseForce(const char* name);
  static bool isWindowOpen(const char* name);
  static ret_t SwitchTo(const char* name, bool close_current);

  TWidget Lookup(const char* name);
  uint32_t On(event_type_t etype);
  uint32_t OnChild(event_type_t etype, const char* name);

 public:
  virtual ~TAppWindow() {
    log_debug("~TAppWindow\n");
  }

  TWidget GetWindow() const {
    return mWindow;
  }

 private:
  TWidget mWindow;
  TRequestPtr mRequest;

 private:
  void HookEvents();
  TAppWindow(const TAppWindow& other);
  TAppWindow& operator=(const TAppWindow& other);
};

#endif /*TK_APP_WINDOW_H*/
