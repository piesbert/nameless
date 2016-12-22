/* File:    interface/kernel.hpp
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

#ifndef H11279318_97F1_48DC_9DFA_C6109C4AD6AF
#define H11279318_97F1_48DC_9DFA_C6109C4AD6AF

namespace nameless {
namespace engine {
namespace core {
namespace interface {

class Kernel {
public:
    virtual ~Kernel() {};

    virtual void start() = 0;
    virtual void kill() = 0;
};

} // namespace interface
} // namespace core
} // namespace engine
} // namespace nameless

#endif // H11279318_97F1_48DC_9DFA_C6109C4AD6AF
