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

#include "engine/log/log.hpp"
#include "version.hpp"

namespace nameless {
namespace engine {
namespace core {

Media::Media(interface::Sdl& sdl, interface::OpenGl& openGl)
: m_sdl(sdl),
  m_openGl(openGl),
  m_window {nullptr},
  m_glContext {0} {
}

Media::~Media() {
    if (m_glContext) {
        LOGINF("Removing OpenGL context.");
        m_sdl.SDL_GL_DeleteContext(m_glContext);
    }

    m_sdl.SDL_Quit();
}

bool Media::init() {
    bool retval {true};

    if (m_sdl.SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        LOGERR(m_sdl.SDL_GetError());
        retval = false;
    }

    if (retval) {
        setGlAttributes();
        createWindow();

        if (m_window != nullptr) {
            LOGINF("Creating OpenGL context.");
            m_glContext = m_sdl.SDL_GL_CreateContext(m_window);
            m_sdl.SDL_GL_MakeCurrent(m_window, m_glContext);
        }
    }

    if (m_glContext == 0) {
        LOGERR(m_sdl.SDL_GetError());
        retval = false;
    }
    else {
        glewExperimental = GL_TRUE;
        m_openGl.glewInit();

        m_openGl.glClearColor(0.0, 0.0, 0.0, 1.0);
        m_openGl.glClear(GL_COLOR_BUFFER_BIT);
        m_sdl.SDL_GL_SwapWindow(m_window);
    }

    return retval;
}

void Media::setGlAttributes() const {
    m_sdl.SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    m_sdl.SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    m_sdl.SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    m_sdl.SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void Media::createWindow() {
    m_window = m_sdl.SDL_CreateWindow(
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
