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
 
#include "show.hpp"

#include "../../core/yahtzeeset.hpp"

#include <vector>
#include <string>
#include <iostream>

bool yahtzee::cli::command::show(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg){
	if(arg.size() == 1){
		std::cout << "Too few arguments";
	} else if (arg.size() != 2){
		std::cout << "Too many arguments";
	} else {
		if(arg.at(1) == "w"){
			std::cout 	<< "This program is distributed in the hope that it will be useful," << std::endl
						<< "but WITHOUT ANY WARRANTY; without even the implied warranty of"  << std::endl
						<< "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the"   << std::endl
						<< "GNU General Public License for mordde details."                  << std::endl;
		} else if(arg.at(1) == "c"){
			std::cout 	<< "This program is free software: you can redistribute it and/or modify" << std::endl
						<< "it under the terms of the GNU General Public License as published by" << std::endl
						<< "the Free Software Foundation, either version 3 of the License, or"    << std::endl
						<< "(at your option) any later version."                                  << std::endl;
		} else {
			std::cout << "Invalid Argument";
		}
	}
	std::cout << std::endl;
	return false;
}