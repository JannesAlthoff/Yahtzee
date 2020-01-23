/* 
 * This file is part of Yahtzee (https://github.com/JolokHD/Yahtzee) 
 * Copyright (C) 2019  Jannes Althoff
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>
 */
 
#ifndef YAHTZEECLI_SET_HPP
#define YAHTZEECLI_SET_HPP

#include "../../core/yahtzeeset.hpp"

#include <vector>
#include <string>

namespace yahtzee{
	namespace cli{
		namespace command{
			bool set(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg);
		}
	}
}
#include "set.cpp"
#endif