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
 
#include "print.hpp"

#include "../../core/yahtzeeset.hpp"
#include "../../core/category.hpp"
#include "../../core/diceset.hpp"

#include <vector>
#include <iostream>

std::string yahtzee::cli::command::crossed(bool i){
	if(i){
		return "X";
	} else {
		return " ";
	}
}
void yahtzee::cli::command::printDice(yahtzee::core::yahtzeeSet &set){
	std::cout	<< "Dices" << std::endl
				<< "Dice	"	<< "Value"	 								<< "	" << "Selected"											<< std::endl
				<< "1:	"		<< set.getDiceSetPtr()->getDiceVal(0) + 0	<< "	" << crossed(set.getDiceSetPtr()->getDiceSelected(0))	<< std::endl
				<< "2:	"		<< set.getDiceSetPtr()->getDiceVal(1) + 0	<< "	" << crossed(set.getDiceSetPtr()->getDiceSelected(1))	<< std::endl
				<< "3:	"		<< set.getDiceSetPtr()->getDiceVal(2) + 0	<< "	" << crossed(set.getDiceSetPtr()->getDiceSelected(2))	<< std::endl
				<< "4:	"		<< set.getDiceSetPtr()->getDiceVal(3) + 0	<< "	" << crossed(set.getDiceSetPtr()->getDiceSelected(3))	<< std::endl
				<< "5:	"		<< set.getDiceSetPtr()->getDiceVal(4) + 0	<< "	" << crossed(set.getDiceSetPtr()->getDiceSelected(4))	<< std::endl;
}
void yahtzee::cli::command::printCategories(yahtzee::core::yahtzeeSet &set){
	std::cout	<< "Categories" 																																			<< std::endl
																																											<< std::endl
				<< "Upper section" 																																			<< std::endl
				<< "Category		"		<< "Points"													<< "	" << "Crossed"												<< std::endl
				<< "Aces:			" 		<< set.getCategoryPoints(yahtzee::core::aces) 			+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::aces)) 			<< std::endl
				<< "Twos:			" 		<< set.getCategoryPoints(yahtzee::core::twos)			+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::twos)) 			<< std::endl
				<< "Threes:			"		<< set.getCategoryPoints(yahtzee::core::threes) 		+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::threes)) 			<< std::endl
				<< "Fours:			"		<< set.getCategoryPoints(yahtzee::core::fours)		 	+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::fours)) 			<< std::endl
				<< "Fives:			"		<< set.getCategoryPoints(yahtzee::core::fives)		 	+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::fives)) 			<< std::endl
				<< "Sixes:			"		<< set.getCategoryPoints(yahtzee::core::sixes) 			+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::sixes)) 			<< std::endl
																																											<< std::endl
				<< "Bonus:			"		<< set.getBonus()										+ 0	<< "	"															<< std::endl
																																											<< std::endl
				<< "Total Upper:		"	<< set.getUpperPoints() + set.getBonus()				+ 0	<< "	"															<< std::endl
																																											<< std::endl
				<< "Lower section"																																			<< std::endl
				<< "Category		"		<< "Points"													<< "	" << "Crossed"												<< std::endl
				<< "Three of a Kind:	"	<< set.getCategoryPoints(yahtzee::core::threeOfAKind)	+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::threeOfAKind))	<< std::endl
				<< "Four of a Kind:		"	<< set.getCategoryPoints(yahtzee::core::fourOfAKind)	+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::fourOfAKind))		<< std::endl
				<< "Full House:		"		<< set.getCategoryPoints(yahtzee::core::fullHouse)		+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::fullHouse))		<< std::endl
				<< "Small Straight:		"	<< set.getCategoryPoints(yahtzee::core::smallStraight)	+ 0	<< "	" << crossed(set.isCrossed(yahtzee::core::smallStraight))	<< std::endl
				<< "Large Straight:		"	<< set.getCategoryPoints(yahtzee::core::largeStraight)	+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::largeStraight))	<< std::endl
				<< "Yahtzee:		"		<< set.getCategoryPoints(yahtzee::core::yahtzeeCat)		+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::yahtzeeCat))		<< std::endl
				<< "Chance:			"		<< set.getCategoryPoints(yahtzee::core::chance)			+ 0 << "	" << crossed(set.isCrossed(yahtzee::core::chance))			<< std::endl
																																											<< std::endl
				<< "Total Lower:		"	<< set.getLowerPoints()									+ 0	<< "	"															<< std::endl
																																											<< std::endl
				<< "Total:			"		<< set.getPoints()										+ 0	<< "	"															<< std::endl;
}
void yahtzee::cli::command::printStats(yahtzee::core::yahtzeeSet &set){
	std::cout	<< "Stats			"		<< "Value"								<< std::endl
				<< "Move:			"		<< set.getDiceSetPtr()->getMove() 	+ 0	<< std::endl
				<< "Filled Categories:	"	<< set.getOverallMove() 			+ 0	<< std::endl
				<< "Yahtzee's:		"		<< set.countYahtzee() 				+ 0 << std::endl;
}
void yahtzee::cli::command::printAll(yahtzee::core::yahtzeeSet &set){
	//Categories Points
	printCategories(set);
	std::cout << std::endl;
	//Dices
	printDice(set);
	std::cout << std::endl;
	//Stats
	printStats(set);
}
bool yahtzee::cli::command::print(yahtzee::core::yahtzeeSet &set, std::vector<std::string> arg){
	if (arg.size() != 1){
		if(arg.size() != 2){
			std::cout << "Too many arguments" << std::endl;
		} else if (arg.at(1) == "all"){
			printAll(set);
		} else if (arg.at(1) == "categories"){
			printCategories(set);
		} else if (arg.at(1) == "dices"){
			printDice(set);
		} else if (arg.at(1) == "stats"){
			printStats(set);
		} else {
			std::cout << "Command not found" << std::endl;
		}
	} else {
		printAll(set);
	}
	std::cout << std::endl;
	return false;
}