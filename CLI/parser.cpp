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
 
#include "parser.hpp"

#include "../core/yahtzeeset.hpp"

//Commands
#include "commands/set.hpp"
#include "commands/close.hpp"
#include "commands/select.hpp"
#include "commands/print.hpp"
#include "commands/help.hpp"
#include "commands/randomize.hpp"
#include "commands/show.hpp"

#include <iostream>
#include <vector>
#include <sstream>

bool yahtzee::cli::parser::inString(std::string in){
	std::stringstream ss(in);
	std::vector<std::string> arg;
	std::string token;
	while(std::getline(ss, token, ' ')){
		arg.push_back(token);
	}
	if(arg.size() == 0){
		std::cout << "Too few arguments" << std::endl;
		return false;
	} else {
		if(arg.at(0) == "help"){
			return (yahtzee::cli::command::help(yahtzeeSet_, arg));
		} else if (arg.at(0) == "print") {
			return (yahtzee::cli::command::print(yahtzeeSet_, arg));
		} else if (arg.at(0) == "randomize") {
			return (yahtzee::cli::command::randomize(yahtzeeSet_, arg));
		} else if (arg.at(0) == "select"){
			return (yahtzee::cli::command::select(yahtzeeSet_, arg));
		} else if (arg.at(0) == "deselect"){
			return (yahtzee::cli::command::deselect(yahtzeeSet_, arg));
		} else if (arg.at(0) == "set"){
			return (yahtzee::cli::command::set(yahtzeeSet_, arg));
		} else if (arg.at(0) == "close"){
			return (yahtzee::cli::command::close(yahtzeeSet_, arg));
		} else if (arg.at(0) == "show"){
			return (yahtzee::cli::command::show(yahtzeeSet_, arg));
		} else {
			std::cout << "Command not found" << std::endl
											 << std::endl;
			return false;
		}
	}
}