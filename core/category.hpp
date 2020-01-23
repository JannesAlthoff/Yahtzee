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
 
#ifndef YAHTZEECORE_CATEGORY_HPP
#define YAHTZEECORE_CATEGORY_HPP

#include <cstdint>

#include "diceset.hpp"
#include "yahtzeeset.hpp"

namespace yahtzee{
	namespace core{
		enum categoryType {aces = 1, twos = 2, threes = 3, fours = 4, fives = 5, sixes = 6, threeOfAKind = 7, fourOfAKind = 8, fullHouse = 9, smallStraight = 10, largeStraight = 11, yahtzeeCat = 12, chance = 13};
		class category{
			public:
				//Get
				int8_t getPoints();
				int8_t getStatus(){return status_;}
				bool isCrossed();
				bool isFillable();
				bool isYahtzeeT(){return yahtzee_;}
				//Default Constructor
				category(categoryType category):
					categorie_(category),
					status_(0),
					yahtzee_(false){
					}
			private:
				//Friend Declarator
				friend class yahtzeeSet;
				//Internal Values
				const categoryType categorie_;
				//For acces to sixes and threeOfAKind/fourOfAKind and chance
				//-1 is crossed out; If You have no Points
				//0 is not filled
				//1-30 are the points you have
				
				//For fullHouse, small/large straight and yahtzee
				//-1 is crossed out
				//0 is not filled
				//1 is filled
				int8_t status_;
				bool yahtzee_;
				
				//Functions
				//Clears the diceSet
				//returns false if Turn is 0
				bool setStatus(diceSet &set);
		};
	}
}
#include "category.cpp"
#endif