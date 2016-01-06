#include <stdlib.h>
#include <limits.h>
#include <algorithm>

#include "cli/cmdinterface.h"

/**
 * Metoda načítá pouze čísla v rozsahu unsigned int
 * @brief CMDInterface::getCount
 * @return načtené číslo
 */
unsigned int CMDInterface::getUInt(){
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

    std::cout << "Zadáno: " << number << "\n" << "\n";
    return (unsigned int)number;
}

/**
 * Metoda vytiskne výzvu zadání počtu barev a spustí metodu pro načtení čísla @code{getCount}
 * @brief CMDInterface::getColorsCount
 * @return načtené číslo
 */
unsigned int CMDInterface::getColorsCount(){
    std::cout << "Zadej počet barev" << "\n";
    return getUInt();
}

/**
 * Metoda vytiskne výzvu zadání počtu pozic a spustí metodu pro načtení čísla @code{getCount}
 * @brief CMDInterface::getPlacesCount
 * @return načtení čslo
 */
unsigned int CMDInterface::getPlacesCount(){
    std::cout << "Zadej počet pozic" << "\n";
    return getUInt();
}

//###############################################################

/**
 * Metoda načte pouze znaky symbolizující typ hry: C / P
 * @brief CMDInterface::getGameType
 * @return char C / P
 */
char CMDInterface::getGameType(){
    std::cout << "Zadej typ hry." << "\n";
    std::cout << "Pro ohodnocení počítačem - C" << "\n";
    std::cout << "Pro ohodnocení uživatelem - P" << "\n";

    char read = 0;
    while(read != 'C' && read != 'P'){
        std::cin >> read;
    }
    std::cout << "Zadáno: " << read << "\n" << "\n";
    return read;
}

/**
 * Metoda načte pouze znaky symbolizující pokračivání vehře: A / N
 * @brief CMDInterface::getNextRound
 * @return char A / N
 */
char CMDInterface::getNextRound(){
    std::cout << "\n";
    std::cout << "Chcetepokračovat dalším kolem?" << "\n";
    std::cout << "Pro pokračivání zadej - (A)no" << "\n";
    std::cout << "Pro ukončení - (N)e" << "\n";

    char read = 0;
    while(read != 'A' && read != 'N'){
        std::cin >> read;
    }

    std::cout << "Zadáno: " << read << "\n";
    return read;
}

//###################################################################################################################x

/**
 * Odřádkuje dle zadaného počtu
 * @brief CMDInterface::spacing
 * @param lines počet volných řádek
 */
void CMDInterface::spacing(int lines){
    int n = 0;
    while(n < lines){
       std::cout << "\n";
       n++;
    }
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
    std::cout << "\n";

    printClue(clues);

    return clues;
}


/***************************************** Následující metody tisknou dialog se strojem */

/**
 * Vytiskne hodnoty barev do řádky vedle sebe v nezmenenem poradi.
 * @brief CMDInterface::printColors
 * @param guess_colors
 */
void CMDInterface::printColors(std::vector<unsigned int> guess_colors)
{
    for(unsigned int i = 0; i < guess_colors.size(); ++i)
    {
        std::cout  << "\t" << guess_colors.at(i) << " ";
    }
    std::cout << "\n";
}

/**
 * Vytiskne ohodnocení pokusu
 * @brief CMDInterface::printColors
 * @param guess_colors
 */
void CMDInterface::printClue(std::vector<bool> clues)
{
    std::cout << "Ohodnocení tahu je: ";
    for(unsigned int i = 0; i < clues.size(); ++i)
    {
        std::cout << " " << clues.at(i);
    }

    std::cout << "\n";
}


/**
 * Vytiskne libovolnou předanou zprávu.
 * @brief CMDInterface::print
 * @param msg
 */
void CMDInterface::print(std::string msg){
    std::cout << msg  << "\n";
}

/**
 * Úvodní informace o hře.
 * @brief CMDInterface::printInfo
 */
void CMDInterface::printInfo(){
    std::cout << "Vítejte v programu AutoMASTERMIND" << "\n";
    std::cout << "Tento program demonstruje automatické strojové resení logické hry Mastermind." << "\n";
    std::cout << "Jde o algoritmus Donalda Knutha (1977), který redukuje mnozinu vsech resení za pomoci entropie informace." << "\n";
    std::cout << "\n";
    std::cout << "Jsou k dispozici dva rezimy hry:" << "\n";
    std::cout << "\t 1)Ohodnocení tahu urcuje pocítac" << "\n";
    std::cout << "\t 2)Ohodnocení tahu urcuje uzivatel" << "\n";
    std::cout << "\t \t Pro ohodnocení slouzi znaky 1 a 0" << "\n";
    std::cout << "\t \t 1 - symbolizuje správnou barvu na správném míste" << "\n";
    std::cout << "\t \t 0 - symbolizuje správnou barvu na spatném míste" << "\n";
}

/**
 * Úvodní informace při automatické hře.
 * @brief CMDInterface::printAutoInfo
 */
void CMDInterface::printAutoInfo(){
    std::cout << "Vítejte v programu AutoMASTERMIND" << "\n";
    std::cout << "Tento program demonstruje automatické strojové resení logické hry Mastermind." << "\n";
    std::cout << "Jde o algoritmus Donalda Knutha (1977), který redukuje mnozinu vsech resení za pomoci entropie informace." << "\n";
    std::cout << "\n";
    std::cout << "Hra je v automatickém režimu" << "\n";
    std::cout << "Ohodnocení tahu:" << "\n";
    std::cout << "\t 1 - symbolizuje správnou barvu na správném míste" << "\n";
    std::cout << "\t 0 - symbolizuje správnou barvu na spatném míste" << "\n";
}

/**
 * Informace o novém kole
 * @brief CMDInterface::newGame
 */
void CMDInterface::newGame(){
    spacing(3);
    std::cout << "Nová hra právě začíná:" << "\n";
}

void CMDInterface::thinking(){
    std::cout << " ... Premyslim ..."  << "\n";
}

void CMDInterface::strategy(){
    std::cout << " Priravuji seznam reseni..." << "\n";
}

void CMDInterface::congratulation(){
    std::cout << "\n";
    std::cout << "Hlavolam byl uspesne vyresen!" << "\n";
}

void CMDInterface::guess(){
    std::cout << "\n";
    std::cout << "Odhaduji:" << "\n";
}

void CMDInterface::show(){
    std::cout << "\n";
    std::cout << "Ma kombinace byla:" << "\n";
}

void CMDInterface::badPlayer(){
    std::cout << "\n";
    std::cout << "To není možné!" << "\n";
    std::cout << "Opravdu jste zadal správné ohodnocení?!" << "\n";
    std::cout << "\n";
}
