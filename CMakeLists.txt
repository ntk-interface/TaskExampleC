cmake_minimum_required(VERSION 3.5)
project(TaskExampleC)
set(CMAKE_C_STANDARD 99)

include_directories(inc)

set(SOURCE_FILES src/main.c)

if (WIN32)
	link_directories(links)
	add_definitions(-DIF_PORTABLE)
else ()
	link_directories(links)
	add_definitions(-DIF_PORTABLE -DLINUX -DTMCONN_NEW)
endif ()

add_executable(TaskExampleC ${SOURCE_FILES})

if (WIN32)
	target_link_libraries(TaskExampleC
			-llibif_cfs
			)

	add_custom_command(TARGET TaskExampleC POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy
			${CMAKE_SOURCE_DIR}/links/libif_cfs.dll
			${CMAKE_CURRENT_BINARY_DIR}/libif_cfs.dll
	        )
else ()
	target_link_libraries(TaskExampleC
			-lif_cfs
			-pthread
			-lm
			-ldl
			-lssl
			-lcrypto
			)
endif ()