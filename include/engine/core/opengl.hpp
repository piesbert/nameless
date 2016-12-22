/* File:    opengl.hpp
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

#ifndef HEBEDD1AA_BB63_41E0_BFDB_2B6280748EA0
#define HEBEDD1AA_BB63_41E0_BFDB_2B6280748EA0

#include "engine/core/interface/opengl.hpp"

namespace nameless {
namespace engine {
namespace core {

class OpenGl: public interface::OpenGl {
public:
    OpenGl();
    virtual ~OpenGl();

    static interface::OpenGl& call();

    inline virtual GLenum glewInit() const override final;
    inline virtual void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) const override final;
    inline virtual void glClear(GLbitfield mask) const override final;

    OpenGl(const OpenGl&) = delete;
    OpenGl& operator=(const OpenGl&) = delete;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // HEBEDD1AA_BB63_41E0_BFDB_2B6280748EA0
