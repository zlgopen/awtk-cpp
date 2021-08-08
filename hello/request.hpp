/**
 * File:   request.hpp
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

#ifndef TK_REQUEST_H
#define TK_REQUEST_H

#include <functional>
#include "awtk_cpp.hpp"

class TAppWindow;

class TRequest {
 public:
  TRequest(void) {
    mArgs = object_default_create();
  }

  TRequest(std::function<void(TAppWindow*)> OnTargetClose) : mOnTargetClose(OnTargetClose) {
    mArgs = object_default_create();
  }
  virtual ~TRequest() {
    OBJECT_UNREF(mArgs);
    log_debug("~TRequest\n");
  }

 public: /*virtual*/
  virtual void OnTargetClose(TAppWindow* target);

 public: /*helper*/
  bool Set(const char* name, int value);
  bool Set(const char* name, double value);
  bool Set(const char* name, const char* value);

  int GetInt(const char* name, int defval) const;
  double GetDouble(const char* name, double defval) const;
  const char* GetString(const char* name) const;

 private:
  TRequest(const TRequest& other);
  TRequest& operator=(const TRequest& other);

 private:
  object_t* mArgs;
  std::function<void(TAppWindow*)> mOnTargetClose;
};

typedef std::shared_ptr<TRequest> TRequestPtr;
typedef std::shared_ptr<TRequest>& TRequestPtrRef;

#endif /*TK_REQUEST_H*/
