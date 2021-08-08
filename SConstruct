import os
import platform
import scripts.app_helper as app

ARGUMENTS['FONT'] = 'default_full'
helper = app.Helper(ARGUMENTS);

APP_CXXFLAGS=''
if platform.system() == 'Windows':
  APP_CXXFLAGS += ' /std:c++17 '
else:
  APP_CXXFLAGS += ' -std=c++17 '

helper.add_cxxflags(APP_CXXFLAGS)
helper.add_libs(['awtk-cpp']).call(DefaultEnvironment)

SConscriptFiles = ['3rd/quickjs/SConscript', 'src/SConscript', 'demos/SConscript']
helper.SConscript(SConscriptFiles)
