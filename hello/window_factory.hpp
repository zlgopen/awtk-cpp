/**
 * File:   window_factory.hpp
 * Author: AWTK Develop Team
 * Brief:  window factory
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

#ifndef TK_WINDOW_FACTORY_H
#define TK_WINDOW_FACTORY_H

#include "request.hpp"

class TAppWindow;

typedef TAppWindow* (*window_create_t)(TAppWindow* caller, bool close_current);

class TWindowFactory {
 private:
  TWindowFactory();
  virtual ~TWindowFactory();

 public:
  ret_t Register(const char* name, window_create_t create, bool single_instance);
  ret_t Open(const char* name, TAppWindow* caller, bool close_current, TRequestPtr request);
  ret_t Unregister(const char* name);

 public:
  static TWindowFactory* instance();
 private:
  object_t* mCreators;
  static TWindowFactory* sInstance;
};

#define WINDOW_REGISTER(Name, Class, SingleInstance) \
static struct WindowFactory##Class{ \
        static TAppWindow* create(TAppWindow* caller, bool close_current) { \
            if(close_current && caller != NULL) { \
              return new Class(TWindow::OpenAndClose(Name, caller->GetWindow())); \
            } else { \
              return new Class(TWindow::Open(Name)); \
            } \
        } \
        WindowFactory##Class() { \
          TWindowFactory::instance()->Register(Name, create, SingleInstance); \
        } \
    } aWindowFactory##Class;

#endif /*TK_WINDOW_FACTORY_H*/
