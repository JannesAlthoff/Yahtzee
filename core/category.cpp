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
 
#include "category.hpp"

#include <exception>
#include <array>

#include "diceset.hpp"

//Categorie
int8_t yahtzee::core::category::getPoints(){
	if (status_ == -1 || status_ == 0){
		return 0;
	} else {
		switch(categorie_){
			case aces:
			case twos:
			case threes:
			case fours:
			case fives:
			case sixes:
			case threeOfAKind:
			case fourOfAKind:
			case chance:
				return status_;
				break;
			case fullHouse:
				return 25;
				break;
			case smallStraight:
				return 30;
				break;
			case largeStraight:
				return 40;
				break;
			case yahtzeeCat:
				return 50;
				break;
			default:
				//Remove Compiler Warnings
				throw std::logic_error("What???");
				return 0;
		}
	}
}
bool yahtzee::core::category::isCrossed(){
	if(status_ == -1){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::category::isFillable(){
	if(status_ == 0){
		return true;
	} else {
		return false;
	}
}
bool yahtzee::core::category::setStatus(diceSet &set){
	if (set.getMove() != 0 && status_ == 0){
		if (set.isYahtzee()){
			yahtzee_ = true;
		}
		switch(categorie_){
			case aces:
			case twos:
			case threes:
			case fours:
			case fives:
			case sixes:
			{
				uint8_t temp = 0;
				for (dice Dice : set.getInternalDiceSet()){
					if (Dice.getDiceVal() == categorie_){
						++temp;
					}
				}
				if (temp == 0){
					status_=-1;
				} else {
					status_=temp*categorie_;
				}
				break;
			}
			case threeOfAKind:
			case fourOfAKind:
			case chance:
			{
				uint8_t temp = 0;
				for (dice Dice : set.getInternalDiceSet()){
					temp+=Dice.getDiceVal();
				}
				switch(categorie_){
					case threeOfAKind:
						if (set.isThreeOfAKind()){
							status_=temp;
						} else {
							status_=-1;
						}
						break;
					case fourOfAKind:
						if (set.isFourOfAKind()){
							status_=temp;
						} else {
							status_=-1;
						}
						break;
					case chance:
						status_=temp;
						break;
					default:
						break;
				}
				break;
			}
			case fullHouse:
			{
				if (set.isFullHouse()){
					status_=1;
				} else {
					status_=-1;
				}
				break;
			}
			case smallStraight:
			{
				if(set.isSmallStraight()){
					status_=1;
				} else {
					status_=-1;
				}
				break;
			}
			case largeStraight:
			{
				if(set.isLargeStraight()){
					status_=1;
				} else {
					status_=-1;
				}
				break;
			}
			case yahtzeeCat:
			{
				if(set.isYahtzee()){
					status_=1;
				} else {
					status_=-1;
				}
				break;
			}
			default:
				break;
		}
		set.clear();
		return true;
	} else {
		return false;
	}
}
