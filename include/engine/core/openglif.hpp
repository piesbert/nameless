/* File:    openglif.hpp
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

#ifndef HBB00EA77_2E82_42A4_9ABD_04FCE860A237
#define HBB00EA77_2E82_42A4_9ABD_04FCE860A237

//#define GLEW_STATIC                                                             
#include <GL/glew.h>
#include <GL/gl.h>                                                              
#include <GL/glu.h>

namespace nameless {
namespace engine {
namespace core {

class OpenGlIF {
public:
    virtual ~OpenGlIF() {};

    virtual GLenum glewInit() const = 0;
    virtual void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) const = 0;
    virtual void glClear(GLbitfield mask) const = 0;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // HBB00EA77_2E82_42A4_9ABD_04FCE860A237
