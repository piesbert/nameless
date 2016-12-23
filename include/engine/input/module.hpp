/* File:    module.hpp
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

#ifndef H7C77C74F_AE5B_4DA9_BC50_67C10AA025FA
#define H7C77C74F_AE5B_4DA9_BC50_67C10AA025FA

#include "engine/core/interface/module.hpp"

#include "engine/api/input.hpp"
#include "engine/core/interface/signal.hpp"
#include "engine/core/interface/sdl.hpp"
#include "engine/input/interface/commander.hpp"
#include "engine/input/interface/sdlinput.hpp"

#include <memory>

namespace nameless {
namespace engine {
namespace input {

class Module: public core::interface::Module {
public:
    Module(core::interface::Signal& signal, core::interface::Sdl& sdl);
    virtual ~Module();

    virtual void build() override;
    virtual core::interface::TaskObserver* getObserver() const override;

    virtual void provideApi(api::Game& game) const override;

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;

private:
    core::interface::Signal& m_signal;
    core::interface::Sdl& m_sdl;

    std::unique_ptr<core::interface::TaskObserver> m_taskObserver;
    std::unique_ptr<interface::SdlInput> m_sdlInput;
    std::unique_ptr<interface::Commander> m_commander;
    std::unique_ptr<api::Input> m_input;

};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // H7C77C74F_AE5B_4DA9_BC50_67C10AA025FA
