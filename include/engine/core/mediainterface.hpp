/* File:    mediainterface.hpp
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

#ifndef H2E3CDD9E_F7A7_4134_BB44_38621450DD3F
#define H2E3CDD9E_F7A7_4134_BB44_38621450DD3F

namespace nameless {
namespace engine {
namespace core {

class MediaInterface {
public:
    virtual ~MediaInterface() {};

    virtual bool init() = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H2E3CDD9E_F7A7_4134_BB44_38621450DD3F
