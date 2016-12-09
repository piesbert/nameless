/* File:    engine.hpp
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

#ifndef H729CB886_658D_477A_A723_9A1788E6AA65
#define H729CB886_658D_477A_A723_9A1788E6AA65

#include "engine/core/engineif.hpp"

#include "engine/core/kernelif.hpp"
#include "engine/core/mediaif.hpp"
#include "engine/core/moduleif.hpp"
#include "engine/core/signalif.hpp"
#include "engine/core/taskif.hpp"

#include <memory>

namespace nameless {
namespace engine {
namespace core {

class Engine: public EngineIF {
public:
    Engine();
    virtual ~Engine();

    virtual bool start() override;

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    std::unique_ptr<KernelIF> m_kernel;
    std::unique_ptr<SignalIF> m_signal;

    std::unique_ptr<MediaIF> m_media;

    std::unique_ptr<ModuleIF> m_inputModule;
    std::unique_ptr<ModuleIF> m_soundModule;
    std::unique_ptr<ModuleIF> m_stateModule;
    std::unique_ptr<ModuleIF> m_videoModule;

    std::unique_ptr<TaskIF> m_inputTask;
    std::unique_ptr<TaskIF> m_soundTask;
    std::unique_ptr<TaskIF> m_stateTask;
    std::unique_ptr<TaskIF> m_videoTask;

    void buildKernel();
    bool buildModules();
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H729CB886_658D_477A_A723_9A1788E6AA65
