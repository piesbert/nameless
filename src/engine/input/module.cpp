/* File:    module.cpp
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

#include "engine/input/module.hpp"

#include "engine/input/sdlinput.hpp"
#include "engine/input/taskobserver.hpp"

namespace nameless {
namespace engine {
namespace input {

Module::Module(core::SignalIF& signal)
: m_signal {signal} {
}

Module::~Module() {
}

void Module::build() {
    m_sdlInput = std::make_unique<SdlInput>(m_signal);
    m_taskObserver = std::make_unique<TaskObserver>(*m_sdlInput);
}

core::TaskObserverIF* Module::getObserver() const {
    return m_taskObserver.get();
}

} // namespace input
} // namespace engine
} // namespace nameless
