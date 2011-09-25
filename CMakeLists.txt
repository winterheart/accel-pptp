CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(accel-pptp-plugin)

SET(PLUGIN_VERSION_MAJOR 0)
SET(PLUGIN_VERSION_MINOR 9)
SET(PLUGIN_VERSION_PATCH 0)

SET(srcDir src)

SET(srcFileList
	${srcDir}/dirutil.c
	${srcDir}/orckit_quirks.c
	${srcDir}/pptp.c
	${srcDir}/pptp_callmgr.c
	${srcDir}/pptp_ctrl.c
	${srcDir}/pptp_quirks.c
	${srcDir}/util.c
	${srcDir}/vector.c
)

CONFIGURE_FILE(
	"${PROJECT_SOURCE_DIR}/${srcDir}/pptp.h.in"
	"${PROJECT_BINARY_DIR}/${srcDir}/pptp.h"
)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/${srcDir}")

ADD_LIBRARY(pptp SHARED ${srcFileList})
SET_TARGET_PROPERTIES(pptp PROPERTIES PREFIX "")

