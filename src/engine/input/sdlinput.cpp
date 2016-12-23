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

#include "engine/log/log.hpp"

namespace nameless {
namespace engine {
namespace input {

SdlInput::SdlInput(core::interface::Signal& signal, core::interface::Sdl& sdl, interface::Commander& commander)
: m_signal {signal},
  m_sdl {sdl},
  m_commander {commander} {
    // Keyboard
    m_trTable[SDL_SCANCODE_UNKNOWN] = api::Input::KEY_UNKNOWN;
    m_trTable[SDL_SCANCODE_A] = api::Input::KEY_A;
    m_trTable[SDL_SCANCODE_B] = api::Input::KEY_B;
    m_trTable[SDL_SCANCODE_C] = api::Input::KEY_C;
    m_trTable[SDL_SCANCODE_D] = api::Input::KEY_D;
    m_trTable[SDL_SCANCODE_E] = api::Input::KEY_E;
    m_trTable[SDL_SCANCODE_F] = api::Input::KEY_F;
    m_trTable[SDL_SCANCODE_G] = api::Input::KEY_G;
    m_trTable[SDL_SCANCODE_H] = api::Input::KEY_H;
    m_trTable[SDL_SCANCODE_I] = api::Input::KEY_I;
    m_trTable[SDL_SCANCODE_J] = api::Input::KEY_J;
    m_trTable[SDL_SCANCODE_K] = api::Input::KEY_K;
    m_trTable[SDL_SCANCODE_L] = api::Input::KEY_L;
    m_trTable[SDL_SCANCODE_M] = api::Input::KEY_M;
    m_trTable[SDL_SCANCODE_N] = api::Input::KEY_N;
    m_trTable[SDL_SCANCODE_O] = api::Input::KEY_O;
    m_trTable[SDL_SCANCODE_P] = api::Input::KEY_P;
    m_trTable[SDL_SCANCODE_Q] = api::Input::KEY_Q;
    m_trTable[SDL_SCANCODE_R] = api::Input::KEY_R;
    m_trTable[SDL_SCANCODE_S] = api::Input::KEY_S;
    m_trTable[SDL_SCANCODE_T] = api::Input::KEY_T;
    m_trTable[SDL_SCANCODE_U] = api::Input::KEY_U;
    m_trTable[SDL_SCANCODE_V] = api::Input::KEY_V;
    m_trTable[SDL_SCANCODE_W] = api::Input::KEY_W;
    m_trTable[SDL_SCANCODE_X] = api::Input::KEY_X;
    m_trTable[SDL_SCANCODE_Y] = api::Input::KEY_Y;
    m_trTable[SDL_SCANCODE_Z] = api::Input::KEY_Z;
    m_trTable[SDL_SCANCODE_1] = api::Input::KEY_1;
    m_trTable[SDL_SCANCODE_2] = api::Input::KEY_2;
    m_trTable[SDL_SCANCODE_3] = api::Input::KEY_3;
    m_trTable[SDL_SCANCODE_4] = api::Input::KEY_4;
    m_trTable[SDL_SCANCODE_5] = api::Input::KEY_5;
    m_trTable[SDL_SCANCODE_6] = api::Input::KEY_6;
    m_trTable[SDL_SCANCODE_7] = api::Input::KEY_7;
    m_trTable[SDL_SCANCODE_8] = api::Input::KEY_8;
    m_trTable[SDL_SCANCODE_9] = api::Input::KEY_9;
    m_trTable[SDL_SCANCODE_0] = api::Input::KEY_0;
    m_trTable[SDL_SCANCODE_RETURN] = api::Input::KEY_RETURN;
    m_trTable[SDL_SCANCODE_ESCAPE] = api::Input::KEY_ESCAPE;
    m_trTable[SDL_SCANCODE_BACKSPACE] = api::Input::KEY_BACKSPACE;
    m_trTable[SDL_SCANCODE_TAB] = api::Input::KEY_TAB;
    m_trTable[SDL_SCANCODE_SPACE] = api::Input::KEY_SPACE;
    m_trTable[SDL_SCANCODE_MINUS] = api::Input::KEY_MINUS;
    m_trTable[SDL_SCANCODE_EQUALS] = api::Input::KEY_EQUALS;
    m_trTable[SDL_SCANCODE_LEFTBRACKET] = api::Input::KEY_LEFTBRACKET;
    m_trTable[SDL_SCANCODE_RIGHTBRACKET] = api::Input::KEY_RIGHTBRACKET;
    m_trTable[SDL_SCANCODE_BACKSLASH] = api::Input::KEY_BACKSLASH;
    m_trTable[SDL_SCANCODE_NONUSHASH] = api::Input::KEY_NONUSHASH;
    m_trTable[SDL_SCANCODE_SEMICOLON] = api::Input::KEY_SEMICOLON;
    m_trTable[SDL_SCANCODE_APOSTROPHE] = api::Input::KEY_APOSTROPHE;
    m_trTable[SDL_SCANCODE_GRAVE] = api::Input::KEY_GRAVE;
    m_trTable[SDL_SCANCODE_COMMA] = api::Input::KEY_COMMA;
    m_trTable[SDL_SCANCODE_PERIOD] = api::Input::KEY_PERIOD;
    m_trTable[SDL_SCANCODE_SLASH] = api::Input::KEY_SLASH;
    m_trTable[SDL_SCANCODE_CAPSLOCK] = api::Input::KEY_CAPSLOCK;
    m_trTable[SDL_SCANCODE_F1] = api::Input::KEY_F1;
    m_trTable[SDL_SCANCODE_F2] = api::Input::KEY_F2;
    m_trTable[SDL_SCANCODE_F3] = api::Input::KEY_F3;
    m_trTable[SDL_SCANCODE_F4] = api::Input::KEY_F4;
    m_trTable[SDL_SCANCODE_F5] = api::Input::KEY_F5;
    m_trTable[SDL_SCANCODE_F6] = api::Input::KEY_F6;
    m_trTable[SDL_SCANCODE_F7] = api::Input::KEY_F7;
    m_trTable[SDL_SCANCODE_F8] = api::Input::KEY_F8;
    m_trTable[SDL_SCANCODE_F9] = api::Input::KEY_F9;
    m_trTable[SDL_SCANCODE_F10] = api::Input::KEY_F10;
    m_trTable[SDL_SCANCODE_F11] = api::Input::KEY_F11;
    m_trTable[SDL_SCANCODE_F12] = api::Input::KEY_F12;
    m_trTable[SDL_SCANCODE_PRINTSCREEN] = api::Input::KEY_PRINTSCREEN;
    m_trTable[SDL_SCANCODE_SCROLLLOCK] = api::Input::KEY_SCROLLLOCK;
    m_trTable[SDL_SCANCODE_PAUSE] = api::Input::KEY_PAUSE;
    m_trTable[SDL_SCANCODE_INSERT] = api::Input::KEY_INSERT;
    m_trTable[SDL_SCANCODE_HOME] = api::Input::KEY_HOME;
    m_trTable[SDL_SCANCODE_PAGEUP] = api::Input::KEY_PAGEUP;
    m_trTable[SDL_SCANCODE_DELETE] = api::Input::KEY_DELETE;
    m_trTable[SDL_SCANCODE_END] = api::Input::KEY_END;
    m_trTable[SDL_SCANCODE_PAGEDOWN] = api::Input::KEY_PAGEDOWN;
    m_trTable[SDL_SCANCODE_RIGHT] = api::Input::KEY_RIGHT;
    m_trTable[SDL_SCANCODE_LEFT] = api::Input::KEY_LEFT;
    m_trTable[SDL_SCANCODE_DOWN] = api::Input::KEY_DOWN;
    m_trTable[SDL_SCANCODE_UP] = api::Input::KEY_UP;
    m_trTable[SDL_SCANCODE_NUMLOCKCLEAR] = api::Input::KEY_NUMLOCKCLEAR;
    m_trTable[SDL_SCANCODE_KP_DIVIDE] = api::Input::KEY_KP_DIVIDE;
    m_trTable[SDL_SCANCODE_KP_MULTIPLY] = api::Input::KEY_KP_MULTIPLY;
    m_trTable[SDL_SCANCODE_KP_MINUS] = api::Input::KEY_KP_MINUS;
    m_trTable[SDL_SCANCODE_KP_PLUS] = api::Input::KEY_KP_PLUS;
    m_trTable[SDL_SCANCODE_KP_ENTER] = api::Input::KEY_KP_ENTER;
    m_trTable[SDL_SCANCODE_KP_1] = api::Input::KEY_KP_1;
    m_trTable[SDL_SCANCODE_KP_2] = api::Input::KEY_KP_2;
    m_trTable[SDL_SCANCODE_KP_3] = api::Input::KEY_KP_3;
    m_trTable[SDL_SCANCODE_KP_4] = api::Input::KEY_KP_4;
    m_trTable[SDL_SCANCODE_KP_5] = api::Input::KEY_KP_5;
    m_trTable[SDL_SCANCODE_KP_6] = api::Input::KEY_KP_6;
    m_trTable[SDL_SCANCODE_KP_7] = api::Input::KEY_KP_7;
    m_trTable[SDL_SCANCODE_KP_8] = api::Input::KEY_KP_8;
    m_trTable[SDL_SCANCODE_KP_9] = api::Input::KEY_KP_9;
    m_trTable[SDL_SCANCODE_KP_0] = api::Input::KEY_KP_0;
    m_trTable[SDL_SCANCODE_KP_PERIOD] = api::Input::KEY_KP_PERIOD;
    m_trTable[SDL_SCANCODE_NONUSBACKSLASH] = api::Input::KEY_NONUSBACKSLASH;
    m_trTable[SDL_SCANCODE_APPLICATION] = api::Input::KEY_APPLICATION;
    m_trTable[SDL_SCANCODE_POWER] = api::Input::KEY_POWER;
    m_trTable[SDL_SCANCODE_KP_EQUALS] = api::Input::KEY_KP_EQUALS;
    m_trTable[SDL_SCANCODE_F13] = api::Input::KEY_F13;
    m_trTable[SDL_SCANCODE_F14] = api::Input::KEY_F14;
    m_trTable[SDL_SCANCODE_F15] = api::Input::KEY_F15;
    m_trTable[SDL_SCANCODE_F16] = api::Input::KEY_F16;
    m_trTable[SDL_SCANCODE_F17] = api::Input::KEY_F17;
    m_trTable[SDL_SCANCODE_F18] = api::Input::KEY_F18;
    m_trTable[SDL_SCANCODE_F19] = api::Input::KEY_F19;
    m_trTable[SDL_SCANCODE_F20] = api::Input::KEY_F20;
    m_trTable[SDL_SCANCODE_F21] = api::Input::KEY_F21;
    m_trTable[SDL_SCANCODE_F22] = api::Input::KEY_F22;
    m_trTable[SDL_SCANCODE_F23] = api::Input::KEY_F23;
    m_trTable[SDL_SCANCODE_F24] = api::Input::KEY_F24;
    m_trTable[SDL_SCANCODE_EXECUTE] = api::Input::KEY_EXECUTE;
    m_trTable[SDL_SCANCODE_HELP] = api::Input::KEY_HELP;
    m_trTable[SDL_SCANCODE_MENU] = api::Input::KEY_MENU;
    m_trTable[SDL_SCANCODE_SELECT] = api::Input::KEY_SELECT;
    m_trTable[SDL_SCANCODE_STOP] = api::Input::KEY_STOP;
    m_trTable[SDL_SCANCODE_AGAIN] = api::Input::KEY_AGAIN;
    m_trTable[SDL_SCANCODE_UNDO] = api::Input::KEY_UNDO;
    m_trTable[SDL_SCANCODE_CUT] = api::Input::KEY_CUT;
    m_trTable[SDL_SCANCODE_COPY] = api::Input::KEY_COPY;
    m_trTable[SDL_SCANCODE_PASTE] = api::Input::KEY_PASTE;
    m_trTable[SDL_SCANCODE_FIND] = api::Input::KEY_FIND;
    m_trTable[SDL_SCANCODE_MUTE] = api::Input::KEY_MUTE;
    m_trTable[SDL_SCANCODE_VOLUMEUP] = api::Input::KEY_VOLUMEUP;
    m_trTable[SDL_SCANCODE_VOLUMEDOWN] = api::Input::KEY_VOLUMEDOWN;
    m_trTable[SDL_SCANCODE_KP_COMMA] = api::Input::KEY_KP_COMMA;
    m_trTable[SDL_SCANCODE_KP_EQUALSAS400] = api::Input::KEY_KP_EQUALSAS400;
    m_trTable[SDL_SCANCODE_INTERNATIONAL1] = api::Input::KEY_INTERNATIONAL1;
    m_trTable[SDL_SCANCODE_INTERNATIONAL2] = api::Input::KEY_INTERNATIONAL2;
    m_trTable[SDL_SCANCODE_INTERNATIONAL3] = api::Input::KEY_INTERNATIONAL3;
    m_trTable[SDL_SCANCODE_INTERNATIONAL4] = api::Input::KEY_INTERNATIONAL4;
    m_trTable[SDL_SCANCODE_INTERNATIONAL5] = api::Input::KEY_INTERNATIONAL5;
    m_trTable[SDL_SCANCODE_INTERNATIONAL6] = api::Input::KEY_INTERNATIONAL6;
    m_trTable[SDL_SCANCODE_INTERNATIONAL7] = api::Input::KEY_INTERNATIONAL7;
    m_trTable[SDL_SCANCODE_INTERNATIONAL8] = api::Input::KEY_INTERNATIONAL8;
    m_trTable[SDL_SCANCODE_INTERNATIONAL9] = api::Input::KEY_INTERNATIONAL9;
    m_trTable[SDL_SCANCODE_LANG1] = api::Input::KEY_LANG1;
    m_trTable[SDL_SCANCODE_LANG2] = api::Input::KEY_LANG2;
    m_trTable[SDL_SCANCODE_LANG3] = api::Input::KEY_LANG3;
    m_trTable[SDL_SCANCODE_LANG4] = api::Input::KEY_LANG4;
    m_trTable[SDL_SCANCODE_LANG5] = api::Input::KEY_LANG5;
    m_trTable[SDL_SCANCODE_LANG6] = api::Input::KEY_LANG6;
    m_trTable[SDL_SCANCODE_LANG7] = api::Input::KEY_LANG7;
    m_trTable[SDL_SCANCODE_LANG8] = api::Input::KEY_LANG8;
    m_trTable[SDL_SCANCODE_LANG9] = api::Input::KEY_LANG9;
    m_trTable[SDL_SCANCODE_ALTERASE] = api::Input::KEY_ALTERASE;
    m_trTable[SDL_SCANCODE_SYSREQ] = api::Input::KEY_SYSREQ;
    m_trTable[SDL_SCANCODE_CANCEL] = api::Input::KEY_CANCEL;
    m_trTable[SDL_SCANCODE_CLEAR] = api::Input::KEY_CLEAR;
    m_trTable[SDL_SCANCODE_PRIOR] = api::Input::KEY_PRIOR;
    m_trTable[SDL_SCANCODE_RETURN2] = api::Input::KEY_RETURN2;
    m_trTable[SDL_SCANCODE_SEPARATOR] = api::Input::KEY_SEPARATOR;
    m_trTable[SDL_SCANCODE_OUT] = api::Input::KEY_OUT;
    m_trTable[SDL_SCANCODE_OPER] = api::Input::KEY_OPER;
    m_trTable[SDL_SCANCODE_CLEARAGAIN] = api::Input::KEY_CLEARAGAIN;
    m_trTable[SDL_SCANCODE_CRSEL] = api::Input::KEY_CRSEL;
    m_trTable[SDL_SCANCODE_EXSEL] = api::Input::KEY_EXSEL;
    m_trTable[SDL_SCANCODE_KP_00] = api::Input::KEY_KP_00;
    m_trTable[SDL_SCANCODE_KP_000] = api::Input::KEY_KP_000;
    m_trTable[SDL_SCANCODE_THOUSANDSSEPARATOR] = api::Input::KEY_THOUSANDSSEPARATOR;
    m_trTable[SDL_SCANCODE_DECIMALSEPARATOR] = api::Input::KEY_DECIMALSEPARATOR;
    m_trTable[SDL_SCANCODE_CURRENCYUNIT] = api::Input::KEY_CURRENCYUNIT;
    m_trTable[SDL_SCANCODE_CURRENCYSUBUNIT] = api::Input::KEY_CURRENCYSUBUNIT;
    m_trTable[SDL_SCANCODE_KP_LEFTPAREN] = api::Input::KEY_KP_LEFTPAREN;
    m_trTable[SDL_SCANCODE_KP_RIGHTPAREN] = api::Input::KEY_KP_RIGHTPAREN;
    m_trTable[SDL_SCANCODE_KP_LEFTBRACE] = api::Input::KEY_KP_LEFTBRACE;
    m_trTable[SDL_SCANCODE_KP_RIGHTBRACE] = api::Input::KEY_KP_RIGHTBRACE;
    m_trTable[SDL_SCANCODE_KP_TAB] = api::Input::KEY_KP_TAB;
    m_trTable[SDL_SCANCODE_KP_BACKSPACE] = api::Input::KEY_KP_BACKSPACE;
    m_trTable[SDL_SCANCODE_KP_A] = api::Input::KEY_KP_A;
    m_trTable[SDL_SCANCODE_KP_B] = api::Input::KEY_KP_B;
    m_trTable[SDL_SCANCODE_KP_C] = api::Input::KEY_KP_C;
    m_trTable[SDL_SCANCODE_KP_D] = api::Input::KEY_KP_D;
    m_trTable[SDL_SCANCODE_KP_E] = api::Input::KEY_KP_E;
    m_trTable[SDL_SCANCODE_KP_F] = api::Input::KEY_KP_F;
    m_trTable[SDL_SCANCODE_KP_XOR] = api::Input::KEY_KP_XOR;
    m_trTable[SDL_SCANCODE_KP_POWER] = api::Input::KEY_KP_POWER;
    m_trTable[SDL_SCANCODE_KP_PERCENT] = api::Input::KEY_KP_PERCENT;
    m_trTable[SDL_SCANCODE_KP_LESS] = api::Input::KEY_KP_LESS;
    m_trTable[SDL_SCANCODE_KP_GREATER] = api::Input::KEY_KP_GREATER;
    m_trTable[SDL_SCANCODE_KP_AMPERSAND] = api::Input::KEY_KP_AMPERSAND;
    m_trTable[SDL_SCANCODE_KP_DBLAMPERSAND] = api::Input::KEY_KP_DBLAMPERSAND;
    m_trTable[SDL_SCANCODE_KP_VERTICALBAR] = api::Input::KEY_KP_VERTICALBAR;
    m_trTable[SDL_SCANCODE_KP_DBLVERTICALBAR] = api::Input::KEY_KP_DBLVERTICALBAR;
    m_trTable[SDL_SCANCODE_KP_COLON] = api::Input::KEY_KP_COLON;
    m_trTable[SDL_SCANCODE_KP_HASH] = api::Input::KEY_KP_HASH;
    m_trTable[SDL_SCANCODE_KP_SPACE] = api::Input::KEY_KP_SPACE;
    m_trTable[SDL_SCANCODE_KP_AT] = api::Input::KEY_KP_AT;
    m_trTable[SDL_SCANCODE_KP_EXCLAM] = api::Input::KEY_KP_EXCLAM;
    m_trTable[SDL_SCANCODE_KP_MEMSTORE] = api::Input::KEY_KP_MEMSTORE;
    m_trTable[SDL_SCANCODE_KP_MEMRECALL] = api::Input::KEY_KP_MEMRECALL;
    m_trTable[SDL_SCANCODE_KP_MEMCLEAR] = api::Input::KEY_KP_MEMCLEAR;
    m_trTable[SDL_SCANCODE_KP_MEMADD] = api::Input::KEY_KP_MEMADD;
    m_trTable[SDL_SCANCODE_KP_MEMSUBTRACT] = api::Input::KEY_KP_MEMSUBTRACT;
    m_trTable[SDL_SCANCODE_KP_MEMMULTIPLY] = api::Input::KEY_KP_MEMMULTIPLY;
    m_trTable[SDL_SCANCODE_KP_MEMDIVIDE] = api::Input::KEY_KP_MEMDIVIDE;
    m_trTable[SDL_SCANCODE_KP_PLUSMINUS] = api::Input::KEY_KP_PLUSMINUS;
    m_trTable[SDL_SCANCODE_KP_CLEAR] = api::Input::KEY_KP_CLEAR;
    m_trTable[SDL_SCANCODE_KP_CLEARENTRY] = api::Input::KEY_KP_CLEARENTRY;
    m_trTable[SDL_SCANCODE_KP_BINARY] = api::Input::KEY_KP_BINARY;
    m_trTable[SDL_SCANCODE_KP_OCTAL] = api::Input::KEY_KP_OCTAL;
    m_trTable[SDL_SCANCODE_KP_DECIMAL] = api::Input::KEY_KP_DECIMAL;
    m_trTable[SDL_SCANCODE_KP_HEXADECIMAL] = api::Input::KEY_KP_HEXADECIMAL;
    m_trTable[SDL_SCANCODE_LCTRL] = api::Input::KEY_LCTRL;
    m_trTable[SDL_SCANCODE_LSHIFT] = api::Input::KEY_LSHIFT;
    m_trTable[SDL_SCANCODE_LALT] = api::Input::KEY_LALT;
    m_trTable[SDL_SCANCODE_LGUI] = api::Input::KEY_LGUI;
    m_trTable[SDL_SCANCODE_RCTRL] = api::Input::KEY_RCTRL;
    m_trTable[SDL_SCANCODE_RSHIFT] = api::Input::KEY_RSHIFT;
    m_trTable[SDL_SCANCODE_RALT] = api::Input::KEY_RALT;
    m_trTable[SDL_SCANCODE_RGUI] = api::Input::KEY_RGUI;
    m_trTable[SDL_SCANCODE_MODE] = api::Input::KEY_MODE;
    m_trTable[SDL_SCANCODE_AUDIONEXT] = api::Input::KEY_AUDIONEXT;
    m_trTable[SDL_SCANCODE_AUDIOPREV] = api::Input::KEY_AUDIOPREV;
    m_trTable[SDL_SCANCODE_AUDIOSTOP] = api::Input::KEY_AUDIOSTOP;
    m_trTable[SDL_SCANCODE_AUDIOPLAY] = api::Input::KEY_AUDIOPLAY;
    m_trTable[SDL_SCANCODE_AUDIOMUTE] = api::Input::KEY_AUDIOMUTE;
    m_trTable[SDL_SCANCODE_MEDIASELECT] = api::Input::KEY_MEDIASELECT;
    m_trTable[SDL_SCANCODE_WWW] = api::Input::KEY_WWW;
    m_trTable[SDL_SCANCODE_MAIL] = api::Input::KEY_MAIL;
    m_trTable[SDL_SCANCODE_CALCULATOR] = api::Input::KEY_CALCULATOR;
    m_trTable[SDL_SCANCODE_COMPUTER] = api::Input::KEY_COMPUTER;
    m_trTable[SDL_SCANCODE_AC_SEARCH] = api::Input::KEY_AC_SEARCH;
    m_trTable[SDL_SCANCODE_AC_HOME] = api::Input::KEY_AC_HOME;
    m_trTable[SDL_SCANCODE_AC_BACK] = api::Input::KEY_AC_BACK;
    m_trTable[SDL_SCANCODE_AC_FORWARD] = api::Input::KEY_AC_FORWARD;
    m_trTable[SDL_SCANCODE_AC_STOP] = api::Input::KEY_AC_STOP;
    m_trTable[SDL_SCANCODE_AC_REFRESH] = api::Input::KEY_AC_REFRESH;
    m_trTable[SDL_SCANCODE_AC_BOOKMARKS] = api::Input::KEY_AC_BOOKMARKS;
    m_trTable[SDL_SCANCODE_BRIGHTNESSDOWN] = api::Input::KEY_BRIGHTNESSDOWN;
    m_trTable[SDL_SCANCODE_BRIGHTNESSUP] = api::Input::KEY_BRIGHTNESSUP;
    m_trTable[SDL_SCANCODE_DISPLAYSWITCH] = api::Input::KEY_DISPLAYSWITCH;
    m_trTable[SDL_SCANCODE_KBDILLUMTOGGLE] = api::Input::KEY_KBDILLUMTOGGLE;
    m_trTable[SDL_SCANCODE_KBDILLUMDOWN] = api::Input::KEY_KBDILLUMDOWN;
    m_trTable[SDL_SCANCODE_KBDILLUMUP] = api::Input::KEY_KBDILLUMUP;
    m_trTable[SDL_SCANCODE_EJECT] = api::Input::KEY_EJECT;
    m_trTable[SDL_SCANCODE_SLEEP] = api::Input::KEY_SLEEP;
    m_trTable[SDL_SCANCODE_APP1] = api::Input::KEY_APP1;
    m_trTable[SDL_SCANCODE_APP2] = api::Input::KEY_APP2;

    // Mouse
    m_trTable[SDL_NUM_SCANCODES + 1] = api::Input::MOUSE_1;
    m_trTable[SDL_NUM_SCANCODES + 2] = api::Input::MOUSE_2;
    m_trTable[SDL_NUM_SCANCODES + 3] = api::Input::MOUSE_3;
    m_trTable[SDL_NUM_SCANCODES + 4] = api::Input::MOUSE_4;
    m_trTable[SDL_NUM_SCANCODES + 5] = api::Input::MOUSE_5;
    m_trTable[SDL_NUM_SCANCODES + 6] = api::Input::MOUSE_6;
    m_trTable[SDL_NUM_SCANCODES + 7] = api::Input::MOUSE_7;
    m_trTable[SDL_NUM_SCANCODES + 8] = api::Input::MOUSE_8;
    m_trTable[SDL_NUM_SCANCODES + 9] = api::Input::MOUSE_9;
}

SdlInput::~SdlInput() {
}

int SdlInput::handleEvents() {
    int eventCnt {0};

    while(m_sdl.SDL_PollEvent(&m_event)) {
        eventCnt++;

        switch (m_event.type) {
            case SDL_QUIT:
                m_signal.kill();
                break;
            case SDL_KEYDOWN: // not interested in repeated events
                if (m_event.key.repeat == 0) {
                    handleKey(api::Command::PRESSED);
                }
                break;
            case SDL_KEYUP:
                handleKey(api::Command::RELEASED);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleButton(api::Command::PRESSED);
                break;
            case SDL_MOUSEBUTTONUP:
                handleButton(api::Command::RELEASED);
                break;
        }
    }

    LOGINF("Input events: " << eventCnt);

    return eventCnt;
}

api::Input::Button SdlInput::attachCommand(api::Command* command, api::Input::Button button) {
    m_commander.attach(command, button);
    return button;
}

api::Input::Button SdlInput::attachCommand(api::Command* command) {
    return api::Input::KEY_UNKNOWN;
}

void SdlInput::handleKey(api::Command::Message message) {
    api::Input::Button button {api::Input::KEY_UNKNOWN};
    
    button = m_trTable[m_event.key.keysym.scancode];
    m_commander.execute(button, message);
}

void SdlInput::handleButton(api::Command::Message message) {
    api::Input::Button button {api::Input::KEY_UNKNOWN};

    button = m_trTable[SDL_NUM_SCANCODES + m_event.button.button];
    m_commander.execute(button, message);
}



} // namespace input
} // namespace engine
} // namespace nameless
