///////////////////////////////////////////
///////////////////////////////////////////

//生成代码时，请修改下面的参数：

//name必须与ui的资源名称一致。
let name = 'foo'; 
//Name为name转换成驼峰格式的名称。
let Name = 'Foo';
const date = '2021-08-08';
const author = 'Li XianJing <xianjimli@hotmail.com>';
const copyright = '2018 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.';

if (process.argv.length > 3) {
  name = process.argv[2];
  Name = process.argv[3];
  console.log(process.argv);
}

///////////////////////////////////////////
const cppFileName = `window_${name}.cpp`
const hppFileName = `window_${name}.hpp`
const fs = require('fs');
const UTF8BOM = "\ufeff";
const NAME=name.toUpperCase();

let c = `
/**
 * File:   window_${name}.cpp
 * Author: AWTK Develop Team
 * Brief:  ${name} window
 *
 * Copyright (c) 2018 - 2021  ${copyright}
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
 * ${date} ${author} created
 *
 */

#include "window_${name}.hpp"

void Window${Name}::OnOpen() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void Window${Name}::OnWillOpen() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void Window${Name}::OnClose() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void Window${Name}::OnToBackGround() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void Window${Name}::OnToForeGround() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

ret_t Window${Name}::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t Window${Name}::OnHookEvents() {
/*
 * TODO: hook events at here
 */
  this->OnChild(EVT_CLICK, "close");

  return TAppWindow::OnHookEvents();
}

ret_t Window${Name}::OnRequest(TRequestPtrRef request, bool first_time) {
/*
  TODO: initialize widget at here
  int value = request->GetInt("value", 10);
  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);
*/
  return TAppWindow::OnRequest(request, first_time);
}

WINDOW_REGISTER("${name}", Window${Name}, TRUE);
`

let h = `
/**
 * File:   window_${name}.hpp
 * Author: AWTK Develop Team
 * Brief:  ${name} window
 *
 * Copyright (c) 2018 - 2021  ${copyright}
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
 * ${date} ${author} created
 *
 */

#ifndef TK_WINDOW_${NAME}_H
#define TK_WINDOW_${NAME}_H

#include "awtk_cpp.hpp"
#include "app_window.hpp"

class Window${Name} : public TAppWindow {
 public:
  Window${Name}(TWidget win) : TAppWindow(win) {
  }

 public:
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();
  virtual ret_t OnHookEvents();
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  virtual ret_t OnRequest(TRequestPtrRef request, bool first_time);
};

#endif /*TK_WINDOW_${NAME}_H*/
`

fs.writeFileSync(cppFileName, UTF8BOM + c);
fs.writeFileSync(hppFileName, UTF8BOM + h);

console.log(`output to ${cppFileName} and ${hppFileName}`);
