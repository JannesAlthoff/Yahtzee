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
 
#include "set.hpp"

#include "../../core/yahtzeeset.hpp"
#include "../../core/category.hpp"

#include <vector>
#include <string>
#include <iostream>

bool yahtzee::cli::command::set(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg){
	if(arg.size() == 1){
		std::cout << "Too few arguments" << std::endl;
	} else if (arg.size() != 2){
		std::cout << "Too many arguments" << std::endl;
	} else {
		if (arg.at(1) == "aces"){
			if(set.setStatusFromCategory(yahtzee::core::aces)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::aces) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if (arg.at(1) == "twos"){
			if(set.setStatusFromCategory(yahtzee::core::twos)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::twos) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if (arg.at(1) == "threes"){
			if(set.setStatusFromCategory(yahtzee::core::threes)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::threes) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if (arg.at(1) == "fours"){
			if(set.setStatusFromCategory(yahtzee::core::fours)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::fours) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if (arg.at(1) == "fives"){
			if(set.setStatusFromCategory(yahtzee::core::fives)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::fives) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "sixes"){
			if(set.setStatusFromCategory(yahtzee::core::sixes)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::sixes) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "threeOfAKind"){
			if(set.setStatusFromCategory(yahtzee::core::threeOfAKind)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::threeOfAKind) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "fourOfAKind"){
			if(set.setStatusFromCategory(yahtzee::core::fourOfAKind)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::fourOfAKind) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "chance"){
			if(set.setStatusFromCategory(yahtzee::core::chance)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::chance) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "fullHouse"){
			if(set.setStatusFromCategory(yahtzee::core::fullHouse)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::fullHouse) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "smallStraight"){
			if(set.setStatusFromCategory(yahtzee::core::smallStraight)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::smallStraight) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "largeStraight"){
			if(set.setStatusFromCategory(yahtzee::core::largeStraight)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::largeStraight) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else if(arg.at(1) == "yahtzee"){
			if(set.setStatusFromCategory(yahtzee::core::yahtzeeCat)){
				std::cout << "You have got " << set.getCategoryPoints(yahtzee::core::yahtzeeCat) + 0 << " Points" << std::endl;
			} else {
				std::cout << "You can't do this now" << std::endl;
			}
		} else {
			std::cout << "Invalid Argument" << std::endl;
		}
	}
	std::cout << std::endl;
	if (set.isGameOver()){
		return true;
	} else {
		return false;
	}
}