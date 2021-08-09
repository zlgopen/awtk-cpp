/**
 * File:   window_factory.cpp
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

#include "window_factory.hpp"
#include "app_window.hpp"

TWindowFactory::TWindowFactory() {
  platform_prepare();
  mCreators = object_default_create();
}

TWindowFactory::~TWindowFactory() {
  OBJECT_UNREF(mCreators);
}

TWindowFactory* TWindowFactory::instance() {
  if(TWindowFactory::sInstance == NULL) {
    TWindowFactory::sInstance = new TWindowFactory();
  }
  return TWindowFactory::sInstance;
}

static const char* gen_single_instance_prop_name(char* prop, size_t size, const char* name) {
  tk_snprintf(prop, size, "%s_single_instance", name);

  return prop;
}

ret_t TWindowFactory::Register(const char* name, window_create_t create, bool single_instance) {
  char single_instance_prop_name[128];
  return_value_if_fail(name != NULL && create != NULL, RET_BAD_PARAMS);
  gen_single_instance_prop_name(single_instance_prop_name, sizeof(single_instance_prop_name), name);

  object_set_prop_pointer(mCreators, name, (void*)create);
  object_set_prop_bool(mCreators, single_instance_prop_name, single_instance);

  return RET_OK;
}

ret_t TWindowFactory::Open(const char* name, TAppWindow* caller, bool close_current, TRequestPtr request) {
  char single_instance_prop_name[128];
  window_create_t create = NULL;
  bool_t single_instance = FALSE;
  return_value_if_fail(name != NULL, RET_BAD_PARAMS);
  gen_single_instance_prop_name(single_instance_prop_name, sizeof(single_instance_prop_name), name);

  create = (window_create_t)object_get_prop_pointer(mCreators, name);
  single_instance = object_get_prop_bool(mCreators, single_instance_prop_name, FALSE);
  return_value_if_fail(create != NULL, RET_NOT_FOUND);

  if (caller != NULL && single_instance && TAppWindow::isWindowOpen("basic")) {
    return caller->SwitchTo("basic", close_current, request);
  } else {
    TAppWindow* win = create(caller, close_current);
    return win->OnRequest(request, true);
  }
}

ret_t TWindowFactory::Unregister(const char* name) {
  char single_instance_prop_name[128];
  return_value_if_fail(name != NULL, RET_BAD_PARAMS);
  gen_single_instance_prop_name(single_instance_prop_name, sizeof(single_instance_prop_name), name);

  object_remove_prop(mCreators, name);
  object_remove_prop(mCreators, single_instance_prop_name);

  return RET_OK;
}

TWindowFactory* TWindowFactory::sInstance = NULL;
