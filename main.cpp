#include <iostream>
#include "state.hpp"
#include "gameclass.hpp"

int main()
{
    std::bitset <6> state;
    yahtzee::state::DiceSelectedState DiceSelectedState(state, false);
    DiceSelectedState.setDiceSelected0(true);
    DiceSelectedState.setDiceSelected1(false);
    DiceSelectedState.setDiceSelected2(true);
    DiceSelectedState.setDiceSelected3(false);
    DiceSelectedState.setDiceSelected4(false);
    DiceSelectedState.setCorrectCheckBitIgnore();
    std::cout << DiceSelectedState.verifyCheckBit() << " " << DiceSelectedState.getDiceSelectedSet().to_string() << " " << DiceSelectedState.getDiceSelected0() << DiceSelectedState.getDiceSelected1() << DiceSelectedState.getDiceSelected2() << DiceSelectedState.getDiceSelected3() << DiceSelectedState.getDiceSelected4() <<std::endl;
    return 0;
}
