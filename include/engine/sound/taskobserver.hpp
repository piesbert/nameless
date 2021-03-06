/* File:    taskobserver.hpp
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

#ifndef HF2FAE35A_5BC5_43FD_B9E2_CA3677C999D1
#define HF2FAE35A_5BC5_43FD_B9E2_CA3677C999D1

#include "engine/core/taskobserverif.hpp"

namespace nameless {
namespace engine {
namespace sound {

class TaskObserver: public core::TaskObserverIF {
public:
    TaskObserver();
    virtual ~TaskObserver();

    virtual void update() override;

    TaskObserver(const TaskObserver&) = delete;
    TaskObserver& operator=(const TaskObserver&) = delete;
};

} // namespace sound
} // namespace engine
} // namespace nameless

#endif // HF2FAE35A_5BC5_43FD_B9E2_CA3677C999D1
