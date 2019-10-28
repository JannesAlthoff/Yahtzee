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
#ifndef STATEYAHTZEE_HPP
#define STATEYAHTZEE_HPP

#include <bitset>
#include "bitsettools.hpp"

namespace yahtzee{
    namespace state{
        //Class which can save all Dices
        class DiceState{
            public:
                //If CheckBit should be Set after an action
                inline void setCheckBitAfterEdit(bool checkBit){setCheckBit_=checkBit;}
                inline bool getCheckBitAfterEdit(){return setCheckBit_;}
                //CheckBit 1 if times of 1 is even 0 if odd. Last Bit
                inline bool getCorrectCheckBit(){return yahtzee::bitsettools::getCorrectCheckBit(&diceState_);}
                inline bool verifyCheckBit(){return yahtzee::bitsettools::verifyCheckBit(&diceState_);}
                inline void setCorrectCheckBit(){yahtzee::bitsettools::setCorrectCheckBit(&diceState_, setCheckBit_);} //Will be called after each set.
                inline void setCorrectCheckBitIgnore(){yahtzee::bitsettools::setCorrectCheckBit(&diceState_, true);}

                void verifyIntegrity(uint8_t dice); //Will remove any 7s and set it to 000. Will be called after each set. But is slow you can disable it by setting the bool verify to 0
                void verifyIntegrityFull();
                inline void afterEdit(uint8_t dice){if (verify_){verifyIntegrity(dice); setCorrectCheckBit();}}
                inline void afterEditFull(){if (verify_){verifyIntegrityFull(); setCorrectCheckBit();}}
                //Getter and Setter
                //Global
                inline bool getVerify(){return verify_;}
                inline void setVerify(bool verify){verify_=verify;}
                inline std::bitset<16> getDiceState(){return diceState_;}
                inline unsigned long int getDiceStateL(){return diceState_.to_ulong();}
                inline unsigned long long int getDiceStateLL(){return diceState_.to_ullong();}
                inline void setDiceState(std::bitset<16> diceState){diceState_ = diceState; afterEditFull();}
                inline void setDiceStateL(unsigned long int diceState){diceState_=std::bitset <16> (diceState); afterEditFull();}
                inline void setDiceStateLL(unsigned long long int diceState){diceState_=std::bitset <16> (diceState); afterEditFull();}
                //Get Dice
                unsigned long getDiceL(uint8_t Dice);
                std::bitset<3> getDice(uint8_t Dice);
                inline unsigned long int getDice0L(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(0, &diceState_).to_ulong();}
                inline unsigned long int getDice1L(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(3, &diceState_).to_ulong();}
                inline unsigned long int getDice2L(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(6, &diceState_).to_ulong();}
                inline unsigned long int getDice3L(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(9, &diceState_).to_ulong();}
                inline unsigned long int getDice4L(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(12, &diceState_).to_ulong();}
                inline std::bitset<3> getDice0(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(0, &diceState_);}
                inline std::bitset<3> getDice1(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(3, &diceState_);}
                inline std::bitset<3> getDice2(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(6, &diceState_);}
                inline std::bitset<3> getDice3(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(9, &diceState_);}
                inline std::bitset<3> getDice4(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(12, &diceState_);}
                //Set Dice
                void setDiceL(uint8_t Dice, unsigned long int TimesOfDice);
                void setDice(uint8_t Dice, std::bitset<3> TimesOfDice);
                inline void setDice0L(unsigned long int Dice){std::bitset<3> Temp(Dice); yahtzee::bitsettools::CopyBitsToBitSet(0, &Temp, &diceState_); afterEdit(0);}
                inline void setDice1L(unsigned long int Dice){std::bitset<3> Temp(Dice); yahtzee::bitsettools::CopyBitsToBitSet(3, &Temp, &diceState_); afterEdit(1);}
                inline void setDice2L(unsigned long int Dice){std::bitset<3> Temp(Dice); yahtzee::bitsettools::CopyBitsToBitSet(6, &Temp, &diceState_); afterEdit(2);}
                inline void setDice3L(unsigned long int Dice){std::bitset<3> Temp(Dice); yahtzee::bitsettools::CopyBitsToBitSet(9, &Temp, &diceState_); afterEdit(3);}
                inline void setDice4L(unsigned long int Dice){std::bitset<3> Temp(Dice); yahtzee::bitsettools::CopyBitsToBitSet(12, &Temp, &diceState_); afterEdit(4);}
                inline void setDice0(std::bitset<3> Dice){yahtzee::bitsettools::CopyBitsToBitSet(0, &Dice, &diceState_); afterEdit(0);}
                inline void setDice1(std::bitset<3> Dice){yahtzee::bitsettools::CopyBitsToBitSet(3, &Dice, &diceState_); afterEdit(1);}
                inline void setDice2(std::bitset<3> Dice){yahtzee::bitsettools::CopyBitsToBitSet(6, &Dice, &diceState_); afterEdit(2);}
                inline void setDice3(std::bitset<3> Dice){yahtzee::bitsettools::CopyBitsToBitSet(9, &Dice, &diceState_); afterEdit(3);}
                inline void setDice4(std::bitset<3> Dice){yahtzee::bitsettools::CopyBitsToBitSet(12, &Dice, &diceState_); afterEdit(4);}
                //CheckBit Getter and Setter
                inline bool getCheckBit(){return diceState_[15];}
                inline void setCheckBit(bool checkBit){diceState_.set(15, checkBit);}
                //Constructor
                DiceState(std::bitset <16> diceState);
                DiceState(std::bitset <16> diceState, bool verifyandcheck);
                DiceState(std::bitset <16> diceState, bool verify, bool setCheckBit);
            private:
                std::bitset <16> diceState_;
                bool verify_; //If Verification should be executed
                bool setCheckBit_; //If CheckBit should be set after Edit
        };
        class DiceSelectedState{
            public:
                //If CheckBit should be Set after an action
                inline void setCheckBitAfterEdit(bool checkBit){setCheckBit_=checkBit;}
                inline bool getCheckBitAfterEdit(){return setCheckBit_;}
                //Global
                bool getDiceSelected(uint8_t Dice);
                void setDiceSelected(uint8_t Dice, bool selected);
                //CheckBit 1 if times of 1 is even 0 if odd. Last Bit
                inline bool getCorrectCheckBit(){return yahtzee::bitsettools::getCorrectCheckBit(&diceSelectedState_);}
                inline bool verifyCheckBit(){return yahtzee::bitsettools::verifyCheckBit(&diceSelectedState_);}
                inline void setCorrectCheckBit(){yahtzee::bitsettools::setCorrectCheckBit(&diceSelectedState_, setCheckBit_);} //Will be called after each set.
                inline void setCorrectCheckBitIgnore(){yahtzee::bitsettools::setCorrectCheckBit(&diceSelectedState_, true);}
                //Global Gets and Sets
                inline std::bitset<6> getDiceSelectedSet(){return diceSelectedState_;}
                inline void setDiceSelectedSet(std::bitset<6> diceSelectedState){diceSelectedState_=diceSelectedState; setCorrectCheckBit();}
                inline unsigned long getDiceSelectedSetL(){return diceSelectedState_.to_ulong();}
                inline void setDiceSelectedSetL(unsigned long diceSelectedState){std::bitset<6> Temp(diceSelectedState); diceSelectedState_=Temp; setCorrectCheckBit();}
                //DiceState Get
                inline bool getDiceSelected0(){return diceSelectedState_[0];}
                inline bool getDiceSelected1(){return diceSelectedState_[1];}
                inline bool getDiceSelected2(){return diceSelectedState_[2];}
                inline bool getDiceSelected3(){return diceSelectedState_[3];}
                inline bool getDiceSelected4(){return diceSelectedState_[4];}
                //DiceState Set If True Selected
                inline void setDiceSelected0(bool selected){diceSelectedState_.set(0, selected); setCorrectCheckBit();}
                inline void setDiceSelected1(bool selected){diceSelectedState_.set(1, selected); setCorrectCheckBit();}
                inline void setDiceSelected2(bool selected){diceSelectedState_.set(2, selected); setCorrectCheckBit();}
                inline void setDiceSelected3(bool selected){diceSelectedState_.set(3, selected); setCorrectCheckBit();}
                inline void setDiceSelected4(bool selected){diceSelectedState_.set(4, selected); setCorrectCheckBit();}
                //CheckBit Getter and Setter
                inline bool getCheckBit(){return diceSelectedState_[5];}
                inline void setCheckBit(bool checkBit){diceSelectedState_.set(5, checkBit);}
                //Constructor
                DiceSelectedState(std::bitset <6> diceSelectedState);
                DiceSelectedState(std::bitset <6> diceSelectedState, bool setCheckBit);
            private:
                std::bitset<6> diceSelectedState_;
                bool setCheckBit_; //If CheckBit should be set after Edit
        };
        class FullYahtzeeState{
            public:
                //If CheckBit should be Set after an action
                inline void setCheckBitAfterEdit(bool checkBit){setCheckBit_=checkBit;}
                inline bool getCheckBitAfterEdit(){return setCheckBit_;}
                //CheckBit 1 if times of 1 is even 0 if odd. Last Bit
                inline bool getCorrectCheckBit(){return yahtzee::bitsettools::getCorrectCheckBit(&fullYahtzeeState_);}
                inline bool verifyCheckBit(){return yahtzee::bitsettools::verifyCheckBit(&fullYahtzeeState_);}
                inline void setCorrectCheckBit(){yahtzee::bitsettools::setCorrectCheckBit(&fullYahtzeeState_, setCheckBit_);} //Will be called after each set.
                inline void setCorrectCheckBitIgnore(){yahtzee::bitsettools::setCorrectCheckBit(&fullYahtzeeState_, true);}
                //Global Gets and Sets
                inline std::bitset<43> getFullYahtzeeState(){return fullYahtzeeState_;}
                inline void setFullYahtzeeState(std::bitset<43> fullYahtzeeState){fullYahtzeeState_=fullYahtzeeState; setCorrectCheckBit();}
                inline unsigned long getFullYahtzeeStateL(){return fullYahtzeeState_.to_ulong();}
                inline void setFullYahtzeeStateL(unsigned long fullYahtzeeState){std::bitset<43> Temp(fullYahtzeeState); fullYahtzeeState_=Temp; setCorrectCheckBit();}
                //Top Block Bit 0-17
                //Top Block Getter 0 js not filled 6 is cancelled. 7 is reserved and should not be used for anything
                inline unsigned long getAcesL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(0, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getTwosL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(3, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getThreesL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(6, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getFoursL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(9, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getFivesL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(12, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getSixesL(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(15, &fullYahtzeeState_).to_ulong();}
                inline std::bitset<3> getAces(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(0, &fullYahtzeeState_);}
                inline std::bitset<3> getTwos(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(3, &fullYahtzeeState_);}
                inline std::bitset<3> getThrees(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(6, &fullYahtzeeState_);}
                inline std::bitset<3> getFours(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(9, &fullYahtzeeState_);}
                inline std::bitset<3> getFives(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(12, &fullYahtzeeState_);}
                inline std::bitset<3> getSixes(){return yahtzee::bitsettools::CopyBitsFromBitSet<3>(15, &fullYahtzeeState_);}
                //Top Block Setter
                inline void setAcesL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(0, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setTwosL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(3, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setThreesL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(6, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFoursL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(9, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFivesL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(12, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setSixesL(unsigned long int times){std::bitset<3> Temp(times); yahtzee::bitsettools::CopyBitsToBitSet(15, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setAces(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(0, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setTwos(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(3, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setThrees(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(6, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFours(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(9, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFives(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(12, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setSixes(std::bitset<3> times){yahtzee::bitsettools::CopyBitsToBitSet(15, &times, &fullYahtzeeState_); setCorrectCheckBit();}
                //Bottom Block (Three of a kind, Four of a Kind, Chance) Bit 18-33
                //Bottom Block Getter 0 is not filled 31 is cancelled. 5bit each
                inline unsigned long getThreeOfAKindL(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(18, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getFourOfAKindL(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(23, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getChanceL(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(28, &fullYahtzeeState_).to_ulong();}
                inline std::bitset<5> getThreeOfAKind(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(18, &fullYahtzeeState_);}
                inline std::bitset<5> getFourOfAKind(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(23, &fullYahtzeeState_);}
                inline std::bitset<5> getChance(){return yahtzee::bitsettools::CopyBitsFromBitSet<5>(28, &fullYahtzeeState_);}
                //Bottom Block Setter
                inline void setThreeOfAKindL(unsigned long int diceEyes){std::bitset<5> Temp(diceEyes); yahtzee::bitsettools::CopyBitsToBitSet(18, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFourOfAKindL(unsigned long int diceEyes){std::bitset<5> Temp(diceEyes); yahtzee::bitsettools::CopyBitsToBitSet(23, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setChanceL(unsigned long int diceEyes){std::bitset<5> Temp(diceEyes); yahtzee::bitsettools::CopyBitsToBitSet(28, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setThreeOfAKind(std::bitset<5> diceEyes){yahtzee::bitsettools::CopyBitsToBitSet(18, &diceEyes, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFourOfAKind(std::bitset<5> diceEyes){yahtzee::bitsettools::CopyBitsToBitSet(23, &diceEyes, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setChance(std::bitset<5> diceEyes){yahtzee::bitsettools::CopyBitsToBitSet(28, &diceEyes, &fullYahtzeeState_); setCorrectCheckBit();}
                //Bottom Block (fullHouse smallStraight largeStraight yahtzee) Bit 34-41.
                //Bottom Block Getter 0 is not filled 1 is filled 2 is cancelled. 2bit each 3 is you used a Yahzee to fill the catgorie
                inline unsigned long getFullHouseL(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(34, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getSmallStraightL(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(36, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getLargeStraightL(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(38, &fullYahtzeeState_).to_ulong();}
                inline unsigned long getYahtzeeL(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(40, &fullYahtzeeState_).to_ulong();}
                inline std::bitset<2> getFullHouse(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(34, &fullYahtzeeState_);}
                inline std::bitset<2> getSmallStraight(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(36, &fullYahtzeeState_);}
                inline std::bitset<2> getLargeStraight(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(38, &fullYahtzeeState_);}
                inline std::bitset<2> getYahtzee(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(40, &fullYahtzeeState_);}
                //Bottom Block Setter
                inline void setFullHouseL(unsigned long int status){std::bitset<2> Temp(status); yahtzee::bitsettools::CopyBitsToBitSet(34, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setSmallStraightL(unsigned long int status){std::bitset<2> Temp(status); yahtzee::bitsettools::CopyBitsToBitSet(36, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setLargeStraightL(unsigned long int status){std::bitset<2> Temp(status); yahtzee::bitsettools::CopyBitsToBitSet(38, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setYahtzeeL(unsigned long int status){std::bitset<2> Temp(status); yahtzee::bitsettools::CopyBitsToBitSet(40, &Temp, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setFullHouse(std::bitset<2> status){yahtzee::bitsettools::CopyBitsToBitSet(34, &status, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setSmallStraight(std::bitset<2> status){yahtzee::bitsettools::CopyBitsToBitSet(36, &status, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setLargeStraight(std::bitset<2> status){yahtzee::bitsettools::CopyBitsToBitSet(38, &status, &fullYahtzeeState_); setCorrectCheckBit();}
                inline void setYahtzee(std::bitset<2> status){yahtzee::bitsettools::CopyBitsToBitSet(40, &status, &fullYahtzeeState_); setCorrectCheckBit();}
                //Bit 41 Check Bit
                //CheckBit Getter and Setter
                inline bool getCheckBit(){return fullYahtzeeState_[42];}
                inline void setCheckBit(bool checkBit){fullYahtzeeState_.set(42, checkBit);}
                //Constructor
                FullYahtzeeState(std::bitset <43> fullYahtzeeState);
                FullYahtzeeState(std::bitset <43> fullYahtzeeState, bool setCheckBit);
            private:
                std::bitset<43> fullYahtzeeState_;
                bool setCheckBit_; //If CheckBit should be set after Edit
        };
        class LastMoveState{ //Used in the .yahtzee File to save a game effective it only contains the Last move and begins with
            public:
                //If CheckBit should be Set after an action
                inline void setCheckBitAfterEdit(bool checkBit){setCheckBit_=checkBit;}
                inline bool getCheckBitAfterEdit(){return setCheckBit_;}
                //CheckBit 1 if times of 1 is even 0 if odd, first 3 bits will be ignored. Last Bit
                //LastMove is defined as 0 no move 1-6 Aces to Six 7 Three of a kind 8 four of a kind 9 Full House 10 small straight 11 large straight 12 Yahtzee 13 Chance 14-15 not yet defined.
                inline bool getCorrectCheckBit(){return yahtzee::bitsettools::getCorrectCheckBit(&lastMove_);}
                inline bool verifyCheckBit(){return yahtzee::bitsettools::verifyCheckBit(&lastMove_);}
                inline void setCorrectCheckBit(){yahtzee::bitsettools::setCorrectCheckBit(&lastMove_, setCheckBit_);} //Will be called after each set.
                inline void setCorrectCheckBitIgnore(){yahtzee::bitsettools::setCorrectCheckBit(&lastMove_, true);}
                //Global
                std::bitset<7> getLastMove(){std::bitset<7> Temp; Temp.set(); yahtzee::bitsettools::CopyBitsToBitSet(2, &lastMove_, &Temp); setCorrectCheckBit(); return Temp;}
                unsigned long getLastMoveL(){std::bitset<7> Temp; Temp.set(); yahtzee::bitsettools::CopyBitsToBitSet(2, &lastMove_, &Temp); setCorrectCheckBit(); return Temp.to_ulong();}
                void setLastMove(std::bitset<5> lastMove){lastMove_=lastMove; setCorrectCheckBit();};
                void setLastMoveL(unsigned long lastMove){std::bitset<5> Temp(lastMove); lastMove_=Temp; setCorrectCheckBit();};
                //Bit 4 Check Bit
                //CheckBit Getter and Setter
                inline bool getCheckBit(){return lastMove_[4];}
                inline void setCheckBit(bool checkBit){lastMove_.set(4, checkBit);}
                //Constructor
                LastMoveState(std::bitset <5> LastMoveState, bool setCheckBit);
                LastMoveState(std::bitset <5> LastMoveState);
            private:
                std::bitset<5> lastMove_;
                bool setCheckBit_;
        };
        class GameState{
            public:
                //If CheckBit should be Set after an action
                inline void setCheckBitAfterEdit(bool checkBit){setCheckBit_=checkBit;}
                inline bool getCheckBitAfterEdit(){return setCheckBit_;}
                //CheckBit 1 if times of 1 is even 0 if odd. Last Bit.
                inline bool getCorrectCheckBit(){return yahtzee::bitsettools::getCorrectCheckBit(&gameState_);}
                inline bool verifyCheckBit(){return yahtzee::bitsettools::verifyCheckBit(&gameState_);}
                inline void setCorrectCheckBit(){yahtzee::bitsettools::setCorrectCheckBit(&gameState_, setCheckBit_);} //Will be called after each set.
                inline void setCorrectCheckBitIgnore(){yahtzee::bitsettools::setCorrectCheckBit(&gameState_, true);}
                //GameState
                std::bitset<7> getGameState(){return gameState_;}
                void setGameState(std::bitset<7> gameState){gameState_=gameState;}
                unsigned long getGameStateL(){return gameState_.to_ulong();}
                void setGameStateL(unsigned long gameState){std::bitset<7> Temp(gameState); gameState_=Temp;}
                //Contains The State of the Dices which are selected and the full state of the Catogories
                DiceState getDiceState(){return diceState_;}
                DiceSelectedState getDiceSelectedState(){return diceSelectedState_;}
                FullYahtzeeState getFullYahtzeeState(){return fullYahtzeeState_;}
                void setDiceState(DiceState diceState){diceState_ = diceState;}
                void setDiceSelectedState(DiceSelectedState diceSelectedState){diceSelectedState_ = diceSelectedState;}
                void setFullYahtzeeState(FullYahtzeeState fullYahtzeeState){fullYahtzeeState_ = fullYahtzeeState;}
                //Get and Set Move
                //0 before the first dice 1 after the first dice 2 after the second dice 3 after the third dice
                inline std::bitset<2> getMove(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(0, &gameState_);}
                inline unsigned long getMoveL(){return yahtzee::bitsettools::CopyBitsFromBitSet<2>(0, &gameState_).to_ulong();}
                inline void setMove(std::bitset<2> moves){yahtzee::bitsettools::CopyBitsToBitSet(0, &moves, &gameState_); setCorrectCheckBit();}
                inline void setMoveL(unsigned long int moves){std::bitset<2> Temp(moves); yahtzee::bitsettools::CopyBitsToBitSet(0, &Temp, &gameState_); setCorrectCheckBit();}
                //Get and Set Move
                //Saves the times of a Yahtzee, should be incremented if a Yahtzee is used to fill any Categories also the Yahtzee Category
                inline std::bitset<4> getTimesOfYahtzee(){return yahtzee::bitsettools::CopyBitsFromBitSet<4>(2, &gameState_);}
                inline unsigned long getTimesOfYahtzeeL(){return yahtzee::bitsettools::CopyBitsFromBitSet<4>(2, &gameState_).to_ulong();}
                inline void setTimesOfYahtzee(std::bitset<4>  moves){yahtzee::bitsettools::CopyBitsToBitSet(2, &moves, &gameState_); setCorrectCheckBit();}
                inline void setTimesOfYahtzeeL(unsigned long int moves){std::bitset<4> Temp(moves); yahtzee::bitsettools::CopyBitsToBitSet(2, &Temp, &gameState_); setCorrectCheckBit();}
                inline void incrementTimesOfYahtzee(){std::bitset<4> Temp(getTimesOfYahtzeeL()+1); yahtzee::bitsettools::CopyBitsToBitSet(2, &Temp, &gameState_); setCorrectCheckBit();}
                //Get and Set Last Move
                inline uint8_t getLastMove(){return lastMove_;}
                inline void setLastMove(uint8_t lastMove){lastMove_=lastMove;}
                inline void incrementLastMove(){++lastMove_;}
                //Get Last Move State Class
                inline LastMoveState getLastMoveState(){std::bitset <5> lastMoveStateBitSet(lastMove_); LastMoveState classLastMoveState(lastMoveStateBitSet); return classLastMoveState;}
                //Bit 6 Check Bit
                //CheckBit Getter and Setter
                inline bool getCheckBit(){return gameState_[6];}
                inline void setCheckBit(bool checkBit){gameState_.set(6, checkBit);}
            private:
                DiceState diceState_;
                DiceSelectedState diceSelectedState_;
                FullYahtzeeState fullYahtzeeState_;
                std::bitset<7> gameState_;
                uint8_t lastMove_;
                bool setCheckBit_;
        };
    }
}
#endif
