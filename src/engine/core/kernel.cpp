/* File:    kernel.cpp
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

#include "engine/core/kernel.hpp"

#include "engine/core/task.hpp"
#include "engine/log/log.hpp"

#include <chrono>
#include <thread>

namespace nameless {
namespace engine {
namespace core {

Kernel::Kernel(TaskIF& inputTask, TaskIF& soundTask, TaskIF& stateTask, TaskIF& videoTask) 
: m_inputTask {inputTask},
  m_soundTask {soundTask},
  m_stateTask {stateTask},
  m_videoTask {videoTask} {
    LOGINF("Kernel init.");
}

Kernel::~Kernel() {
    LOGINF("Kernel shutdown.");
}

void Kernel::start() {
    while (m_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        m_inputTask.run();
        m_soundTask.run();
        m_stateTask.run();
        m_videoTask.run();
    }
}

void Kernel::kill() {
    m_running = false;
}

} // namespace core
} // namespace engine
} // namespace nameless
