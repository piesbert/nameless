/* File:    commandif.hpp
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

#ifndef HCA116080_F71C_48D5_B74F_A7B6BC26ABB1
#define HCA116080_F71C_48D5_B74F_A7B6BC26ABB1

namespace nameless {
namespace engine {
namespace input {

class CommandIF {
public:
    virtual ~CommandIF() {};

    enum State {
        START = 0,
        STOP
    };

    virtual void execute(State state) = 0;

    CommandIF(const CommandIF&) = delete;
    CommandIF& operator=(const CommandIF&) = delete;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // HCA116080_F71C_48D5_B74F_A7B6BC26ABB1
