//By Jannes Althoff

#include <bitset> //BitSets
#include <stdexcept> //Exceptions
#include "state.hpp"

namespace yahtzee {
    namespace state {
        //Dice State Class
        void DiceState::setDice(uint8_t Dice, std::bitset<3> TimesOfDice){
            switch(Dice){
                case 0:
                    setDice0(TimesOfDice); break;
                case 1:
                    setDice1(TimesOfDice); break;
                case 2:
                    setDice2(TimesOfDice); break;
                case 3:
                    setDice3(TimesOfDice); break;
                case 4:
                    setDice4(TimesOfDice); break;
                default:
                    throw std::invalid_argument("Out of Range");
            }
            afterEdit(Dice);
        }
        void DiceState::setDiceL(uint8_t Dice, unsigned long int TimesOfDice){
            switch(Dice){
                case 0:
                    setDice0L(TimesOfDice); break;
                case 1:
                    setDice1L(TimesOfDice); break;
                case 2:
                    setDice2L(TimesOfDice); break;
                case 3:
                    setDice3L(TimesOfDice); break;
                case 4:
                    setDice4L(TimesOfDice); break;
                default: throw std::invalid_argument("Out of Range");
            }
            afterEdit(Dice);
        }
        std::bitset<3> DiceState::getDice(uint8_t Dice){
            switch(Dice){
                case 0:
                    return getDice0(); break;
                case 1:
                    return getDice1(); break;
                case 2:
                    return getDice2(); break;
                case 3:
                    return getDice3(); break;
                case 4:
                    return getDice4(); break;
                default:
                    throw std::invalid_argument("Out of Range");
            }
        }
        unsigned long int DiceState::getDiceL(uint8_t Dice){
            switch(Dice){
                case 0:
                    return getDice0L(); break;
                case 1:
                    return getDice1L(); break;
                case 2:
                    return getDice2L(); break;
                case 3:
                    return getDice3L(); break;
                case 4:
                    return getDice4L(); break;
                default:
                    throw std::invalid_argument("Out of Range");
            }
        }
        void DiceState::verifyIntegrity(uint8_t dice){
            int temp = 0;
            for (uint8_t i = dice; i < (dice*3)+3; i++){
                if (diceState_[i]){
                    ++temp;
                }
            }
            if (temp==3){
                for (uint8_t i = dice; i < dice+3; i++){
                    diceState_.set(i,false);
                }
            }
        }
        void DiceState::verifyIntegrityFull(){
            verifyIntegrity(0);
            verifyIntegrity(1);
            verifyIntegrity(2);
            verifyIntegrity(3);
            verifyIntegrity(4);
        }
        DiceState::DiceState(std::bitset <16> diceState):
            diceState_(diceState),
            verify_(true),
            setCheckBit_(true){
                afterEditFull();
        }
        DiceState::DiceState(std::bitset <16> diceState, bool verifyandcheck):
            diceState_(diceState),
            verify_(verifyandcheck),
            setCheckBit_(verifyandcheck){
                afterEditFull();
        }
        DiceState::DiceState(std::bitset <16> diceState, bool verify, bool setCheckBit):
            diceState_(diceState),
            verify_(verify),
            setCheckBit_(setCheckBit){
                afterEditFull();
        }
        //DiceSelectedState Class
        void DiceSelectedState::setDiceSelected(uint8_t Dice, bool selected){
            switch(Dice){
                case 0:
                    setDiceSelected0(selected); break;
                case 1:
                    setDiceSelected1(selected); break;
                case 2:
                    setDiceSelected2(selected); break;
                case 3:
                    setDiceSelected3(selected); break;
                case 4:
                    setDiceSelected4(selected); break;
                default:
                    throw std::invalid_argument("Out of Range");
            }
            setCorrectCheckBit();
        }
        bool DiceSelectedState::getDiceSelected(uint8_t Dice){
            switch(Dice){
                case 0:
                    return getDiceSelected0(); break;
                case 1:
                    return getDiceSelected1(); break;
                case 2:
                    return getDiceSelected2(); break;
                case 3:
                    return getDiceSelected3(); break;
                case 4:
                    return getDiceSelected4(); break;
                default:
                    throw std::invalid_argument("Out of Range");
            }
        }
        DiceSelectedState::DiceSelectedState(std::bitset <6> diceSelectedState):
            diceSelectedState_(diceSelectedState),
            setCheckBit_(true){
                setCorrectCheckBit();
            }
        DiceSelectedState::DiceSelectedState(std::bitset <6> diceSelectedState, bool setCheckBit):
            diceSelectedState_(diceSelectedState),
            setCheckBit_(setCheckBit){
                setCorrectCheckBit();
            }
        //FullYahtzeeState Class
        FullYahtzeeState::FullYahtzeeState(std::bitset <43> fullYahtzeeState):
            fullYahtzeeState_(fullYahtzeeState),
            setCheckBit_(true){
                setCorrectCheckBit();
            }
        FullYahtzeeState::FullYahtzeeState(std::bitset <43> fullYahtzeeState, bool setCheckBit):
            fullYahtzeeState_(fullYahtzeeState),
            setCheckBit_(setCheckBit){
                setCorrectCheckBit();
            }
        //GameState

        //LastMoveState
        LastMoveState::LastMoveState(std::bitset <5> lastMove):
            lastMove_(lastMove),
            setCheckBit_(true){
            }
        LastMoveState::LastMoveState(std::bitset <5> lastMove, bool setCheckBit):
            lastMove_(lastMove),
            setCheckBit_(setCheckBit){
            }
    }
}