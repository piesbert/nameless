/* File:    sdl.cpp
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

#include "engine/core/sdl.hpp"

namespace nameless {
namespace engine {
namespace core {

Sdl::Sdl() {
}

Sdl::~Sdl() {
}

SdlIF& Sdl::call() {
    static Sdl sdlInstance;
    return sdlInstance;
}

inline int Sdl::SDL_Init(Uint32 flags) const {
    return ::SDL_Init(flags);
}

inline void Sdl::SDL_Quit() const {
    ::SDL_Quit();
}

inline const char* Sdl::SDL_GetError() const {
    return ::SDL_GetError();
}

inline SDL_Window* Sdl::SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const {
    return ::SDL_CreateWindow(title, x, y, w, h, flags);
}

inline int Sdl::SDL_GL_SetAttribute(SDL_GLattr attr, int value) const {
    return ::SDL_GL_SetAttribute(attr, value);
}

inline SDL_GLContext Sdl::SDL_GL_CreateContext(SDL_Window* window) const {
    return ::SDL_GL_CreateContext(window);
}

inline int Sdl::SDL_GL_MakeCurrent(SDL_Window* window, SDL_GLContext context) const {
    return ::SDL_GL_MakeCurrent(window, context);
}

inline void Sdl::SDL_GL_DeleteContext(SDL_GLContext context) const {
    ::SDL_GL_DeleteContext(context);
}

inline void Sdl::SDL_GL_SwapWindow(SDL_Window* window) const {
    ::SDL_GL_SwapWindow(window);
}

} // namespace core
} // namespace engine
} // namespace nameless
