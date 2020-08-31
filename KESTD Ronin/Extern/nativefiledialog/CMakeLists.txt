if(WIN32)
	add_library("nativefiledialog" STATIC 
	"src/common.h"
	#"src/nfd_cocoa.m"
	"src/nfd_common.c"
	"src/nfd_common.h"
	#"src/nfd_gtk.c"
	"src/nfd_win.cpp"
	#"src/nfd_zenity.c"
	"src/include/nfd.h")
elseif(APPLE)
	add_library("nativefiledialog" STATIC 
	"src/common.h"
	"src/nfd_cocoa.m"
	"src/nfd_common.c"
	"src/nfd_common.h"
	#"src/nfd_gtk.c"
	#"src/nfd_win.cpp"
	#"src/nfd_zenity.c"
	"src/include/nfd.h")
else()
	add_library("nativefiledialog" STATIC 
	"src/common.h"
	#"src/nfd_cocoa.m"
	"src/nfd_common.c"
	"src/nfd_common.h"
	"src/nfd_gtk.c"
	#"src/nfd_win.cpp"
	"src/nfd_zenity.c"
	"src/include/nfd.h")
endif()