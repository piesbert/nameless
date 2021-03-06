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

#include "engine/input/sdlinputif.hpp"

#include "engine/core/signalif.hpp"

#include <SDL.h>

namespace nameless {
namespace engine {
namespace input {

class SdlInput: public SdlInputIF {
public:
    SdlInput(core::SignalIF& signal);
    virtual ~SdlInput();

    virtual int handleEvents() override;

    SdlInput(const SdlInput&) = delete;
    SdlInput& operator=(const SdlInput&) = delete;

private:
    core::SignalIF& m_signal;
    SDL_Event m_event;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // HCC36A64A_1A1B_4154_B016_8150C1E169E4
