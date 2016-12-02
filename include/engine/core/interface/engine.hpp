/* File:    interface/engine.hpp
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

#ifndef H3015AC03_D8D2_4406_9F6A_BDEB46404EE5
#define H3015AC03_D8D2_4406_9F6A_BDEB46404EE5

namespace nameless {
namespace engine {
namespace core {
namespace interface {

class Engine {
public:
    virtual ~Engine() {};

    virtual bool build() = 0;
    virtual bool run() = 0;
};

} // namespace interface
} // namespace core
} // namespace engine
} // namespace nameless

#endif // H3015AC03_D8D2_4406_9F6A_BDEB46404EE5
