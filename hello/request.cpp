/**
 * File:   request.cpp
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

#include "request.hpp"

void TRequest::OnTargetClose(TAppWindow* target) {
  log_debug("TRequest::OnTargetClose\n");
  mOnTargetClose(target);
}

bool TRequest::Set(const char* name, int value) {
  return object_set_prop_int(mArgs, name, value) == RET_OK;
}

bool TRequest::Set(const char* name, double value) {
  return object_set_prop_double(mArgs, name, value) == RET_OK;
}

bool TRequest::Set(const char* name, const char* value) {
  return object_set_prop_str(mArgs, name, value) == RET_OK;
}

int TRequest::GetInt(const char* name, int defval) const {
  return object_get_prop_int(mArgs, name, defval);
}

double TRequest::GetDouble(const char* name, double defval) const {
  return object_get_prop_double(mArgs, name, defval);
}

const char* TRequest::GetString(const char* name) const {
  return object_get_prop_str(mArgs, name);
}
