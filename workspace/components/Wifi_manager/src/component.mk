#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_ADD_INCLUDEDIRS = Wifi_manager
COMPONENT_SRCDIRS = Wifi_manager
COMPONENT_DEPENDS = log
COMPONENT_EMBED_FILES := Wifi_manager/style.css Wifi_manager/jquery.gz Wifi_manager/code.js Wifi_manager/index.html

