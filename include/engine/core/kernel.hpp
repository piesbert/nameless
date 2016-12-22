/* File:    kernel.hpp
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

#ifndef H7858F920_30DE_45F2_8E2A_32D08DAE0DFA
#define H7858F920_30DE_45F2_8E2A_32D08DAE0DFA

#include "engine/core/interface/kernel.hpp"

#include "engine/core/interface/task.hpp"

namespace nameless {
namespace engine {
namespace core {

class Kernel: public interface::Kernel {
public:
    Kernel(interface::Task& inputTask, interface::Task& soundTask, interface::Task& stateTask, interface::Task& videoTask);
    virtual ~Kernel();
    
    virtual void start() override;
    virtual void kill() override;

    Kernel(const Kernel&) = delete;
    Kernel& operator=(const Kernel&) = delete;

private:
    bool m_running {true};

    interface::Task& m_inputTask;
    interface::Task& m_soundTask;
    interface::Task& m_stateTask;
    interface::Task& m_videoTask;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H7858F920_30DE_45F2_8E2A_32D08DAE0DFA
