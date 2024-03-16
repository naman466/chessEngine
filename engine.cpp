#include "board.h"

#include <iostream>

int main(){


    for(int i = 0; i < NUM_SQUARES; i++) {
        if(i%10==0){
            std::cout << " " << std::endl;
        }
        std::cout << map120to64[i] << " ";
    }

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    for(int i = 0; i < 64; i++) {
        if(i%8==0){
            std::cout << " " << std::endl;
        }
        std::cout << map64to120[i] << " ";
    }

    return 0;
}