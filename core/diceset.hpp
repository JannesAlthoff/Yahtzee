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
 
#ifndef YAHTZEECORE_DICESET_HPP
#define YAHTZEECORE_DICESET_HPP

#include <array>
#include <cstdint>
#include <algorithm>

#include "dice.hpp"
#include "category.hpp"

namespace yahtzee{
	namespace core{
		class diceSet{
			public:
				dice getDice(uint8_t dice){return diceSet_.at(dice);}
				uint8_t getDiceVal(uint8_t dice){return diceSet_.at(dice).getDiceVal();}
				bool getDiceSelected(uint8_t dice){return diceSet_.at(dice).getDiceSelected();}
				uint8_t getMove(){return move_;}
				
				//Is
				bool isYahtzee();
				bool isLargeStraight();
				bool isSmallStraight();
				bool isFullHouse();
				bool isThreeOfAKind();
				bool isFourOfAKind();
				
				//Constructor
				diceSet():
					move_(0){
					diceSet_={};
				}
			private:
				//Friend 
				friend class yahtzeeSet;
				friend class category;
				//Internal Values
				std::array<dice, 5> diceSet_;
				uint8_t move_;
				//Functions
				void clear();
				void select(uint8_t dice){diceSet_.at(dice).setDiceSelected(true);}
				void deselect(uint8_t dice){diceSet_.at(dice).setDiceSelected(false);}
				inline std::array<dice, 5> getInternalDiceSet(){return diceSet_;}
				void sort(){std::sort(diceSet_.begin(), diceSet_.end());};
				//if returned false there was an error
				bool randomizeAll();
				bool randomizeSelected();
		};
		//MIC FUNC
		bool threeSame(uint8_t one, uint8_t two, uint8_t three);
		bool fourSame(uint8_t one, uint8_t two, uint8_t three, uint8_t four);
		bool fiveSame(uint8_t one, uint8_t two, uint8_t three, uint8_t four, uint8_t five);
	}
}
#include "diceset.cpp"
#endif