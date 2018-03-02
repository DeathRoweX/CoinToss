include <iostream>
#include "coin.hpp"

void test(Coin& coin, unsigned int n, bool v){
        for(unsigned int i = 0; i <= n; i++){
                std::string result = coin.flip();
                if(v){
                        std::cout << result << std::endl;
                }
        }
}


int main(void){

        const unsigned int NUMBER_OF_TRIALS = 12500000;
        const std::string EXPECTED_RESULT = "heads";
        const unsigned int NUMBER_OF_EXPECTED_RESULTS = 6248000;
        const bool VERBOSE = false;

        std::srand(std::time(nullptr));

        Coin coin;

        test(coin, NUMBER_OF_TRIALS, VERBOSE);

        long double headsAvg = (long double)(coin.getHeads())/NUMBER_OF_TRIALS;
        long double tailsAvg = (long double)(coin.getTails())/NUMBER_OF_TRIALS;
        long double percentOffset = (long double)(NUMBER_OF_EXPECTED_RESULTS)/NUMBER_OF_TRIALS;

        std::cout << "Trials: " << NUMBER_OF_TRIALS << std::endl;
        std::cout << "Total Heads: " << coin.getHeads() << std::endl;
        std::cout << "Total Tails: " << coin.getTails() << std::endl;


        std::cout << "Percent Heads: " << headsAvg << std::endl;
        std::cout << "Percent Tails: " << tailsAvg << std::endl;


        std::cout << "\nExpected Result: " << EXPECTED_RESULT << std::endl;
        std::cout << "Expected Total: " << NUMBER_OF_EXPECTED_RESULTS << std::endl;
        std::cout << "Percent Expected: "  << percentOffset << std::endl;
        switch(EXPECTED_RESULT[0]){
                case 'h':
                        std::cout << "Total Offset: " << coin.getHeads() - NUMBER_OF_EXPECTED_RESULTS << std::endl;
                        std::cout << "Percent Offset: " << headsAvg - percentOffset << std::endl;
                        break;
                case 't':
                        std::cout << "Total Offset: " << coin.getTails() - NUMBER_OF_EXPECTED_RESULTS << std::endl;
                        std::cout << "Percent Offset: " << tailsAvg - percentOffset << std::endl;
                        break;
        }

        return 0;
}

