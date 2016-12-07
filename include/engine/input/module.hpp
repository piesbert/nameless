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

#include "engine/core/moduleinterface.hpp"

#include <memory>

namespace nameless {
namespace engine {
namespace input {

using namespace nameless::engine::core;

class Module: public ModuleInterface {
public:
    Module();
    virtual ~Module();

    virtual void build() override;
    virtual TaskObserverInterface& getObserver() const override;

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;

private:
    std::unique_ptr<core::TaskObserverInterface> m_taskObserver;
};

} // namespace input
} // namespace engine
} // namespace nameless

#endif // H7C77C74F_AE5B_4DA9_BC50_67C10AA025FA
