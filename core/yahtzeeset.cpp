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
 
#include "yahtzeeset.hpp"

#include <array>

#include "category.hpp"
#include "diceset.hpp"

bool yahtzee::core::yahtzeeSet::setStatusFromCategory(categoryType catType){
	bool temp = categories_.at(catType-1).setStatus(diceSet_);
	if (temp){
		overallMove_+=1;
		return true;
	} else {
		return false;
	}
}
uint8_t yahtzee::core::yahtzeeSet::countYahtzee(){
	uint8_t val = 0;
	for(category &cat : categories_){
		val += cat.isYahtzeeT();
	}
	return val;
}
uint16_t yahtzee::core::yahtzeeSet::getUpperPoints(){
	return categories_.at(0).getPoints() + categories_.at(1).getPoints() + categories_.at(2).getPoints() + categories_.at(3).getPoints() + categories_.at(4).getPoints() + categories_.at(5).getPoints();
}
uint16_t yahtzee::core::yahtzeeSet::getLowerPoints(){
	return categories_.at(6).getPoints() + categories_.at(7).getPoints() + categories_.at(8).getPoints() + categories_.at(9).getPoints() + categories_.at(10).getPoints() + categories_.at(11).getPoints() + categories_.at(12).getPoints();
}
uint8_t yahtzee::core::yahtzeeSet::getBonus(){
	if(getUpperPoints() >= 63){
		return 35;
	} else {
		return 0;
	}
}
