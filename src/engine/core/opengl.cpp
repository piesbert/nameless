/* File:    opengl.cpp
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

#include "engine/core/opengl.hpp"

#define GLEW_STATIC                                                             
#include <GL/glew.h>                                                            

namespace nameless {
namespace engine {
namespace core {

OpenGl::OpenGl() {
}

OpenGl::~OpenGl() {
}

OpenGlIF& OpenGl::call() {
    static OpenGl openGlInstance;
    return openGlInstance;
}

inline GLenum OpenGl::glewInit() const {
    return ::glewInit();
}

inline void OpenGl::glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) const {
    ::glClearColor(red, green, blue, alpha);
}

inline void OpenGl::glClear(GLbitfield mask) const {
    ::glClear(mask);
}

} // namespace core
} // namespace engine
} // namespace nameless