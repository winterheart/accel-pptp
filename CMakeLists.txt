cmake_minimum_required(VERSION 3.1)
project(accel-pptp VERSION 0.8.7.1)

set(PPP_PREFIX_DIR "/usr" CACHE STRING "Prefix dir for installed PPP")

include(CheckIncludeFiles)
check_include_files("pppd/pathnames.h;pppd/patchlevel.h" HAVE_PPP_HEADERS)
if(NOT HAVE_PPP_HEADERS)
	message(FATAL_ERROR "PPPD not found. Please install pppd-devel package.")
endif()

try_run(RUN_RESULT COMPILE_RESULT
	${PROJECT_BINARY_DIR}/CMakeTmp
	${PROJECT_SOURCE_DIR}/ppp_path_check.c
	COMPILE_DEFINITIONS "-DDESTDIR=\"${PPP_PREFIX_DIR}\""
	RUN_OUTPUT_VARIABLE PPP_PLUGIN_PATH
)

message(STATUS "PPP_PLUGIN_PATH is " ${PPP_PLUGIN_PATH})

set(srcFileList
	src/dirutil.c
	src/orckit_quirks.c
	src/pptp.c
	src/pptp_callmgr.c
	src/pptp_ctrl.c
	src/pptp_quirks.c
	src/util.c
	src/vector.c
)

configure_file(
	"${PROJECT_SOURCE_DIR}/src/pptp.h.in"
	"${PROJECT_BINARY_DIR}/pptp.h"
)
include_directories("${PROJECT_BINARY_DIR}")

add_library(pptp SHARED ${srcFileList})
set_target_properties(pptp PROPERTIES PREFIX "")

install(TARGETS pptp LIBRARY DESTINATION ${PPP_PLUGIN_PATH})
install(FILES pppd-pptp.8 DESTINATION share/man/man8)

# Packaging stuff
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Accel-PPTP client plugin for PPPd")
set(CPACK_PACKAGE_VENDOR "Azamat H. Hackimov <azamat.hackimov@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_SOURCE_PACKAGE_FILE_NAME
	"${CMAKE_PROJECT_NAME}-${PROJECT_VERSION}")
set(CPACK_SOURCE_GENERATOR TBZ2)
set(CPACK_SOURCE_IGNORE_FILES
  "/build;/.git*;.idea;/cmake-build-*")

include(CPack)
