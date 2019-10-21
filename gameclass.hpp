#ifndef GAMECLASSYAHTZEE_HPP
#define GAMECLASSYAHTZEE_HPP

#include <bitset>
#include <random> //Random
#include "state.hpp"
namespace yahtzee{
    class GameClass{
        private:
            //Categories is defined as 0 no move 1-6 Aces to Six 7 Three of a kind 8 four of a kind 9 Full House 10 small straight 11 large straight 12 Yahtzee 13 Chance 14-15 not yet defined.
            void selectCategorie(uint8_t category);
            void rollDices();
            uint8_t countDices(uint8_t DiceEyes);
            void selectCategory(uint8_t category);
            inline void selectDice(uint8_t dice){gameState_.getDiceSelectedState().setDiceSelected(dice, true);}
            inline void selectDiceAll(){for(int i=0; i<5; i++){gameState_.getDiceSelectedState().setDiceSelected(i, true);}}
            inline void deselectDiceAll(){for(int i=0; i<5; i++){gameState_.getDiceSelectedState().setDiceSelected(i, false);}}
            inline void setSelectDice(uint8_t dice, bool select){gameState_.getDiceSelectedState().setDiceSelected(dice, select);}
            inline void deselectDice(uint8_t dice){gameState_.getDiceSelectedState().setDiceSelected(dice, false);}
            inline std::bitset<5> getSelectDices(){std::bitset<6> Temp = gameState_.getDiceSelectedState().getDiceSelectedSet(); return yahtzee::bitsettools::CopyBitsFromBitSet<5>(0, &Temp);}
            inline unsigned long getSelectDice(uint8_t dice){return gameState_.getDiceSelectedState().getDiceSelected(dice);}
            //GameState Get and Set should not be used. Use it only when you need specific data out of the States
            inline yahtzee::state::GameState getGameState(){return gameState_;}
            inline void setGameState(yahtzee::state::GameState gameState){gameState_=gameState;}
            //Last Move Package. Used in the .yahtzee file
            inline yahtzee::state::LastMoveState getLastMoveState(){return gameState_.getLastMoveState();}
            inline std::bitset<7> getLastMoveStateBitSet(){return gameState_.getLastMoveState().getLastMove();}
            inline unsigned long getLastMoveStateBitSetL(){return gameState_.getLastMoveState().getLastMoveL();}
        private:
            void rollADice(uint8_t dice);
            void rollADiceFull();
            void rollADiceSelected();
            std::default_random_engine generator_;
            yahtzee::state::GameState gameState_; //Contains Full Current state.
    };
}
#endif