/* File:    log.cpp
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

#include "engine/log/log.hpp"
#include "version.hpp"

namespace nameless {
namespace log {

Log::Log()
: m_file {},
  m_errCnt {},
  m_wrnCnt {},
  m_mod {Mod::NORMAL} {
        initTypeTable();
        initStream();
}

Log::~Log() {
    m_file << std::endl;

    m_file << m_wrnCnt << ((1 == m_wrnCnt) ? " warning." : " warnings.") << std::endl;
    m_file << m_errCnt << ((1 == m_errCnt) ? " error." : " errors.") << std::endl;

    m_file.close();
}

Log& Log::instance() {
    static Log instance;
    return instance;
}

Log& operator<<(Log& log, const Log::Type type) {
    log.m_file << log.m_type[(int)type] << " ";

    if (type == Log::Type::ERR) {
        log.m_errCnt++;
    }
    else if (type == Log::Type::WRN) {
        log.m_wrnCnt++;
    }

    return log;
}

Log& operator<<(Log& log, const Log::Mod mod) {
    log.m_mod = mod;
    return log;
}

Log& operator<<(Log& log, const int value) {
    if (log.m_mod == Log::Mod::LINE) {
        log.m_file << "(" << value << "): ";
        log.m_mod = Log::Mod::NORMAL;
    }
    else {
        log.m_file << value;
    }

    return log;
}

Log& operator<<(Log& log, const std::string& message) {
    log.m_file << message;
    return log;
}

Log& operator<<(Log& log, std::ostream& (*f)(std::ostream&)) {
    f(log.m_file);
    return log;
}

Log& operator<<(Log& log, const std::chrono::system_clock::time_point& time) {
    auto duration = time.time_since_epoch();
    log.m_file
        << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
        << " ";
    return log;
}

void Log::initTypeTable() {
    m_type[(int)Type::ERR] = "ERR";
    m_type[(int)Type::WRN] = "WRN";
    m_type[(int)Type::INF] = "INF";
    m_type[(int)Type::LUA] = "LUA";
    m_type[(int)Type::NIL] = "NIL";
}

void Log::initStream() {
    m_file.open("nameless.log");
    m_file
        << nameless::Version::getName() << " v"
        << nameless::Version::getString()
        << std::endl << std::endl;
}

} // namespace log
} // namespace nameless
