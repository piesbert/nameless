/* File:    sdlinputif.hpp
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

#ifndef HB145BE7E_B032_4C23_8B5F_3318D17F7480
#define HB145BE7E_B032_4C23_8B5F_3318D17F7480

namespace nameless {
namespace engine {
namespace input {

class SdlInputIF {
public:
    virtual ~SdlInputIF() {};

    virtual int handleEvents() = 0;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // HB145BE7E_B032_4C23_8B5F_3318D17F7480
