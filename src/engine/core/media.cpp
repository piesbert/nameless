/* File:    media.cpp
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

#include "engine/core/media.hpp"

#include "engine/core/sdl.hpp"
#include "engine/core/opengl.hpp"
#include "engine/log/log.hpp"
#include "version.hpp"

namespace nameless {
namespace engine {
namespace core {

Media::Media()
: m_window {nullptr},
  m_glContext {0} {
}

Media::~Media() {
    if (m_glContext) {
        LOGINF("Removing OpenGL context.");
        Sdl::call().SDL_GL_DeleteContext(m_glContext);
    }

    Sdl::call().SDL_Quit();
}

bool Media::init() {
    bool retval {true};

    if (Sdl::call().SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        LOGERR(Sdl::call().SDL_GetError());
        retval = false;
    }

    if (retval) {
        setGlAttributes();
        createWindow();

        if (m_window != nullptr) {
            LOGINF("Creating OpenGL context.");
            m_glContext = Sdl::call().SDL_GL_CreateContext(m_window);
            Sdl::call().SDL_GL_MakeCurrent(m_window, m_glContext);
        }
    }

    if (m_glContext == 0) {
        LOGERR(Sdl::call().SDL_GetError());
        retval = false;
    }
    else {
        glewExperimental = GL_TRUE;
        OpenGl::call().glewInit();

        OpenGl::call().glClearColor(0.0, 0.0, 0.0, 1.0);
        OpenGl::call().glClear(GL_COLOR_BUFFER_BIT);
        Sdl::call().SDL_GL_SwapWindow(m_window);
    }

    return retval;
}

void Media::setGlAttributes() const {
    Sdl::call().SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    Sdl::call().SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    Sdl::call().SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    Sdl::call().SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void Media::createWindow() {
    m_window = Sdl::call().SDL_CreateWindow(
            nameless::Version::getName().c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            600,
            SDL_WINDOW_OPENGL);
}

} // namespace core
} // namespace engine
} // namespace nameless
