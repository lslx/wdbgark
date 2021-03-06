/*
    * WinDBG Anti-RootKit extension
    * Copyright � 2013-2015  Vyacheslav Rusakoff
    * 
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    * 
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    * 
    * You should have received a copy of the GNU General Public License
    * along with this program.  If not, see <http://www.gnu.org/licenses/>.

    * This work is licensed under the terms of the GNU GPL, version 3.  See
    * the COPYING file in the top-level directory.
*/

#include "util.hpp"
#include <engextcpp.hpp>

#include <sstream>

#include "manipulators.hpp"

namespace wa {

bool NormalizeAddress(const uint64_t address, uint64_t* result) {
    *result = 0;

    std::stringstream string_value;
    string_value << std::hex << std::showbase << address;

    try {
        *result = g_Ext->EvalExprU64(string_value.str().c_str());
        return true;
    } catch ( const ExtStatusException &Ex ) {
        std::stringstream err;
        err << wa::showminus << __FUNCTION__ << ": " << Ex.GetMessage() << endlerr;
    }

    return false;
}

}   // namespace wa
