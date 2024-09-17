cmake_minimum_required(VERSION 3.30)

project(
  covid19_simulator
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

message("gtk3 libs " ${GTK3_LIBRARIES})
message("gtk3 lib dirs " ${GTK3_LIBRARY_DIRS})
message("gtk3 include dirs " ${GTK3_INCLUDE_DIRS})

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

set(EXECUTABLE_TEST first_exec)

add_subdirectory(app)
