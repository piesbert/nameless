/* File:    taskif.hpp
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

#ifndef H4C9483F6_59B4_488D_85ED_7D0AABD6416B
#define H4C9483F6_59B4_488D_85ED_7D0AABD6416B

namespace nameless {
namespace engine {
namespace core {

class TaskObserverIF;

class TaskIF {
public:
    virtual ~TaskIF() {};

    virtual void attach(TaskObserverIF* taskObserver) = 0;
    virtual void run() const = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H4C9483F6_59B4_488D_85ED_7D0AABD6416B
