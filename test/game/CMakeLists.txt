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

set(TEST_NAME nameless_game_test)

#add_subdirectory(lib/googletest)
#include_directories(                                                          
#    ${gmock_SOURCE_DIR}/include                                               
#    ${gtest_SOURCE_DIR}/include                                               
#    )

#Uncomment this in the future instead of writing null to testing.cpp"
#set(CORE_SOURCES
#    ./core/signal.cpp
#    )
file(WRITE testing.cpp "")

add_executable(
    ${TEST_NAME}
    testing.cpp
    )

target_link_libraries(
    ${TEST_NAME}
    gmock                                                                       
    gmock_main                                                                  
    ${ENGINE_LIB_NAME}                                                          
    ${GAME_LIB_NAME}                                                            
    ) 
