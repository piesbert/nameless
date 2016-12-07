/* File:    signalinterface.hpp
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

#ifndef HEB0194EE_316F_4F2B_A6EC_F0524C1E25B2
#define HEB0194EE_316F_4F2B_A6EC_F0524C1E25B2

namespace nameless {
namespace engine {
namespace core {

class SignalInterface {
public:
    virtual ~SignalInterface() {};

    enum class Id {
        KILL
    };

    virtual void send(Id id) const = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // HEB0194EE_316F_4F2B_A6EC_F0524C1E25B2
