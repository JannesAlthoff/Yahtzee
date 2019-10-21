#include <random> //Random
#include <array>
#include <stdexcept> //Exceptions
#include "state.hpp"
#include "gameclass.hpp"
namespace yahtzee{
    void GameClass::selectCategory(uint8_t category){
        if(gameState_.getMoveL()==0){
            throw std::logic_error("You cannot select a Category before you have rolled the dice the first time.");
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
            case 13: //Chance
                DicesCount = gameState_.getDiceState().getDice0L()+gameState_.getDiceState().getDice1L()+gameState_.getDiceState().getDice2L()+gameState_.getDiceState().getDice3L()+gameState_.getDiceState().getDice4L();
                switch(category){
                    case 7:
                    case 8:
                        std::array<unsigned long, 5> Temp;
                        Temp.
                        break;
                    case 13:
                        gameState_.getFullYahtzeeState().setChanceL(DicesCount);
                        break;
                    default:
                        throw std::logic_error("How???"); break;
                }
                if(((gameState_.getDiceState().getDice0L()==gameState_.getDiceState().getDice1L())&&(gameState_.getDiceState().getDice2L() == gameState_.getDiceState().getDice3L())) && ((gameState_.getDiceState().getDice4L()==gameState_.getDiceState().getDice1L()) && (gameState_.getDiceState().getDice4L()==gameState_.getDiceState().getDice3L()))){
                    gameState_.incrementTimesOfYahtzee();
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