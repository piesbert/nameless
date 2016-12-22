/* File:    interface/commander.hpp
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

#ifndef H2E6F2745_E303_4CB9_A365_8BCFB482CEE5
#define H2E6F2745_E303_4CB9_A365_8BCFB482CEE5

#include "engine/api/input.hpp"
#include "engine/api/command.hpp"

namespace nameless {
namespace engine {
namespace input {
namespace interface {

class Commander {
public:
    virtual ~Commander() {};

    virtual void execute(api::Input::Button button, api::Command::Message message) const = 0;
    virtual void attach(api::Command* command, api::Input::Button button) = 0;
};

} // namespace interface
} // namespace input
} // namespace engine
} // namespace nameless

#endif // H2E6F2745_E303_4CB9_A365_8BCFB482CEE5