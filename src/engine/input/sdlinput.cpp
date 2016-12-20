/* File:    sdlinput.cpp
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

#include "engine/input/sdlinput.hpp"

#include "engine/core/sdl.hpp"
#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace input {

SdlInput::SdlInput(core::SignalIF& signal, CommanderIF& commander)
: m_signal {signal},
  m_commander {commander} {
    // Keyboard
    m_trTable[SDL_SCANCODE_UNKNOWN] = KEY_UNKNOWN;
    m_trTable[SDL_SCANCODE_A] = KEY_A;
    m_trTable[SDL_SCANCODE_B] = KEY_B;
    m_trTable[SDL_SCANCODE_C] = KEY_C;
    m_trTable[SDL_SCANCODE_D] = KEY_D;
    m_trTable[SDL_SCANCODE_E] = KEY_E;
    m_trTable[SDL_SCANCODE_F] = KEY_F;
    m_trTable[SDL_SCANCODE_G] = KEY_G;
    m_trTable[SDL_SCANCODE_H] = KEY_H;
    m_trTable[SDL_SCANCODE_I] = KEY_I;
    m_trTable[SDL_SCANCODE_J] = KEY_J;
    m_trTable[SDL_SCANCODE_K] = KEY_K;
    m_trTable[SDL_SCANCODE_L] = KEY_L;
    m_trTable[SDL_SCANCODE_M] = KEY_M;
    m_trTable[SDL_SCANCODE_N] = KEY_N;
    m_trTable[SDL_SCANCODE_O] = KEY_O;
    m_trTable[SDL_SCANCODE_P] = KEY_P;
    m_trTable[SDL_SCANCODE_Q] = KEY_Q;
    m_trTable[SDL_SCANCODE_R] = KEY_R;
    m_trTable[SDL_SCANCODE_S] = KEY_S;
    m_trTable[SDL_SCANCODE_T] = KEY_T;
    m_trTable[SDL_SCANCODE_U] = KEY_U;
    m_trTable[SDL_SCANCODE_V] = KEY_V;
    m_trTable[SDL_SCANCODE_W] = KEY_W;
    m_trTable[SDL_SCANCODE_X] = KEY_X;
    m_trTable[SDL_SCANCODE_Y] = KEY_Y;
    m_trTable[SDL_SCANCODE_Z] = KEY_Z;
    m_trTable[SDL_SCANCODE_1] = KEY_1;
    m_trTable[SDL_SCANCODE_2] = KEY_2;
    m_trTable[SDL_SCANCODE_3] = KEY_3;
    m_trTable[SDL_SCANCODE_4] = KEY_4;
    m_trTable[SDL_SCANCODE_5] = KEY_5;
    m_trTable[SDL_SCANCODE_6] = KEY_6;
    m_trTable[SDL_SCANCODE_7] = KEY_7;
    m_trTable[SDL_SCANCODE_8] = KEY_8;
    m_trTable[SDL_SCANCODE_9] = KEY_9;
    m_trTable[SDL_SCANCODE_0] = KEY_0;
    m_trTable[SDL_SCANCODE_RETURN] = KEY_RETURN;
    m_trTable[SDL_SCANCODE_ESCAPE] = KEY_ESCAPE;
    m_trTable[SDL_SCANCODE_BACKSPACE] = KEY_BACKSPACE;
    m_trTable[SDL_SCANCODE_TAB] = KEY_TAB;
    m_trTable[SDL_SCANCODE_SPACE] = KEY_SPACE;
    m_trTable[SDL_SCANCODE_MINUS] = KEY_MINUS;
    m_trTable[SDL_SCANCODE_EQUALS] = KEY_EQUALS;
    m_trTable[SDL_SCANCODE_LEFTBRACKET] = KEY_LEFTBRACKET;
    m_trTable[SDL_SCANCODE_RIGHTBRACKET] = KEY_RIGHTBRACKET;
    m_trTable[SDL_SCANCODE_BACKSLASH] = KEY_BACKSLASH;
    m_trTable[SDL_SCANCODE_NONUSHASH] = KEY_NONUSHASH;
    m_trTable[SDL_SCANCODE_SEMICOLON] = KEY_SEMICOLON;
    m_trTable[SDL_SCANCODE_APOSTROPHE] = KEY_APOSTROPHE;
    m_trTable[SDL_SCANCODE_GRAVE] = KEY_GRAVE;
    m_trTable[SDL_SCANCODE_COMMA] = KEY_COMMA;
    m_trTable[SDL_SCANCODE_PERIOD] = KEY_PERIOD;
    m_trTable[SDL_SCANCODE_SLASH] = KEY_SLASH;
    m_trTable[SDL_SCANCODE_CAPSLOCK] = KEY_CAPSLOCK;
    m_trTable[SDL_SCANCODE_F1] = KEY_F1;
    m_trTable[SDL_SCANCODE_F2] = KEY_F2;
    m_trTable[SDL_SCANCODE_F3] = KEY_F3;
    m_trTable[SDL_SCANCODE_F4] = KEY_F4;
    m_trTable[SDL_SCANCODE_F5] = KEY_F5;
    m_trTable[SDL_SCANCODE_F6] = KEY_F6;
    m_trTable[SDL_SCANCODE_F7] = KEY_F7;
    m_trTable[SDL_SCANCODE_F8] = KEY_F8;
    m_trTable[SDL_SCANCODE_F9] = KEY_F9;
    m_trTable[SDL_SCANCODE_F10] = KEY_F10;
    m_trTable[SDL_SCANCODE_F11] = KEY_F11;
    m_trTable[SDL_SCANCODE_F12] = KEY_F12;
    m_trTable[SDL_SCANCODE_PRINTSCREEN] = KEY_PRINTSCREEN;
    m_trTable[SDL_SCANCODE_SCROLLLOCK] = KEY_SCROLLLOCK;
    m_trTable[SDL_SCANCODE_PAUSE] = KEY_PAUSE;
    m_trTable[SDL_SCANCODE_INSERT] = KEY_INSERT;
    m_trTable[SDL_SCANCODE_HOME] = KEY_HOME;
    m_trTable[SDL_SCANCODE_PAGEUP] = KEY_PAGEUP;
    m_trTable[SDL_SCANCODE_DELETE] = KEY_DELETE;
    m_trTable[SDL_SCANCODE_END] = KEY_END;
    m_trTable[SDL_SCANCODE_PAGEDOWN] = KEY_PAGEDOWN;
    m_trTable[SDL_SCANCODE_RIGHT] = KEY_RIGHT;
    m_trTable[SDL_SCANCODE_LEFT] = KEY_LEFT;
    m_trTable[SDL_SCANCODE_DOWN] = KEY_DOWN;
    m_trTable[SDL_SCANCODE_UP] = KEY_UP;
    m_trTable[SDL_SCANCODE_NUMLOCKCLEAR] = KEY_NUMLOCKCLEAR;
    m_trTable[SDL_SCANCODE_KP_DIVIDE] = KEY_KP_DIVIDE;
    m_trTable[SDL_SCANCODE_KP_MULTIPLY] = KEY_KP_MULTIPLY;
    m_trTable[SDL_SCANCODE_KP_MINUS] = KEY_KP_MINUS;
    m_trTable[SDL_SCANCODE_KP_PLUS] = KEY_KP_PLUS;
    m_trTable[SDL_SCANCODE_KP_ENTER] = KEY_KP_ENTER;
    m_trTable[SDL_SCANCODE_KP_1] = KEY_KP_1;
    m_trTable[SDL_SCANCODE_KP_2] = KEY_KP_2;
    m_trTable[SDL_SCANCODE_KP_3] = KEY_KP_3;
    m_trTable[SDL_SCANCODE_KP_4] = KEY_KP_4;
    m_trTable[SDL_SCANCODE_KP_5] = KEY_KP_5;
    m_trTable[SDL_SCANCODE_KP_6] = KEY_KP_6;
    m_trTable[SDL_SCANCODE_KP_7] = KEY_KP_7;
    m_trTable[SDL_SCANCODE_KP_8] = KEY_KP_8;
    m_trTable[SDL_SCANCODE_KP_9] = KEY_KP_9;
    m_trTable[SDL_SCANCODE_KP_0] = KEY_KP_0;
    m_trTable[SDL_SCANCODE_KP_PERIOD] = KEY_KP_PERIOD;
    m_trTable[SDL_SCANCODE_NONUSBACKSLASH] = KEY_NONUSBACKSLASH;
    m_trTable[SDL_SCANCODE_APPLICATION] = KEY_APPLICATION;
    m_trTable[SDL_SCANCODE_POWER] = KEY_POWER;
    m_trTable[SDL_SCANCODE_KP_EQUALS] = KEY_KP_EQUALS;
    m_trTable[SDL_SCANCODE_F13] = KEY_F13;
    m_trTable[SDL_SCANCODE_F14] = KEY_F14;
    m_trTable[SDL_SCANCODE_F15] = KEY_F15;
    m_trTable[SDL_SCANCODE_F16] = KEY_F16;
    m_trTable[SDL_SCANCODE_F17] = KEY_F17;
    m_trTable[SDL_SCANCODE_F18] = KEY_F18;
    m_trTable[SDL_SCANCODE_F19] = KEY_F19;
    m_trTable[SDL_SCANCODE_F20] = KEY_F20;
    m_trTable[SDL_SCANCODE_F21] = KEY_F21;
    m_trTable[SDL_SCANCODE_F22] = KEY_F22;
    m_trTable[SDL_SCANCODE_F23] = KEY_F23;
    m_trTable[SDL_SCANCODE_F24] = KEY_F24;
    m_trTable[SDL_SCANCODE_EXECUTE] = KEY_EXECUTE;
    m_trTable[SDL_SCANCODE_HELP] = KEY_HELP;
    m_trTable[SDL_SCANCODE_MENU] = KEY_MENU;
    m_trTable[SDL_SCANCODE_SELECT] = KEY_SELECT;
    m_trTable[SDL_SCANCODE_STOP] = KEY_STOP;
    m_trTable[SDL_SCANCODE_AGAIN] = KEY_AGAIN;
    m_trTable[SDL_SCANCODE_UNDO] = KEY_UNDO;
    m_trTable[SDL_SCANCODE_CUT] = KEY_CUT;
    m_trTable[SDL_SCANCODE_COPY] = KEY_COPY;
    m_trTable[SDL_SCANCODE_PASTE] = KEY_PASTE;
    m_trTable[SDL_SCANCODE_FIND] = KEY_FIND;
    m_trTable[SDL_SCANCODE_MUTE] = KEY_MUTE;
    m_trTable[SDL_SCANCODE_VOLUMEUP] = KEY_VOLUMEUP;
    m_trTable[SDL_SCANCODE_VOLUMEDOWN] = KEY_VOLUMEDOWN;
    m_trTable[SDL_SCANCODE_KP_COMMA] = KEY_KP_COMMA;
    m_trTable[SDL_SCANCODE_KP_EQUALSAS400] = KEY_KP_EQUALSAS400;
    m_trTable[SDL_SCANCODE_INTERNATIONAL1] = KEY_INTERNATIONAL1;
    m_trTable[SDL_SCANCODE_INTERNATIONAL2] = KEY_INTERNATIONAL2;
    m_trTable[SDL_SCANCODE_INTERNATIONAL3] = KEY_INTERNATIONAL3;
    m_trTable[SDL_SCANCODE_INTERNATIONAL4] = KEY_INTERNATIONAL4;
    m_trTable[SDL_SCANCODE_INTERNATIONAL5] = KEY_INTERNATIONAL5;
    m_trTable[SDL_SCANCODE_INTERNATIONAL6] = KEY_INTERNATIONAL6;
    m_trTable[SDL_SCANCODE_INTERNATIONAL7] = KEY_INTERNATIONAL7;
    m_trTable[SDL_SCANCODE_INTERNATIONAL8] = KEY_INTERNATIONAL8;
    m_trTable[SDL_SCANCODE_INTERNATIONAL9] = KEY_INTERNATIONAL9;
    m_trTable[SDL_SCANCODE_LANG1] = KEY_LANG1;
    m_trTable[SDL_SCANCODE_LANG2] = KEY_LANG2;
    m_trTable[SDL_SCANCODE_LANG3] = KEY_LANG3;
    m_trTable[SDL_SCANCODE_LANG4] = KEY_LANG4;
    m_trTable[SDL_SCANCODE_LANG5] = KEY_LANG5;
    m_trTable[SDL_SCANCODE_LANG6] = KEY_LANG6;
    m_trTable[SDL_SCANCODE_LANG7] = KEY_LANG7;
    m_trTable[SDL_SCANCODE_LANG8] = KEY_LANG8;
    m_trTable[SDL_SCANCODE_LANG9] = KEY_LANG9;
    m_trTable[SDL_SCANCODE_ALTERASE] = KEY_ALTERASE;
    m_trTable[SDL_SCANCODE_SYSREQ] = KEY_SYSREQ;
    m_trTable[SDL_SCANCODE_CANCEL] = KEY_CANCEL;
    m_trTable[SDL_SCANCODE_CLEAR] = KEY_CLEAR;
    m_trTable[SDL_SCANCODE_PRIOR] = KEY_PRIOR;
    m_trTable[SDL_SCANCODE_RETURN2] = KEY_RETURN2;
    m_trTable[SDL_SCANCODE_SEPARATOR] = KEY_SEPARATOR;
    m_trTable[SDL_SCANCODE_OUT] = KEY_OUT;
    m_trTable[SDL_SCANCODE_OPER] = KEY_OPER;
    m_trTable[SDL_SCANCODE_CLEARAGAIN] = KEY_CLEARAGAIN;
    m_trTable[SDL_SCANCODE_CRSEL] = KEY_CRSEL;
    m_trTable[SDL_SCANCODE_EXSEL] = KEY_EXSEL;
    m_trTable[SDL_SCANCODE_KP_00] = KEY_KP_00;
    m_trTable[SDL_SCANCODE_KP_000] = KEY_KP_000;
    m_trTable[SDL_SCANCODE_THOUSANDSSEPARATOR] = KEY_THOUSANDSSEPARATOR;
    m_trTable[SDL_SCANCODE_DECIMALSEPARATOR] = KEY_DECIMALSEPARATOR;
    m_trTable[SDL_SCANCODE_CURRENCYUNIT] = KEY_CURRENCYUNIT;
    m_trTable[SDL_SCANCODE_CURRENCYSUBUNIT] = KEY_CURRENCYSUBUNIT;
    m_trTable[SDL_SCANCODE_KP_LEFTPAREN] = KEY_KP_LEFTPAREN;
    m_trTable[SDL_SCANCODE_KP_RIGHTPAREN] = KEY_KP_RIGHTPAREN;
    m_trTable[SDL_SCANCODE_KP_LEFTBRACE] = KEY_KP_LEFTBRACE;
    m_trTable[SDL_SCANCODE_KP_RIGHTBRACE] = KEY_KP_RIGHTBRACE;
    m_trTable[SDL_SCANCODE_KP_TAB] = KEY_KP_TAB;
    m_trTable[SDL_SCANCODE_KP_BACKSPACE] = KEY_KP_BACKSPACE;
    m_trTable[SDL_SCANCODE_KP_A] = KEY_KP_A;
    m_trTable[SDL_SCANCODE_KP_B] = KEY_KP_B;
    m_trTable[SDL_SCANCODE_KP_C] = KEY_KP_C;
    m_trTable[SDL_SCANCODE_KP_D] = KEY_KP_D;
    m_trTable[SDL_SCANCODE_KP_E] = KEY_KP_E;
    m_trTable[SDL_SCANCODE_KP_F] = KEY_KP_F;
    m_trTable[SDL_SCANCODE_KP_XOR] = KEY_KP_XOR;
    m_trTable[SDL_SCANCODE_KP_POWER] = KEY_KP_POWER;
    m_trTable[SDL_SCANCODE_KP_PERCENT] = KEY_KP_PERCENT;
    m_trTable[SDL_SCANCODE_KP_LESS] = KEY_KP_LESS;
    m_trTable[SDL_SCANCODE_KP_GREATER] = KEY_KP_GREATER;
    m_trTable[SDL_SCANCODE_KP_AMPERSAND] = KEY_KP_AMPERSAND;
    m_trTable[SDL_SCANCODE_KP_DBLAMPERSAND] = KEY_KP_DBLAMPERSAND;
    m_trTable[SDL_SCANCODE_KP_VERTICALBAR] = KEY_KP_VERTICALBAR;
    m_trTable[SDL_SCANCODE_KP_DBLVERTICALBAR] = KEY_KP_DBLVERTICALBAR;
    m_trTable[SDL_SCANCODE_KP_COLON] = KEY_KP_COLON;
    m_trTable[SDL_SCANCODE_KP_HASH] = KEY_KP_HASH;
    m_trTable[SDL_SCANCODE_KP_SPACE] = KEY_KP_SPACE;
    m_trTable[SDL_SCANCODE_KP_AT] = KEY_KP_AT;
    m_trTable[SDL_SCANCODE_KP_EXCLAM] = KEY_KP_EXCLAM;
    m_trTable[SDL_SCANCODE_KP_MEMSTORE] = KEY_KP_MEMSTORE;
    m_trTable[SDL_SCANCODE_KP_MEMRECALL] = KEY_KP_MEMRECALL;
    m_trTable[SDL_SCANCODE_KP_MEMCLEAR] = KEY_KP_MEMCLEAR;
    m_trTable[SDL_SCANCODE_KP_MEMADD] = KEY_KP_MEMADD;
    m_trTable[SDL_SCANCODE_KP_MEMSUBTRACT] = KEY_KP_MEMSUBTRACT;
    m_trTable[SDL_SCANCODE_KP_MEMMULTIPLY] = KEY_KP_MEMMULTIPLY;
    m_trTable[SDL_SCANCODE_KP_MEMDIVIDE] = KEY_KP_MEMDIVIDE;
    m_trTable[SDL_SCANCODE_KP_PLUSMINUS] = KEY_KP_PLUSMINUS;
    m_trTable[SDL_SCANCODE_KP_CLEAR] = KEY_KP_CLEAR;
    m_trTable[SDL_SCANCODE_KP_CLEARENTRY] = KEY_KP_CLEARENTRY;
    m_trTable[SDL_SCANCODE_KP_BINARY] = KEY_KP_BINARY;
    m_trTable[SDL_SCANCODE_KP_OCTAL] = KEY_KP_OCTAL;
    m_trTable[SDL_SCANCODE_KP_DECIMAL] = KEY_KP_DECIMAL;
    m_trTable[SDL_SCANCODE_KP_HEXADECIMAL] = KEY_KP_HEXADECIMAL;
    m_trTable[SDL_SCANCODE_LCTRL] = KEY_LCTRL;
    m_trTable[SDL_SCANCODE_LSHIFT] = KEY_LSHIFT;
    m_trTable[SDL_SCANCODE_LALT] = KEY_LALT;
    m_trTable[SDL_SCANCODE_LGUI] = KEY_LGUI;
    m_trTable[SDL_SCANCODE_RCTRL] = KEY_RCTRL;
    m_trTable[SDL_SCANCODE_RSHIFT] = KEY_RSHIFT;
    m_trTable[SDL_SCANCODE_RALT] = KEY_RALT;
    m_trTable[SDL_SCANCODE_RGUI] = KEY_RGUI;
    m_trTable[SDL_SCANCODE_MODE] = KEY_MODE;
    m_trTable[SDL_SCANCODE_AUDIONEXT] = KEY_AUDIONEXT;
    m_trTable[SDL_SCANCODE_AUDIOPREV] = KEY_AUDIOPREV;
    m_trTable[SDL_SCANCODE_AUDIOSTOP] = KEY_AUDIOSTOP;
    m_trTable[SDL_SCANCODE_AUDIOPLAY] = KEY_AUDIOPLAY;
    m_trTable[SDL_SCANCODE_AUDIOMUTE] = KEY_AUDIOMUTE;
    m_trTable[SDL_SCANCODE_MEDIASELECT] = KEY_MEDIASELECT;
    m_trTable[SDL_SCANCODE_WWW] = KEY_WWW;
    m_trTable[SDL_SCANCODE_MAIL] = KEY_MAIL;
    m_trTable[SDL_SCANCODE_CALCULATOR] = KEY_CALCULATOR;
    m_trTable[SDL_SCANCODE_COMPUTER] = KEY_COMPUTER;
    m_trTable[SDL_SCANCODE_AC_SEARCH] = KEY_AC_SEARCH;
    m_trTable[SDL_SCANCODE_AC_HOME] = KEY_AC_HOME;
    m_trTable[SDL_SCANCODE_AC_BACK] = KEY_AC_BACK;
    m_trTable[SDL_SCANCODE_AC_FORWARD] = KEY_AC_FORWARD;
    m_trTable[SDL_SCANCODE_AC_STOP] = KEY_AC_STOP;
    m_trTable[SDL_SCANCODE_AC_REFRESH] = KEY_AC_REFRESH;
    m_trTable[SDL_SCANCODE_AC_BOOKMARKS] = KEY_AC_BOOKMARKS;
    m_trTable[SDL_SCANCODE_BRIGHTNESSDOWN] = KEY_BRIGHTNESSDOWN;
    m_trTable[SDL_SCANCODE_BRIGHTNESSUP] = KEY_BRIGHTNESSUP;
    m_trTable[SDL_SCANCODE_DISPLAYSWITCH] = KEY_DISPLAYSWITCH;
    m_trTable[SDL_SCANCODE_KBDILLUMTOGGLE] = KEY_KBDILLUMTOGGLE;
    m_trTable[SDL_SCANCODE_KBDILLUMDOWN] = KEY_KBDILLUMDOWN;
    m_trTable[SDL_SCANCODE_KBDILLUMUP] = KEY_KBDILLUMUP;
    m_trTable[SDL_SCANCODE_EJECT] = KEY_EJECT;
    m_trTable[SDL_SCANCODE_SLEEP] = KEY_SLEEP;
    m_trTable[SDL_SCANCODE_APP1] = KEY_APP1;
    m_trTable[SDL_SCANCODE_APP2] = KEY_APP2;

    // Mouse
    m_trTable[SDL_NUM_SCANCODES + 1] = MOUSE_1;
    m_trTable[SDL_NUM_SCANCODES + 2] = MOUSE_2;
    m_trTable[SDL_NUM_SCANCODES + 3] = MOUSE_3;
    m_trTable[SDL_NUM_SCANCODES + 4] = MOUSE_4;
    m_trTable[SDL_NUM_SCANCODES + 5] = MOUSE_5;
    m_trTable[SDL_NUM_SCANCODES + 6] = MOUSE_6;
    m_trTable[SDL_NUM_SCANCODES + 7] = MOUSE_7;
    m_trTable[SDL_NUM_SCANCODES + 8] = MOUSE_8;
    m_trTable[SDL_NUM_SCANCODES + 9] = MOUSE_9;
}

SdlInput::~SdlInput() {
}

int SdlInput::handleEvents() {
    int eventCnt {0};

    while(core::Sdl::call().SDL_PollEvent(&m_event)) {
        eventCnt++;

        switch (m_event.type) {
            case SDL_QUIT:
                m_signal.kill();
                break;
            case SDL_KEYDOWN: // not interested in repeated events
                if (m_event.key.repeat == 0) {
                    handleKey(CommandIF::START);
                }
                break;
            case SDL_KEYUP:
                handleKey(CommandIF::STOP);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleButton(CommandIF::START);
                break;
            case SDL_MOUSEBUTTONUP:
                handleButton(CommandIF::STOP);
                break;
        }
    }

    LOGINF("Input events: " << eventCnt);

    return eventCnt;
}

SdlInput::Button SdlInput::attachCommand(CommandIF* command, SdlInput::Button button) {
    m_commander.attach(command, button);
    return button;
}

SdlInput::Button SdlInput::attachCommand(CommandIF* command) {
    return SdlInput::KEY_UNKNOWN;
}

void SdlInput::handleKey(CommandIF::State state) {
    Button button {KEY_UNKNOWN};
    
    button = m_trTable[m_event.key.keysym.scancode];
    m_commander.execute(button, state);
}

void SdlInput::handleButton(CommandIF::State state) {
    Button button {KEY_UNKNOWN};

    button = m_trTable[SDL_NUM_SCANCODES + m_event.button.button];
    m_commander.execute(button, state);
}



} // namespace input
} // namespace engine
} // namespace nameless
