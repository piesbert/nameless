/* File:    input.hpp
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

#ifndef H83F1A5A4_AE16_4891_87FD_74DCFDB72AC3
#define H83F1A5A4_AE16_4891_87FD_74DCFDB72AC3

#include "engine/api/input.hpp"
#include "engine/api/command.hpp"
#include "engine/input/interface/sdlinput.hpp"

namespace nameless {
namespace engine {
namespace input {

class Input: public api::Input {
public:
    Input(interface::SdlInput& sdlInput);
    virtual ~Input();

    virtual api::Input::Button attachCommand(api::Command* command, api::Input::Button button) const override;
    virtual api::Input::Button attachCommand(api::Command* command) const override;

    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;

private:
    interface::SdlInput& m_sdlInput;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // H83F1A5A4_AE16_4891_87FD_74DCFDB72AC3
