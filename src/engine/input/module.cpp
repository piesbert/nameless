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

#include "engine/input/commander.hpp"
#include "engine/input/sdlinput.hpp"
#include "engine/input/taskobserver.hpp"
#include "engine/input/input.hpp"

namespace nameless {
namespace engine {
namespace input {

Module::Module(core::interface::Signal& signal)
: m_signal {signal} {
}

Module::~Module() {
}

void Module::build() {
    m_commander = std::make_unique<Commander>();
    m_sdlInput = std::make_unique<SdlInput>(m_signal, *m_commander);
    m_taskObserver = std::make_unique<TaskObserver>(*m_sdlInput);
    m_input = std::make_unique<Input>(*m_sdlInput);
}

core::interface::TaskObserver* Module::getObserver() const {
    return m_taskObserver.get();
}

void Module::provideApi(api::Game& game) const {
    game.setInputApi(m_input.get());
}

} // namespace input
} // namespace engine
} // namespace nameless
