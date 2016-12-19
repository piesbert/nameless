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

set(ENGINE_NAME engine)

set(CORE_SOURCES
    ./core/engine.cpp
    ./core/kernel.cpp
    ./core/media.cpp
    ./core/opengl.cpp
    ./core/sdl.cpp
    ./core/signal.cpp
    ./core/task.cpp
    )

set(LOG_SOURCES
    ./log/log.cpp
    )

set(INPUT_SOURCES
    ./input/commander.cpp
    ./input/module.cpp
    ./input/sdlinput.cpp
    ./input/taskobserver.cpp
    )
        
set(SOUND_SOURCES
    ./sound/module.cpp
    ./sound/taskobserver.cpp
    )

set(STATE_SOURCES
    ./state/module.cpp
    ./state/taskobserver.cpp
    )

set(VIDEO_SOURCES
    ./video/module.cpp
    ./video/taskobserver.cpp
    )

add_library(
    ${ENGINE_NAME}
    ${CORE_SOURCES}
    ${INPUT_SOURCES}
    ${LOG_SOURCES}
    ${SOUND_SOURCES}
    ${STATE_SOURCES}
    ${VIDEO_SOURCES}
    )
