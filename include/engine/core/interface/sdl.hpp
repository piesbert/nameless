/* File:    interface/sdl.hpp
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

#ifndef HB346FAC5_25BF_451E_AD9D_68F5B836036D
#define HB346FAC5_25BF_451E_AD9D_68F5B836036D

#include <SDL.h>

namespace nameless {
namespace engine {
namespace core {
namespace interface {

class Sdl {
public:
    virtual ~Sdl() {};

    virtual int SDL_Init(Uint32 flags) const = 0;
    virtual void SDL_Quit() const = 0;

    virtual const char* SDL_GetError() const = 0;
    virtual SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const = 0;

    virtual int SDL_PollEvent(SDL_Event* event) const = 0;

    virtual int SDL_GL_SetAttribute(SDL_GLattr attr, int value) const = 0;
    virtual SDL_GLContext SDL_GL_CreateContext(SDL_Window* window) const = 0;
    virtual int SDL_GL_MakeCurrent(SDL_Window* window, SDL_GLContext context) const = 0;
    virtual void SDL_GL_DeleteContext(SDL_GLContext context) const = 0;
    virtual void SDL_GL_SwapWindow(SDL_Window* window) const = 0;
};

} // namespace interface
} // namespace core
} // namespace engine
} // namespace nameless

#endif // HB346FAC5_25BF_451E_AD9D_68F5B836036D
