#include "cli/cmdinterface.h"
#include <stdlib.h>
#include <limits.h>
#include <algorithm>

unsigned int CMDInterface::getCount(){
    unsigned long number = ULONG_MAX;
    std::string numbuf;

    std::cout << "Zadej číslo (doporučeno 5): "<< "\n";

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

void CMDInterface::spacing(int lines){
    int n = 0;
    while(n < lines){
       std::cout << "\n";
       n++;
    }
}

void CMDInterface::newGame(){
    spacing(6);
    std::cout << "Nová hra právě začíná:" << "\n";
}

void CMDInterface::printInfo(){
    std::cout << "Vítejte v programu AutoMASTERMIND" << "\n";
    std::cout << "Tento program demonstruje automatické strojové řešení logické hry Mastermind." << "\n";
    std::cout << "Jde o algoritmus Donalda Knutha (1977), který redukuje množinu všech řešení za pomoci entropie informace." << "\n";
    std::cout << "\n";
    std::cout << "Jsou k dispozici dva režimy hry:" << "\n";
    std::cout << "\t 1)Ohodnocení tahu určuje počítač" << "\n";
    std::cout << "\t 2)Ohodnocení tahu určuje uživatel" << "\n";
}


/**
 * Nacte vstup oduživatele a seřadí hodnoty true/false v pořadí false ... true
 * @brief DataControler::readClues
 * @return sorted list of clues to solve mastermind
 */
std::vector<bool> CMDInterface::readClues(){
    std::vector<bool> clues;

    std::cout << "Zadej ohodnocení 1 nebo 0 (zadávání ukončte znakem N)" << "\n";

    char read = 0;
    while(read != 'N'){
        std::cout << "ohodnocení (1/0/N): " ;
        std::cin >> read;
        if(read == '0'){
            clues.push_back(false);
        }
        if(read == '1'){
            clues.push_back(true);
        }
    }
    sort(clues.begin(), clues.end());

    std::cout << "Zadal jste ohodnocení tahu";
    for(unsigned int i = 0; i < clues.size(); ++i)
    {
        std::cout << " " << clues.at(i);
    }

    std::cout << "\n";

    return clues;
}

void CMDInterface::printColors(std::vector<unsigned int> guess_colors)
{
    std::cout << "Počítač odhaduje:" << "\n";
    for(unsigned int i = 0; i < guess_colors.size(); ++i)
    {
        std::cout  << "\t" << guess_colors.at(i) << " ";
    }
    std::cout << "\n";
}

void CMDInterface::print(std::string msg){
    std::cout << msg;
}
