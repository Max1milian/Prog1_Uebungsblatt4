cmake_minimum_required(VERSION 3.25.0)
project(Uebungsblatt4
	LANGUAGES C
	VERSION 0.0.1
	DESCRIPTION "Viertes Übungsblatt"
	HOMEPAGE_URL "https://github.com/Max1milian/Prog1_Uebungsblatt4")

find_package(Curses REQUIRED)

if(MSVC)
    add_compile_options(/W3 /WX /permissive)
else()
    add_compile_options(-Wextra -Wall -Werror -pedantic-errors)
endif(MSVC)


file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
target_compile_options(${PROJECT_NAME} PRIVATE -stc=c11)
