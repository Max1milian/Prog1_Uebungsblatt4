cmake_minimum_required(VERSION 3.20.0)
project(Snek
	LANGUAGES C
	VERSION 0.0.1
	DESCRIPTION "Viertes Übungsblatt"
	HOMEPAGE_URL "https://github.com/Max1milian/Prog1_Uebungsblatt4")

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

if(MSVC)
    add_compile_options(/W3 /WX /permissive)
else()
    add_compile_options(-Wextra -Wall -Werror -pedantic-errors -fanalyzer)
endif(MSVC)


file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE -std=c11 ${CURSES_CFLAGS}) 
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
