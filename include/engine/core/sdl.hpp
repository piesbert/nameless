/* File:    sdl.hpp
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

#ifndef H16B1E272_B530_40FF_9734_D8FC161F9615
#define H16B1E272_B530_40FF_9734_D8FC161F9615

#include "engine/core/interface/sdl.hpp"

namespace nameless {
namespace engine {
namespace core {

class Sdl: public interface::Sdl {
public:
    Sdl();
    virtual ~Sdl();

    static interface::Sdl& call();

    inline virtual int SDL_Init(Uint32 flags) const override final;
    inline virtual void SDL_Quit() const override final;

    inline virtual const char* SDL_GetError() const override final;
    inline virtual SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const override final;

    inline virtual int SDL_PollEvent(SDL_Event* event) const override final;

    inline virtual int SDL_GL_SetAttribute(SDL_GLattr attr, int value) const override final;
    inline virtual SDL_GLContext SDL_GL_CreateContext(SDL_Window* window) const override final;
    inline virtual int SDL_GL_MakeCurrent(SDL_Window* window, SDL_GLContext context) const override final;
    inline virtual void SDL_GL_DeleteContext(SDL_GLContext context) const override final;
    inline virtual void SDL_GL_SwapWindow(SDL_Window* window) const override final;

    Sdl(const Sdl&) = delete;
    Sdl& operator=(const Sdl&) = delete;
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H16B1E272_B530_40FF_9734_D8FC161F9615
