cmake_minimum_required(VERSION 3.0)

project(sqlite3ep)


include_directories(source)

IF(UNIX)
    add_executable (sqlite3ep source/main.c source/sqlite3.c source/utils.c)

    target_link_libraries(sqlite3ep m dl pthread)

ELSE (WIN32)
    add_executable (sqlite3ep source/main.c source/sqlite3.c source/utils.c)

    target_link_libraries(sqlite3ep)

ENDIF (UNIX)

set(CMAKE_BUILD_TYPE Debug)
