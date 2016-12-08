/* File:    taskobserver.cpp
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

#include "engine/sound/taskobserver.hpp"

#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace sound {

TaskObserver::TaskObserver() {
}

TaskObserver::~TaskObserver() {
}

void TaskObserver::update() {
    LOGINF("Sound module updated.");
}

} // namespace sound
} // namespace engine
} // namespace nameless