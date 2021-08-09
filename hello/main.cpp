/**
 * File:   main.cpp
 * Author: AWTK Develop Team
 * Brief:  app main
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
 * 2021-08-08 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "window_main.hpp"

static ret_t application_init(void) {
  TWindow::Open("system_bar");

  TAppWindow::OpenFirst("main", NULL);

  return RET_OK;
}

static ret_t application_exit(void) {
  return RET_OK;
}

#define APP_DEFAULT_FONT "default_full"

#include "awtk_main.inc"
