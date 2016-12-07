/* File:    taskobserverinterface.hpp
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

#ifndef H23EAE505_7634_46A1_BE97_17D0EFE3AE61
#define H23EAE505_7634_46A1_BE97_17D0EFE3AE61

namespace nameless {
namespace engine {
namespace core {

class TaskObserverInterface {
public:
    virtual ~TaskObserverInterface() {};

    virtual void update() = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H23EAE505_7634_46A1_BE97_17D0EFE3AE61
