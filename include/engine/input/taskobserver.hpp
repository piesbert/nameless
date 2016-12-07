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

#ifndef HE440E6BA_2B61_4257_ADA2_2D5BB2F84992
#define HE440E6BA_2B61_4257_ADA2_2D5BB2F84992

#include "engine/core/taskobserverinterface.hpp"

namespace nameless {
namespace engine {
namespace input {

class TaskObserver: public core::TaskObserverInterface {
public:
    TaskObserver();
    virtual ~TaskObserver();

    virtual void update() override;

private:
    TaskObserver(const TaskObserver&) = delete;
    TaskObserver& operator=(const TaskObserver&) = delete;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // HE440E6BA_2B61_4257_ADA2_2D5BB2F84992
