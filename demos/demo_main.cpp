/**
 * File:   demo_main.cpp
 * Author: AWTK Develop Team
 * Brief:  demo main
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
 * 2019-12-21 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "application.hpp"

static ret_t application_init(void) {
  Application::Init();

  return RET_OK;
}

static ret_t application_exit(void) {
  Application::Exit();

  return RET_OK;
}

#include "awtk_main.inc"


