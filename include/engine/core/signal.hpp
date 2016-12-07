/* File:    signal.hpp
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

#ifndef H83B3828A_93DA_4049_83AD_FBB4F94637DC
#define H83B3828A_93DA_4049_83AD_FBB4F94637DC

#include "engine/core/signalinterface.hpp"
#include "engine/core/kernelinterface.hpp"

namespace nameless {
namespace engine {
namespace core {

class Signal: public SignalInterface {
public:
    Signal(KernelInterface& kernel);
    virtual ~Signal();

    virtual void send(Id id) const;

    Signal(const Signal&) = delete;
    Signal& operator=(const Signal&) = delete;

private:
    KernelInterface& m_kernel;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H83B3828A_93DA_4049_83AD_FBB4F94637DC
