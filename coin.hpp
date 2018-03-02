/*
        Coin Declarations
*/

#ifndef COIN_HPP
#define COIN_HPP

#include <string>
#include <cstdlib>
#include <ctime>

class Coin{
private:
        int heads;
        int tails;

public:
        Coin();
        std::string flip();
        int getHeads();
        int getTails();
};

#endif
