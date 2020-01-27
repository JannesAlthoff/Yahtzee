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
 
#include "core/yahtzeeset.hpp"

#include "cli/parser.hpp"

#include <iostream>
#include <string>

int main(void){
	yahtzee::cli::parser parserH;
	std::string in;
	std::cout 	<< "Yahtzee  Copyright (C) 2019  Jannes Althoff"                                << std::endl
				<< "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << std::endl
				<< "This is free software, and you are welcome to redistribute it"              << std::endl
				<< "under certain conditions; type `show c' for details."                       << std::endl;
	while (true){
		std::cout << ">";
		std::getline(std::cin, in);
		if(parserH.inString(in)){
			break;
		}
	}
	return 0;
}
