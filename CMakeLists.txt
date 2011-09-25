PROJECT(accel-pptp-plugin)

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

ADD_LIBRARY(pptp SHARED ${srcFileList})
