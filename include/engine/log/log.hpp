/* File:    log.hpp
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

#ifndef H9AC1F634_071C_4612_87FD_314AA9210281
#define H9AC1F634_071C_4612_87FD_314AA9210281

#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include <string.h>

#define LOGLUA(MSG) LOGGEN(MSG, nameless::log::Log::Type::LUA)                  
#define LOGNIL(MSG) LOGGEN(MSG, nameless::log::Log::Type::NIL)                  
                                                                                
#define LOGERR(MSG) LOGGEN(MSG, nameless::log::Log::Type::ERR)                  
#define LOGWRN(MSG) LOGGEN(MSG, nameless::log::Log::Type::WRN)                  
#define LOGINF(MSG) LOGGEN(MSG, nameless::log::Log::Type::INF)

#define SHORT_FILE_NAME(FILE) (strrchr(FILE, '/') ? strrchr(FILE, '/') + 1 : FILE)

#define LOGGEN(L_MSG, L_TYPE) nameless::log::Log::instance() \
        << L_TYPE \
        << std::chrono::system_clock::now() \
        << SHORT_FILE_NAME(__FILE__) \
        << nameless::log::Log::Mod::LINE << __LINE__ \
        << L_MSG << std::endl;

namespace nameless {
namespace log {

class Log {
public:
    virtual ~Log();
    static Log& instance();

    enum class Type : int {
        ERR,
        WRN,
        INF,
        LUA,
        NIL,
        MAX
    };

    enum class Mod : char {
        NORMAL,
        LINE
    };

    friend Log& operator<<(Log& log, const Type type);
    friend Log& operator<<(Log& log, const Mod mod);
    friend Log& operator<<(Log& log, const int value);
    friend Log& operator<<(Log& log, const std::string& message);
    friend Log& operator<<(Log& log, std::ostream& (*f)(std::ostream&));
    friend Log& operator<<(Log& log, const std::chrono::system_clock::time_point& time);

private:
    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

    Log();

    std::string   m_type[(int)Type::MAX];
    std::ofstream m_file;

    unsigned int m_errCnt;
    unsigned int m_wrnCnt;

    Mod m_mod;

    void initTypeTable();
    void initStream();
};

} // namespace log
} // namespace nameless

#endif // H9AC1F634_071C_4612_87FD_314AA9210281
