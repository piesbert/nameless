/* File:    command.hpp
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

#ifndef H34E73453_FFDB_4531_851F_5F9ABDBC4C4F
#define H34E73453_FFDB_4531_851F_5F9ABDBC4C4F

#include <string>

namespace nameless {
namespace engine {
namespace api {

class Command {
public:
    virtual ~Command() {};

    enum Message: int;

    virtual void execute(Message message) = 0;

    virtual void setName(const std::string& name) = 0;
    virtual const std::string& getName() = 0;

    enum Message: int {
        PRESSED,
        RELEASED
    };
};

} // namespace api
} // namespace engine
} // namespace nameless

#endif // H34E73453_FFDB_4531_851F_5F9ABDBC4C4F
