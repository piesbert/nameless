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
                         
set(APP_NAME nameless)
set(APP_SOURCES main.cpp)

set(APP_LIBS
    engine
    )

add_executable(${APP_NAME} ${APP_SOURCES})
target_link_libraries(${APP_NAME} ${APP_LIBS} ${SDL2_LIBRARY} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})

message(${GLEW_LIBRARIES})

add_subdirectory(engine)
