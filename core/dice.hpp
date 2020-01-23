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
 
#ifndef YAHTZEECORE_DICE_HPP
#define YAHTZEECORE_DICE_HPP

#include <cstdint>
#include <chrono>
#include <random>

#include "diceset.hpp"

namespace yahtzee{
	namespace core{
		class dice{
			public:
				//Functions
				inline uint8_t getDiceVal(){return val_;}
				inline uint8_t getDiceSelected(){return selected_;}
				inline void setDiceSelected(bool selected){selected_=selected;}
				bool operator < (const dice& t) const{return val_ < t.val_;}
				//Constructor
				dice():
					val_(0),
					selected_(true){
				}
			private:
				//Friend Declarator
				friend class diceSet;
				//Internal Values
				//0 is not set
				uint8_t val_;
				bool selected_;
				//Functions
				inline void clear(){val_ = 0; selected_ = true;}
				void randomize();
				void set(uint8_t val){val_ = val;}
		};
	}
}
#include "dice.cpp"
#endif