## 代码生成

### 准备

> 请先安装nodejs。

* 安装依赖的库

```
npm install
```

* 修改参数

打开gen.js文件，根据自己的情况修改文件前面的参数。如：

```js
let name = 'foo';

const date = '2021-08-08';
const designDir = '../design';
const author = 'Li XianJing <xianjimli@hotmail.com>';
const copyright = '2018 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.';
```

> name 必须是有效的UI资源文件名(不包含扩展名和路径)

### 运行gen.js

```
node gen.js [name]
```

示例：

```
node gen.js gauge
```

>在这个例子中，../design/default/ui/gauge.xml文件必须存在。

