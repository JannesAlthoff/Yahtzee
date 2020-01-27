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
 
#include "diceSet.hpp"

#include "dice.hpp"

#include <array>
#include <algorithm>
#include <cstdint>
#include <random>
#include <chrono>

void yahtzee::core::diceSet::clear(){
	for(dice& Dice : diceSet_){
		Dice.clear();
		Dice.setDiceSelected(true);
	}
	move_=0;
}
bool yahtzee::core::diceSet::randomizeAll(){
	if(move_<3){
		std::mt19937_64 rd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<uint8_t> dis(1, 6);
		for(dice &Dice : diceSet_){
			Dice.set(dis(rd));
		}
		++move_;
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::randomizeSelected(){
	if(move_<3 && move_!=0){
		std::mt19937_64 rd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<uint8_t> dis(1, 6);
		for(dice &Dice : diceSet_){
			if (Dice.getDiceSelected()){
				Dice.set(dis(rd));
			}
		}
		++move_;
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isYahtzee(){
	if (move_ == 0){
		return false;
	}
	if(fiveSame(getDiceVal(0), getDiceVal(1), getDiceVal(2), getDiceVal(3), getDiceVal(4))){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isLargeStraight(){
        if (move_ == 0){
		return false;
	}
	std::array<dice, 5> tempDiceSet_(diceSet_);
	std::sort(tempDiceSet_.begin(), tempDiceSet_.end());
	if(((tempDiceSet_.at(0).getDiceVal() == 1) + (tempDiceSet_.at(1).getDiceVal() == 2) + (tempDiceSet_.at(2).getDiceVal() == 3) + (tempDiceSet_.at(3).getDiceVal() == 4) + (tempDiceSet_.at(4).getDiceVal() == 5) == 5) || ((tempDiceSet_.at(0).getDiceVal() == 2) + (tempDiceSet_.at(1).getDiceVal() == 3) + (tempDiceSet_.at(2).getDiceVal() == 4) + (tempDiceSet_.at(3).getDiceVal() == 5) + (tempDiceSet_.at(4).getDiceVal() == 6) == 5)){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isSmallStraight(){
        if (move_ == 0){
		return false;
	}
	std::array<bool, 6> dice_val{false, false, false, false, false, false};
	for (dice Dice : diceSet_){
			dice_val.at(Dice.getDiceVal()-1) = true;
	}
	if (((dice_val.at(0) && dice_val.at(1)) && (dice_val.at(2) && dice_val.at(3))) || (dice_val.at(1) && dice_val.at(2)) && (dice_val.at(3) && dice_val.at(4)) || (dice_val.at(2) && dice_val.at(3)) && (dice_val.at(4) && dice_val.at(5))){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isFullHouse(){
	if (move_ == 0){
		return false;
	}
	std::array<dice, 5> tempDiceSet_(diceSet_);
	std::sort(tempDiceSet_.begin(), tempDiceSet_.end());
	if((threeSame(tempDiceSet_.at(0).getDiceVal(), tempDiceSet_.at(1).getDiceVal(), tempDiceSet_.at(2).getDiceVal()) && (tempDiceSet_.at(3).getDiceVal() == tempDiceSet_.at(4).getDiceVal())) || (threeSame(tempDiceSet_.at(2).getDiceVal(), tempDiceSet_.at(3).getDiceVal(), tempDiceSet_.at(4).getDiceVal()) && (tempDiceSet_.at(0).getDiceVal() == tempDiceSet_.at(1).getDiceVal()))){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isThreeOfAKind(){
	if (move_ == 0){
		return false;
	}
	std::array<dice, 5> tempDiceSet_(diceSet_);
	std::sort(tempDiceSet_.begin(), tempDiceSet_.end());
	if(threeSame(tempDiceSet_.at(0).getDiceVal(), tempDiceSet_.at(1).getDiceVal(), tempDiceSet_.at(2).getDiceVal()) || threeSame(tempDiceSet_.at(1).getDiceVal(), tempDiceSet_.at(2).getDiceVal(), tempDiceSet_.at(3).getDiceVal()) || threeSame(tempDiceSet_.at(2).getDiceVal(), tempDiceSet_.at(3).getDiceVal(), tempDiceSet_.at(4).getDiceVal())){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::diceSet::isFourOfAKind(){
	if (move_ == 0){
		return false;
	}
	std::array<dice, 5> tempDiceSet_(diceSet_);
	std::sort(tempDiceSet_.begin(), tempDiceSet_.end());
	if(fourSame(tempDiceSet_.at(0).getDiceVal(), tempDiceSet_.at(1).getDiceVal(), tempDiceSet_.at(2).getDiceVal(), tempDiceSet_.at(3).getDiceVal()) || fourSame(tempDiceSet_.at(1).getDiceVal(), tempDiceSet_.at(2).getDiceVal(), tempDiceSet_.at(3).getDiceVal(), tempDiceSet_.at(4).getDiceVal())){
		return true;
	} else {
		return false;
	}
}
//MIC FUNC
bool yahtzee::core::threeSame(uint8_t one, uint8_t two, uint8_t three){
	if((one == two) && (two == three)){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::fourSame(uint8_t one, uint8_t two, uint8_t three, uint8_t four){
	if((one == two) + (three == four) + (two == three) == 3){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::fiveSame(uint8_t one, uint8_t two, uint8_t three, uint8_t four, uint8_t five){
	if(threeSame(one, two, three) && threeSame(three, four, five)){
		return true;
	} else {
		return false;
	}
}
