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
 
#include "select.hpp"

#include "../../core/yahtzeeset.hpp"

#include <vector>
#include <iostream>
#include <cstdint>
#include <exception>

bool yahtzee::cli::command::select(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg){
	if(arg.size() == 1){
		std::cout << "Too few arguments" << std::endl;
	}
	if(arg.size() == 2){
		if(arg.at(1) == "all"){
			for(uint8_t i = 0; i < 5; ++i){
				set.selectDice(i);
			}
		} else {
			try {
				int64_t i = std::stoi(arg.at(1)) -1;
				if(i < 0){
					throw std::out_of_range("E");
				} else if(i > 5){
					throw std::out_of_range("E");
				} else {
					set.selectDice(i);
				}
			} catch (const std::invalid_argument& e){
				std::cout << "Invalid Argument" << std::endl;
			} catch (const std::out_of_range& e){
				std::cout << "Out of Range" << std::endl;
			}
		}
	} else {
		std::cout << "Too many arguments" << std::endl;
	}
	std::cout << std::endl;
	return false;
}
bool yahtzee::cli::command::deselect(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg){
	if(arg.size() == 1){
		std::cout << "Too few arguments" << std::endl;
	}
	if(arg.size() == 2){
		if(arg.at(1) == "all"){
			for(uint8_t i = 0; i < 5; ++i){
				set.deselectDice(i);
			}
		} else {
			try {
				int64_t i = std::stoi(arg.at(1)) - 1;
				if(i < 0){
					throw std::out_of_range("E");
				} else if(i > 5){
					throw std::out_of_range("E");
				} else {
					set.deselectDice(i);
				}
			} catch (const std::invalid_argument& e){
				std::cout << "Invalid Argument" << std::endl;
			} catch (const std::out_of_range& e){
				std::cout << "Out of Range" << std::endl;
			}
		}
	} else {
		std::cout << "Too many arguments" << std::endl;
	}
	std::cout << std::endl;
	return false;
}