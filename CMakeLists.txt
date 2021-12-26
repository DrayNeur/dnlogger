cmake_minimum_required(VERSION 3.0)

project(dnlogger)

add_subdirectory(libdnlogger)

set(SRCS
	test.cpp
	)
	
add_executable(main ${SRCS})

target_link_libraries(main dnlogger)