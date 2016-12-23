/* File:    media.hpp
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

#ifndef H57EE9E60_7546_4F85_9C99_9B7E010B1F4B
#define H57EE9E60_7546_4F85_9C99_9B7E010B1F4B

#include "engine/core/interface/media.hpp"

#include "engine/core/interface/sdl.hpp"
#include "engine/core/interface/opengl.hpp"

#include <SDL.h>

namespace nameless {
namespace engine {
namespace core {

class Media: public interface::Media {
public:
    Media(interface::Sdl& sdl, interface::OpenGl& openGl);
    virtual ~Media();

    virtual bool init() override;

    Media(const Media&) = delete;
    Media& operator=(const Media&) = delete;
    
private:
    interface::Sdl& m_sdl;
    interface::OpenGl& m_openGl;

    SDL_Window *m_window;
    SDL_GLContext m_glContext;

    void setGlAttributes() const;
    void createWindow();
};

} // namespace core
} // namespace engine
} // namespace nameless

#endif // H57EE9E60_7546_4F85_9C99_9B7E010B1F4B
