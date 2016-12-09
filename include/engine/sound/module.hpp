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

#ifndef HA302BBA9_EAAC_4900_B4A3_3095EFD2BFC4
#define HA302BBA9_EAAC_4900_B4A3_3095EFD2BFC4

#include "engine/core/moduleif.hpp"

#include "engine/core/signalif.hpp"

#include <memory>

namespace nameless {
namespace engine {
namespace sound {

class Module: public core::ModuleIF {
public:
    Module(core::SignalIF& signal);
    virtual ~Module();

    virtual void build() override;
    virtual core::TaskObserverIF* getObserver() const override;

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;

private:
    core::SignalIF& m_signal;

    std::unique_ptr<core::TaskObserverIF> m_taskObserver;
};

} // namespace sound
} // namespace engine
} // namespace nameless

#endif // HA302BBA9_EAAC_4900_B4A3_3095EFD2BFC4
