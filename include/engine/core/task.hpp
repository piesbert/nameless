/* File:    task.hpp
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

#ifndef HC5EAACEA_0CC0_4458_ACFF_5E1881955C15
#define HC5EAACEA_0CC0_4458_ACFF_5E1881955C15

#include "engine/core/taskinterface.hpp"

#include "engine/core/taskobserverinterface.hpp"

namespace nameless {
namespace engine {
namespace core {

class Task: public TaskInterface {
public:
    Task();
    virtual ~Task();

    virtual void attach(TaskObserverInterface* taskObserver);
    virtual void run() const;

    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

private:
    TaskObserverInterface* m_taskObserver;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // HC5EAACEA_0CC0_4458_ACFF_5E1881955C15
