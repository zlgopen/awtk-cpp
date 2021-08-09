///////////////////////////////////////////
///////////////////////////////////////////

//生成代码时，请修改下面的参数：

//name必须与ui的资源名称一致。
let name = 'foo';

const date = '2021-08-08';
const designDir = '../design';
const author = 'Li XianJing <xianjimli@hotmail.com>';
const copyright = '2018 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.';

if (process.argv.length > 2) {
  name = process.argv[2];
}

///////////////////////////////////////////
const fs = require('fs');
let convert = require('xml-js');

const UTF8BOM = "\ufeff";
const NAME = name.toUpperCase();
const Name = upperCamelName(name);
const cppFileName = `window_${name}.cpp`
const hppFileName = `window_${name}.hpp`
const uiFileName = `window_${name}_ui.hpp`
const className = `Window${Name}`;
const uiClassName = `${className}UI`;
const xmlFilename = `${designDir}/default/ui/${name}.xml`

function upperCamelName(name) {
  name = name.replace(/_t$/, '');
  name = name.replace(/(^|_)[a-z]/g, r => {
    if (r.length > 1) {
      r = r.substr(1);
    }

    return r.toUpperCase();
  });

  return name;
}

let c = `
/**
 * File:   ${cppFileName}
 * Author: AWTK Develop Team
 * Brief:  ${name} window
 *
 * Copyright (c) ${copyright}
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

#include "${hppFileName}"
#include "${uiFileName}"

void ${className}::OnOpen() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void ${className}::OnWillOpen() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void ${className}::OnClose() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void ${className}::OnToBackGround() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

void ${className}::OnToForeGround() {
  log_debug("%s: %s\\n", __FUNCTION__, this->GetWindow().GetName());
}

ret_t ${className}::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t ${className}::OnHookEvents() {
/*
 * TODO: hook events at here
 */
  this->OnChild(EVT_CLICK, "close");

  return TAppWindow::OnHookEvents();
}

ret_t ${className}::OnInit(TRequestPtrRef request, bool first_time) {
/*
  TODO: initialize widget at here
  int value = request->GetInt("value", 10);
  this->Lookup("bar1").SetValue(value);
  this->Lookup("bar2").SetValue(value);
*/
  return RET_OK;
}

WINDOW_REGISTER("${name}", ${className}, TRUE);
`

let h = `
/**
 * File:   ${hppFileName}
 * Author: AWTK Develop Team
 * Brief:  ${name} window
 *
 * Copyright (c) ${copyright}
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

#include "app_window.hpp"
#include "${uiFileName}"

class ${className} : public TAppWindow {
 public:
  ${className}(TWidget win) : TAppWindow(win) {
    this->ui.Init(win);
  }

 public:
  virtual void OnOpen();
  virtual void OnClose();
  virtual void OnWillOpen();
  virtual void OnToBackGround();
  virtual void OnToForeGround();
  virtual ret_t OnHookEvents();
  virtual ret_t OnEvent(TWidget& target, TEvent& e);
  virtual ret_t OnInit(TRequestPtrRef request, bool first_time);
private:
  ${className}UI ui;
};

#endif /*TK_WINDOW_${NAME}_H*/
`

function parseNamedWidgets(filename) {
  let xml = fs.readFileSync(filename, 'utf-8');
  let result1 = convert.xml2json(xml, { compact: true, spaces: 4 });
  let json = JSON.parse(result1);

  let namedWidgets = [];
  function dumpWidget(widgetType, widget) {
    if (widgetType && widget._attributes) {
      let name = widget._attributes['name'];
      if (name) {
        namedWidgets.push({ name: name, type: widgetType });
      }
    }

    if (widget.length > 0) {
      widget.forEach((iter) => {
        let child = {};
        child._attributes = iter._attributes;
        dumpWidget(widgetType, child);
      })
    } else {
      for (let type in widget) {
        if (type != '_attributes') {
          let child = widget[type];
          dumpWidget(type, child);
        }
      }

    }
  }

  dumpWidget('window', json);

  return namedWidgets;
}

function toWidgetType(type) {
  return `T${upperCamelName(type)}`;
}

function genUICode(name, filename) {
  let decls = '';
  let lookups = ''
  let Name = upperCamelName(name);
  let namedWidgets = parseNamedWidgets(filename);

  namedWidgets.forEach(iter => {
    decls += `  ${toWidgetType(iter.type)} ${iter.name};\n`
    lookups += `    this->${iter.name} = ${toWidgetType(iter.type)}::Cast(win.Lookup("${iter.name}", TRUE));\n`
  })

let uiClass = `
/**
 * File:   ${uiFileName}
 * Author: AWTK Develop Team
 * Brief:  ${name} window ui
 *
 * Copyright (c) ${copyright}
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
#ifndef TK_WINDOW_${NAME}_UI_H
#define TK_WINDOW_${NAME}_UI_H

#include "awtk_cpp.hpp"

class ${uiClassName} {
public:
  ${uiClassName}() {};
  ~${uiClassName}() {} 
public:
${decls}
public:
 void Init(TWidget win) {
${lookups}
    return;
 }
};
#endif /*TK_WINDOW_${NAME}_UI_H*/
`
  return uiClass;
}

let ui = genUICode(name, xmlFilename);

fs.writeFileSync(cppFileName, UTF8BOM + c);
fs.writeFileSync(hppFileName, UTF8BOM + h);
fs.writeFileSync(uiFileName, UTF8BOM + ui);

console.log(`Output to ${cppFileName} ${hppFileName} ${uiFileName}`);

