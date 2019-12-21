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

extern "C" ret_t assets_init(void);

#ifdef USE_GUI_MAIN
int gui_app_start(int lcd_w, int lcd_h) {
  tk_init(lcd_w, lcd_h, APP_MOBILE, NULL, NULL);
#elif defined(WIN32)
#include <windows.h>
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow) {
  tk_init(320, 480, APP_SIMULATOR, "AWTK-CPP", NULL);
#else
int main(void) {
  tk_init(320, 480, APP_SIMULATOR, "AWTK-CPP", NULL);
#endif

#ifdef WITH_FS_RES
  system_info_set_default_font(system_info(), "default_full");
#endif /*WITH_FS_RES*/

  TK_ENABLE_CONSOLE();

  assets_init();
  tk_ext_widgets_init();

  Application::Init();
  tk_run();
  Application::Exit();

  return 0;
}
