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

#ifndef HC55D6AD2_5C88_4F23_9BE3_F8D740693AD6
#define HC55D6AD2_5C88_4F23_9BE3_F8D740693AD6

#include "engine/core/interface/module.hpp"

#include "engine/core/interface/signal.hpp"

#include <memory>

namespace nameless {
namespace engine {
namespace video {

class Module: public core::interface::Module {
public:
    Module(core::interface::Signal& signal);
    virtual ~Module();

    virtual void build() override;
    virtual core::interface::TaskObserver* getObserver() const override;

    virtual void provideApi(api::Game& game) const override;

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;

private:
    core::interface::Signal& m_signal;

    std::unique_ptr<core::interface::TaskObserver> m_taskObserver;
};

} // namespace video
} // namespace engine
} // namespace nameless

#endif // HC55D6AD2_5C88_4F23_9BE3_F8D740693AD6
