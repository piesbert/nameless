/* File:    sdlinput.hpp
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

#ifndef HCC36A64A_1A1B_4154_B016_8150C1E169E4
#define HCC36A64A_1A1B_4154_B016_8150C1E169E4

#include "engine/input/interface/sdlinput.hpp"

#include "engine/core/interface/signal.hpp"
#include "engine/input/interface/commander.hpp"

#include <SDL.h>

#define MOUSE_BUTTONS 9

namespace nameless {
namespace engine {
namespace input {

class SdlInput: public interface::SdlInput {
public:
    SdlInput(core::interface::Signal& signal, interface::Commander& commander);
    virtual ~SdlInput();

    virtual int handleEvents() override;

    virtual api::Input::Button attachCommand(api::Command* command, api::Input::Button button) override;
    virtual api::Input::Button attachCommand(api::Command* command) override;

    SdlInput(const SdlInput&) = delete;
    SdlInput& operator=(const SdlInput&) = delete;

private:
    core::interface::Signal& m_signal;
    interface::Commander& m_commander;
    SDL_Event m_event;

    api::Input::Button m_trTable[SDL_NUM_SCANCODES + MOUSE_BUTTONS];

    void handleKey(api::Command::Message message);
    void handleButton(api::Command::Message message);
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // HCC36A64A_1A1B_4154_B016_8150C1E169E4
