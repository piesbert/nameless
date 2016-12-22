/* File:    commander.hpp
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

#ifndef H15F12A9D_FFE3_4D19_B8DE_CE21518A235C
#define H15F12A9D_FFE3_4D19_B8DE_CE21518A235C

#include "engine/input/interface/commander.hpp"

#include <array>

namespace nameless {
namespace engine {
namespace input {

class Commander: public interface::Commander {
public:
    Commander();
    virtual ~Commander();

    virtual void execute(api::Input::Button button, api::Command::Message message) const override;
    virtual void attach(api::Command* command, api::Input::Button button) override;

    Commander(const Commander&) = delete;
    Commander& operator=(const Commander&) = delete;

private:
    std::array<api::Command*, api::Input::BUTTON_MAX> m_command;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // H15F12A9D_FFE3_4D19_B8DE_CE21518A235C
