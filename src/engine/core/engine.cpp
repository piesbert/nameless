/* File:    engine.cpp
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

#include "engine/core/engine.hpp"

#include "engine/core/kernel.hpp"
#include "engine/core/signal.hpp"
#include "engine/core/task.hpp"

#include "engine/input/module.hpp"

#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace core {

Engine::Engine() {
}

Engine::~Engine() {
}

void Engine::start() {
    buildKernel();
    buildModules();
    
    m_kernel->start();
}

void Engine::buildKernel() {
    m_kernel = std::make_unique<Kernel>();
    m_signal = std::make_unique<Signal>(*m_kernel);
}

void Engine::buildModules() {
    m_inputModule = std::make_unique<input::Module>();
    m_inputModule->build();

    m_inputTask = std::make_unique<Task>(m_inputModule->getObserver());
}

} // namespace core
} // namespace engine
} // namespace nameless
