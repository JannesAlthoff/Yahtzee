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
 
#ifndef YAHTZEESET_DICESET_HPP
#define YAHTZEESET_DICESET_HPP

#include "category.hpp"
#include "diceset.hpp"

#include <array>
#include <cstdint>

namespace yahtzee{
	namespace core{
		class yahtzeeSet{
			public:
				//Functions
				//Clears the diceSet
				//returns false if Turn is 0 or is already set
				bool setStatusFromCategory(categoryType catType);
				//Getter
				inline uint8_t getCategoryStatus(categoryType catType){return categories_.at(catType-1).getStatus();}
				inline uint8_t getCategoryPoints(categoryType catType){return categories_.at(catType-1).getPoints();}
				inline uint8_t isCrossed(categoryType catType){return categories_.at(catType-1).isCrossed();}
				//Functions
				inline void selectDice(uint8_t dice){diceSet_.select(dice);}
				inline void deselectDice(uint8_t dice){diceSet_.deselect(dice);}
				inline uint8_t getOverallMove(){return overallMove_;}
				//if returned false there was an error or the game is over
				inline bool randomizeAll(){if(isGameOver()){return false;} return diceSet_.randomizeAll();}
				inline bool randomizeSelected(){if(isGameOver()){return false;} return diceSet_.randomizeSelected();}
				//Get Dice PTR
				inline diceSet* getDiceSetPtr(){return &diceSet_;}
				//Is
				inline bool isGameOver(){if (overallMove_==13){return true;} return false;}
				
				//Count Yahtzee
				uint8_t countYahtzee();
				uint16_t getUpperPoints();
				uint16_t getLowerPoints();
				uint8_t getBonus();
				uint16_t getPoints(){return getUpperPoints() + getBonus() + getLowerPoints();}
				
				//Constructor
				yahtzeeSet():
					categories_{category(aces), category(twos), category(threes), category(fours), category(fives), category(sixes), category(threeOfAKind), category(fourOfAKind), category(fullHouse), category(smallStraight), category(largeStraight), category(yahtzeeCat), category(chance)},
					overallMove_(0),
					diceSet_{diceSet()}{
				}
			private:
				std::array<category, 13> categories_;
				uint8_t overallMove_;
				diceSet diceSet_;
		};
	}
}
#include "yahtzeeset.cpp"
#endif
