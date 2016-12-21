/* File:    gameif.hpp
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

#ifndef H745FAE1F_9B8D_4E90_92D4_CFCD01A57402
#define H745FAE1F_9B8D_4E90_92D4_CFCD01A57402

#include "engine/api/input.hpp"

namespace nameless {
namespace engine {
namespace api {

class Game {
public:
    virtual ~Game() {};

    virtual bool onStart() = 0;
    virtual void onStop() = 0;

    virtual void setInputApi(Input* input) = 0;
};

} // namespace api
} // namespace engine
} // namespace nameless

#endif // H745FAE1F_9B8D_4E90_92D4_CFCD01A57402
