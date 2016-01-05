#include "cli/cmdinterface.h"
#include <stdlib.h>
#include <limits.h>

unsigned int CMDInterface::getCount(){
    unsigned long number = ULONG_MAX;
    std::string numbuf;

    std::cout << "Zadej číslo mezi 0 a " << UINT_MAX << ":" << "\n";

    while(number > UINT_MAX){
        std::cin >> numbuf;

        number = strtoul(numbuf.c_str(), 0, 10); //prevod z ascii na long

        if (ULONG_MAX == number && ERANGE == errno){ // pokud přeteče u long
            std::cout << "Číslo je moc velké" << "\n";
            continue;
        }
        if(number > UINT_MAX){ // pokud je vyšší než uint
            std::cout << "Číslo je moc velké" << "\n";
            continue;
        }
    }

    std::cout << "Zadáno: " << number << "\n";
    return (unsigned int)number;
}

unsigned int CMDInterface::getColorsCount(){
    std::cout << "Zadej počet barev" << "\n";
    return getCount();
}

unsigned int CMDInterface::getPlacesCount(){
    std::cout << "Zadej počet pozic" << "\n";
    return getCount();
}

char CMDInterface::getGameType(){
    std::cout << "Zadej typ hry." << "\n";
    std::cout << "Pro ohodnocení počítačem - C" << "\n";
    std::cout << "Pro ohodnocení uživatelem - P" << "\n";

    char read = 0;
    while(read != 'C' && read != 'P'){
        std::cin >> read;
        std::cout << "přečteno: " << read;
    }
    std::cout << "Zadáno: " << read << "\n";
    return read;
}

char CMDInterface::getNextRound(){
    std::cout << "Chcetepokračovat dalším kolem?" << "\n";
    std::cout << "Pro pokračivání zadej - A" << "\n";
    std::cout << "Pro ukončení - N" << "\n";

    char read = 0;
    while(read != 'A' && read != 'N'){
        std::cin >> read;
    }

    std::cout << "Zadáno: " << read << "\n";
    return read;
}

void CMDInterface::printInfo(){
    int n = 0;
    while(n < 5){
       std::cout << "\n";
       n++;
    }
    std::cout << "Vítejte v programu AutoMASTERMIND" << "\n";
    std::cout << "Tento program demonstruje automatické strojové řešení logické hry Mastermind." << "\n";
    std::cout << "Jsou k dispozici dva režimy hry:" << "\n";
    std::cout << "\t 1)Ohodnocení tahu určuje počítač" << "\n";
    std::cout << "\t 2)Ohodnocení tahu určuje uživatel" << "\n";
    std::cout << "\n";
    std::cout << "Nová hra právě začíná:" << "\n";
    std::cout << "\n";



}

