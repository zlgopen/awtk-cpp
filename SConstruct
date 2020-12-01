import os
import scripts.app_helper as app

ARGUMENTS['FONT'] = 'default_full'
helper = app.Helper(ARGUMENTS);

helper.add_libs(['awtk-cpp']).call(DefaultEnvironment)

SConscriptFiles = ['3rd/quickjs/SConscript', 'src/SConscript', 'demos/SConscript']
SConscript(SConscriptFiles)
