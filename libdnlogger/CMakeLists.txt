
cmake_minimum_required(VERSION 3.0)

project(libdnlogger)

set(SRCS
	dnlogger.cpp
	messagebox.cpp
	)
	
set(HEADERS
	dnlogger.h
	messagebox.h
	)

	find_package(X11 REQUIRED)
	link_libraries(${X11_LIBRARIES})
	include_directories(${X11_INCLUDE_DIR})
add_library(dnlogger ${SRCS} ${HEADERS})