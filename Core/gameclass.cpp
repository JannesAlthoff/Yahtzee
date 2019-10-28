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
#include <random> //Random
#include <array>
#include <stdexcept> //Exceptions
#include <algorithm>
#include "state.hpp"
#include "gameclass.hpp"
namespace yahtzee{
    //Straight
    void GameClass::selectCategory(uint8_t category){
        if(gameState_.getMoveL()==0){
            throw std::logic_error("You cannot select a Category before you have rolled the dice the first time.");
        }
        //If filled
        switch(category){
            case 1:
                if(gameState_.getFullYahtzeeState().getAcesL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 2:
                if(gameState_.getFullYahtzeeState().getTwosL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 3:
                if(gameState_.getFullYahtzeeState().getThreesL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 4:
                if(gameState_.getFullYahtzeeState().getFoursL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 5:
                if(gameState_.getFullYahtzeeState().getFivesL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 6:
                if(gameState_.getFullYahtzeeState().getSixesL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 7: //Three of A Kind
                if(gameState_.getFullYahtzeeState().getThreeOfAKindL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 8: //Four of A Kind
                if(gameState_.getFullYahtzeeState().getFourOfAKindL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 9: //FullHouse
                if(gameState_.getFullYahtzeeState().getFullHouseL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 10: //small straight
                if(gameState_.getFullYahtzeeState().getSmallStraightL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 11: //large straight
                if(gameState_.getFullYahtzeeState().getLargeStraightL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 12: //Yahtzee
                if(gameState_.getFullYahtzeeState().getYahtzeeL()!=0){throw std::logic_error("Already Filled"); return;} break;
            case 13: //Chance
                if(gameState_.getFullYahtzeeState().getChanceL()!=0){throw std::logic_error("Already Filled"); return;} break;
        }
        unsigned long int DicesCount;
        switch(category){
            case 0:
                throw std::logic_error("You must select a Category."); break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                DicesCount = countDices(category);
                if(DicesCount == 0){
                    DicesCount=6;
                }
                if(DicesCount == 5){
                    gameState_.incrementTimesOfYahtzee();
                }
                switch(category){
                    case 1:
                        gameState_.getFullYahtzeeState().setAcesL(DicesCount); break;
                    case 2:
                        gameState_.getFullYahtzeeState().setTwosL(DicesCount); break;
                    case 3:
                        gameState_.getFullYahtzeeState().setThreesL(DicesCount); break;
                    case 4:
                        gameState_.getFullYahtzeeState().setFoursL(DicesCount); break;
                    case 5:
                        gameState_.getFullYahtzeeState().setFivesL(DicesCount); break;
                    case 6:
                        gameState_.getFullYahtzeeState().setSixesL(DicesCount); break;
                    default:
                        throw std::logic_error("How???");
                }
                break;
            case 7: //Three of A Kind
            case 8: //Four of A Kind
            case 9: //FullHouse
            case 10: //small straight
            case 11: //large straight
            case 12: //Yahtzee
            case 13: //Chance
                DicesCount = gameState_.getDiceState().getDice0L()+gameState_.getDiceState().getDice1L()+gameState_.getDiceState().getDice2L()+gameState_.getDiceState().getDice3L()+gameState_.getDiceState().getDice4L();
                if(((gameState_.getDiceState().getDice0L()==gameState_.getDiceState().getDice1L())&&(gameState_.getDiceState().getDice2L() == gameState_.getDiceState().getDice3L())) && ((gameState_.getDiceState().getDice4L()==gameState_.getDiceState().getDice1L()) && (gameState_.getDiceState().getDice4L()==gameState_.getDiceState().getDice3L()))){
                    gameState_.incrementTimesOfYahtzee();
                    if(category==13){
                        gameState_.getFullYahtzeeState().setYahtzeeL(1);
                    }
                } else if(category==13){
                    gameState_.getFullYahtzeeState().setYahtzeeL(2);
                }
                switch(category){
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        std::array<unsigned long, 5> Temp;
                        for(int i = 0; i < 5; i++){
                            Temp[i] = gameState_.getDiceState().getDiceL(i);
                        }
                        std::sort(Temp.begin(), Temp.end());
                        switch(category){
                            case 7:
                                if((((Temp.at(0)==Temp.at(1))&&(Temp.at(1)==Temp.at(2)))||((Temp.at(1)==Temp.at(2))&&(Temp.at(2)==Temp.at(3)))||((Temp.at(2)==Temp.at(3))&&(Temp.at(3)==Temp.at(4))))){
                                    gameState_.getFullYahtzeeState().setThreeOfAKindL(DicesCount);
                                } else {
                                    gameState_.getFullYahtzeeState().setThreeOfAKindL(31);
                                }
                                break;
                            case 8:
                                if(((Temp.at(0)==Temp.at(1))&&(Temp.at(2)==Temp.at(3))&&(Temp.at(3)==Temp.at(1)))||((Temp.at(1)==Temp.at(2))&&(Temp.at(3)==Temp.at(4))&&(Temp.at(4)==Temp.at(1)))){
                                    gameState_.getFullYahtzeeState().setFourOfAKindL(DicesCount);
                                } else {
                                    gameState_.getFullYahtzeeState().setFourOfAKindL(31);
                                }
                                break;
                            case 9:
                                if(((Temp.at(0)==Temp.at(1))&&(Temp.at(1)==Temp.at(2))&&(Temp.at(3)==Temp.at(3)))||((Temp.at(0)==Temp.at(1))&&(Temp.at(2)==Temp.at(3))&&(Temp.at(3)==Temp.at(4)))){
                                    gameState_.getFullYahtzeeState().setFullHouseL(1);
                                } else {
                                    gameState_.getFullYahtzeeState().setFullHouseL(2);                                    
                                }
                                break;
                            case 10:
                                if(((Temp.at(0)==1)&&(Temp.at(1)==2)&&(Temp.at(2)==3)&&(Temp.at(3)==4))||((Temp.at(0)==2)&&(Temp.at(1)==3)&&(Temp.at(2)==4)&&(Temp.at(3)==5))||((Temp.at(0)==3)&&(Temp.at(1)==4)&&(Temp.at(2)==5)&&(Temp.at(3)==6))||((Temp.at(1)==1)&&(Temp.at(2)==2)&&(Temp.at(3)==3)&&(Temp.at(4)==4))||((Temp.at(1)==2)&&(Temp.at(2)==3)&&(Temp.at(3)==4)&&(Temp.at(4)==5))||((Temp.at(1)==3)&&(Temp.at(2)==4)&&(Temp.at(3)==5)&&(Temp.at(4)==6))){
                                    gameState_.getFullYahtzeeState().setSmallStraightL(1);
                                }  else {
                                    gameState_.getFullYahtzeeState().setSmallStraightL(2);                                 
                                }  
                                break;
                            case 11:
                                if(((Temp.at(0)==1)&&(Temp.at(1)==2)&&(Temp.at(2)==3)&&(Temp.at(3)==4)&&(Temp.at(4)==5))||((Temp.at(0)==2)&&(Temp.at(1)==3)&&(Temp.at(2)==4)&&(Temp.at(3)==5)&&(Temp.at(4)==6))){
                                    gameState_.getFullYahtzeeState().setLargeStraightL(1);
                                } else {
                                    gameState_.getFullYahtzeeState().setLargeStraightL(2);
                                }
                        }
                        break;
                    case 13:
                        gameState_.getFullYahtzeeState().setChanceL(DicesCount);
                        break;
                    default:
                        throw std::logic_error("How???"); break;
                }
            }
        gameState_.setLastMove(category);
        gameState_.setMoveL(0);
    }
    uint8_t GameClass::countDices(uint8_t DiceEyes){
        uint8_t Temp(0);
        for(uint8_t i = 0; i<5; i++){
            if(gameState_.getDiceState().getDiceL(i) == DiceEyes){
                ++Temp;
            }
        }
        return Temp;
    }
    void GameClass::rollADice(uint8_t dice){
        if ((dice>=0) && (dice<=4)) {
            std::uniform_int_distribution<unsigned long> distribution(1,6);
            gameState_.getDiceState().setDiceL(dice,distribution(generator_));
        } else {
            throw std::out_of_range("Out of Range");
        }
    }
    void GameClass::rollADiceFull(){
        bool verify = gameState_.getDiceState().getVerify();
        bool checkBit = gameState_.getDiceState().getCheckBitAfterEdit();
        gameState_.getDiceState().setVerify(false);
        for(uint8_t dice = 0; dice<5; dice++){
            rollADice(dice);
        }
        gameState_.incrementLastMove();

        gameState_.getDiceState().setVerify(verify);
        gameState_.getDiceState().setCheckBitAfterEdit(checkBit);
        gameState_.getDiceState().verifyIntegrityFull();
        gameState_.getDiceState().setCorrectCheckBit();
    }
    void GameClass::rollADiceSelected(){
        bool checkBitDiceSelected = gameState_.getDiceSelectedState().getCheckBitAfterEdit();
        bool verify = gameState_.getDiceState().getVerify();
        bool checkBitDice = gameState_.getDiceState().getCheckBitAfterEdit();
        for(uint8_t dice = 0; dice<5; dice++){
            if(gameState_.getDiceSelectedState().getDiceSelected(dice)){
                rollADice(dice);
            }
        }
        gameState_.incrementLastMove();

        gameState_.getDiceSelectedState().setCheckBitAfterEdit(checkBitDiceSelected);
        gameState_.getDiceSelectedState().setCorrectCheckBit();
        gameState_.getDiceState().setVerify(verify);
        gameState_.getDiceState().setCheckBitAfterEdit(checkBitDice);
        gameState_.getDiceState().verifyIntegrityFull();
        gameState_.getDiceState().setCorrectCheckBit();
    }
    void GameClass::rollDices(){
        if(getSelectDices().to_ulong() == 0){
            throw std::logic_error("Why??");
        }
        if(gameState_.getMoveL()==0){
            selectDiceAll();
        }
        if (gameState_.getMoveL()>=3){
            deselectDiceAll();
            throw std::logic_error("Not Possible");
        }
        rollADiceSelected();
        if (gameState_.getMoveL()>=2){
            deselectDiceAll();
        }
    }
}
