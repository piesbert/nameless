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
#include "engine/core/media.hpp"
#include "engine/core/signal.hpp"
#include "engine/core/task.hpp"

#include "engine/input/module.hpp"
#include "engine/sound/module.hpp"
#include "engine/state/module.hpp"
#include "engine/video/module.hpp"

#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace core {

Engine::Engine() {
    LOGINF("Start your engine!");
}

Engine::~Engine() {
    LOGINF("Slowing down...");
}

bool Engine::start() {
    bool retval {false};

    m_media = std::make_unique<Media>();

    if (m_media->init()) {
        buildKernel();
        if (buildModules()) {
            m_kernel->start();
            retval = true;
        }
    }

    return retval;
}

void Engine::buildKernel() {
    m_inputTask = std::make_unique<Task>();
    m_soundTask = std::make_unique<Task>();
    m_stateTask = std::make_unique<Task>();
    m_videoTask = std::make_unique<Task>();

    m_kernel = std::make_unique<Kernel>(*m_inputTask, *m_soundTask, *m_stateTask, *m_videoTask);
    m_signal = std::make_unique<Signal>(*m_kernel);
}

bool Engine::buildModules() {
    m_inputModule = std::make_unique<input::Module>(*m_signal);
    m_inputModule->build();
    m_soundModule = std::make_unique<sound::Module>(*m_signal);
    m_soundModule->build();
    m_stateModule = std::make_unique<state::Module>(*m_signal);
    m_stateModule->build();
    m_videoModule = std::make_unique<video::Module>(*m_signal);
    m_videoModule->build();

    m_inputTask->attach(m_inputModule->getObserver());
    m_soundTask->attach(m_soundModule->getObserver());
    m_stateTask->attach(m_stateModule->getObserver());
    m_videoTask->attach(m_videoModule->getObserver());

    return true;
}

} // namespace core
} // namespace engine
} // namespace nameless
