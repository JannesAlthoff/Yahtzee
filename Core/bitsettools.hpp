#ifndef BITSETTOOLSYAHTZEE_HPP
#define BITSETTOOLSYAHTZEE_HPP

#include <bitset> //BitSets
#include <stdexcept> //Exceptions

namespace yahtzee{
    namespace bitsettools{
        //Needs length from the extraction of the BitSet and a start where to start extraction from the BitSet, which should be the second Parameter.
        template <std::size_t length, std::size_t lengthBitSet> std::bitset<length> CopyBitsFromBitSet(unsigned int start, std::bitset<lengthBitSet> *BitSet){
            if (start + length > lengthBitSet) {
                throw std::invalid_argument("Out of Border");
            }
            std::bitset<length> CopyBitSet;
            for (unsigned int i = 0; i < length; i++) {
                CopyBitSet.set(i, (*BitSet)[i + start]);
            }
            return CopyBitSet;
        }
        //Copy A BitSet into a Bigger BitSet Start is defined as Start of the smaller BitSet in the Bigger BitSet.
        template <std::size_t lengthBitSetFrom, std::size_t lengthBitSetTo> void CopyBitsToBitSet(unsigned int start, std::bitset<lengthBitSetFrom> *BitSetFrom, std::bitset<lengthBitSetTo> *BitSetTo){
            if (start + lengthBitSetFrom > lengthBitSetTo) {
                throw std::invalid_argument("Out of Border");
            }
            for (unsigned int i = 0; i < lengthBitSetFrom; i++) {
                (*BitSetTo).set(i+start, (*BitSetFrom)[i]);
            }
        }
        //Get the correct Check Bit for a BitSet Correct is when even 1 odd 0 CheckBit is the last Bit
        template <std::size_t lengthBitSet> bool getCorrectCheckBit(std::bitset<lengthBitSet> *BitSet){
            int ones = 0;
            for(unsigned int i=0; i<(lengthBitSet-1); i++){
                if ((*BitSet)[i] == true){
                    ++ones;
                }
            }
            if (ones%2==0){ //even
                return true;
            } else { //odd
                return false;
            }
        }
        template <std::size_t lengthBitSet> bool verifyCheckBit(std::bitset<lengthBitSet> *BitSet){
            if ((*BitSet)[lengthBitSet-1] == getCorrectCheckBit(BitSet)){
                return true;
            } else {
                return false;
            }
        }
        template <std::size_t lengthBitSet> void setCorrectCheckBit(std::bitset<lengthBitSet> *BitSet, bool setCheckBit){
            if ((!verifyCheckBit(BitSet)) && setCheckBit){
                (*BitSet).flip(lengthBitSet-1);
            }
        }
    }
}
#endif
