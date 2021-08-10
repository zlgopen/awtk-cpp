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

 public: /*virtual*/
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();

  //子类重载本函数注册控件的事件。
  virtual ret_t OnHookEvents();
  //子类重载本函数处理控件的事件。
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  //子类重载本函数初始化控件的数据。
  virtual ret_t OnInit(TRequestPtrRef request, bool first_time);

 public: /*helper*/
  //返回上一级窗口
  ret_t Back();
  //退出应用程序
  ret_t Quit();
  //返回到主窗口
  ret_t BackToHome();

  //强制关闭指定窗口
  static ret_t CloseForce(const char* name);
  //判断指定窗口是否打开
  static bool isWindowOpen(const char* name);
  //打开指定的窗口
  static ret_t Open(const char* name, bool close_current = false, TRequestPtr request = NULL);

  //查找指定控件
  TWidget Lookup(const char* name);
  //注册窗口的事件，子类可以重载OnEvent函数进行事件处理。
  uint32_t On(event_type_t etype);
  //注册控件的事件，子类可以重载OnEvent函数进行事件处理。
  uint32_t OnChild(event_type_t etype, const char* name);

  //获取AWTK窗口对象。
  TWidget& GetWindow() const {
    return mWindow;
  }

 public:
  virtual ~TAppWindow() {
    log_debug("~TAppWindow\n");
  }

 private:
  mutable TWidget mWindow;
  TRequestPtr mRequest;

 private:
  ret_t OnRequest(TRequestPtrRef request, bool first_time);
  static ret_t SwitchTo(const char* name, bool close_current = false, TRequestPtr request = NULL);

 private:
  TAppWindow(const TAppWindow& other);
  TAppWindow& operator=(const TAppWindow& other);
 friend class TWindowFactory;
};

#endif /*TK_APP_WINDOW_H*/
