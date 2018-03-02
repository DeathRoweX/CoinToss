/*
        Coin Definitions
*/

#ifndef COIN_CPP
#define COIN_CPP

#include <iostream>
#include "coin.hpp"

Coin::Coin(){
        heads = 0;
        tails = 0;
}

std::string Coin::flip(){
        if(std::rand() % 10000 < 5000){
                ++heads;
                return "heads";
        } else {
                ++tails;
                return "tails";
        }
}

int Coin::getHeads(){
        return heads;
}

int Coin::getTails(){
        return tails;
}

#endif
