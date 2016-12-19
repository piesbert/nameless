/* File:    commander.cpp
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

#include "engine/input/commander.hpp"

#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace input {

Commander::Commander() {
    for (int i = 0; i < SdlInputIF::BUTTON_MAX; i++) {
        m_command[i] = nullptr;
    }
}

Commander::~Commander() {
}

void Commander::execute(SdlInputIF::Button button, CommandIF::State state) const {
    if (m_command[button] != nullptr) {
        m_command[button]->execute(state);
    }

    LOGINF("BUTTON: " << (int)button << ", " << (int)state);
}

void Commander::attach(CommandIF* command, SdlInputIF::Button button) {
    for (int i = 0; i < SdlInputIF::BUTTON_MAX; i++) {
        if (m_command[i] == command) {
            m_command[i] = nullptr;
        }
    }

    m_command[button] = command;
}

} // namespace input
} // namespace engine
} // namespace nameless
