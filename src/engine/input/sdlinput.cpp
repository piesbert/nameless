/* File:    sdlinput.cpp
 * Project: nameless
 * Author:  Sebastian Szymak <sebastian.szymak@gmail.com>
 *
 * Copyright (C) 2016 Sebastian Szymak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "engine/input/sdlinput.hpp"

#include "engine/core/sdl.hpp"
#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace input {

SdlInput::SdlInput(core::SignalIF& signal)
: m_signal {signal} {
}

SdlInput::~SdlInput() {
}

int SdlInput::handleEvents() {
    int eventCnt {0};

    while(core::Sdl::call().SDL_PollEvent(&m_event)) {
        eventCnt++;

        if (m_event.type == SDL_QUIT) {
            m_signal.kill();
        }
    }

    LOGINF("Input events: " << eventCnt);

    return eventCnt;
}

} // namespace input
} // namespace engine
} // namespace nameless
