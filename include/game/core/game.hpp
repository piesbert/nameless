/* File:    game.hpp
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

#ifndef H8FECAF4D_FF7C_41C5_A308_AE4913111C61
#define H8FECAF4D_FF7C_41C5_A308_AE4913111C61

#include "engine/api/game.hpp"

namespace nameless {
namespace game {
namespace core {

class Game: public engine::api::Game {
public:
    Game();
    virtual ~Game();

    virtual bool onStart() override;
    virtual void onStop() override;

    virtual void setInputApi(engine::api::Input* input) override;

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

private:
    engine::api::Input* m_input;
};

} // namespace core
} // namespace game
} // namespace nameless

#endif // H8FECAF4D_FF7C_41C5_A308_AE4913111C61
