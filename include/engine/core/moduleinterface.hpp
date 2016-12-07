/* File:    moduleinterface.hpp
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

#ifndef H5607D8B1_D34D_4197_B77A_0346C9D4EC4D
#define H5607D8B1_D34D_4197_B77A_0346C9D4EC4D

namespace nameless {
namespace engine {
namespace core {

class TaskObserverInterface;

class ModuleInterface {
public:
    virtual ~ModuleInterface() {};

    virtual void build() = 0;
    virtual TaskObserverInterface& getObserver() const = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H5607D8B1_D34D_4197_B77A_0346C9D4EC4D
