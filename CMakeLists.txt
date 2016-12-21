# Project: nameless                                                             
# Copyright (C) 2015 Sebastian Szymak                                           
#                                                                               
# This program is free software: you can redistribute it and/or modify          
# it under the terms of the GNU General Public License as published by          
# the Free Software Foundation, either version 3 of the License, or             
# (at your option) any later version.                                           
#                                                                               
# This program is distributed in the hope that it will be useful,               
# but WITHOUT ANY WARRANTY; without even the implied warranty of                
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 
# GNU General Public License for more details.                                  
#                                                                               
# You should have received a copy of the GNU General Public License             
# along with this program.  If not, see <http://www.gnu.org/licenses/>          
                                                                                
cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(nameless)

set(ENGINE_LIB_NAME engine)
set(GAME_LIB_NAME game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(GCC_PROJECT_COMPILE_FLAGS "-std=c++14 -Wall -g")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GCC_PROJECT_COMPILE_FLAGS})

enable_testing()

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/include"
    "${PROJECT_SOURCE_DIR}/test"
    "${PROJECT_BINARY_DIR}/test"
    "${SDL2_INCLUDE_DIR}"
    "${GLEW_INCLUDE_DIRS}"
    )

message(${GLEW_INCLUDE_DIRS})

#add_subdirectory("doc")
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)

add_test(nameless_engine bin/nameless_engine_test)
add_test(nameless_game bin/nameless_game_test)
