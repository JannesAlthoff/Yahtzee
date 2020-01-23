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
 
#ifndef YAHTZEECLI_PARSER_HPP
#define YAHTZEECLI_PARSER_HPP

#include "../core/yahtzeeset.hpp"

#include <string>

namespace yahtzee{
	namespace cli{
		class parser{
			public:
				//Funktion
				//Returns true if programm should be closed
				bool inString(std::string in);
				//Constructor
				parser():
					yahtzeeSet_(yahtzee::core::yahtzeeSet()){
				}
			private:
				yahtzee::core::yahtzeeSet yahtzeeSet_;
		};
	}
}
#include "parser.cpp"
#endif