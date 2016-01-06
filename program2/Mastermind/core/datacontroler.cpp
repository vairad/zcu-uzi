#include <string>

#include "datacontroler.h"

#include "cli/cmdinterface.h"

/**
 * Zobrazí odhad počítače.
 * @brief DataControler::showGuess
 * @param guess_colors pole odhadu
 */
void DataControler::showGuess(std::vector<unsigned int> guess_colors){
    CMDInterface::guess();
    CMDInterface::printColors(guess_colors);
}

/**
 * Zobrazí řešení počítače
 * @brief DataControler::showSolution
 * @param solution_colors
 */
void DataControler::showSolution(std::vector<unsigned int> solution_colors){
    CMDInterface::show();
    CMDInterface::printColors(solution_colors);
}

/**
 * Upozorní, že hlavolam nebyl vyřešen
 * @brief DataControler::notSolved
 */
void DataControler::notSolved(){
    CMDInterface::print("Hlavolam jeste neni vyreseny.");
}

/**
 * Upozorní, že není možné zobrazitřešení, protože ho stroj nezná.
 * @brief DataControler::echoItsOnYou
 */
void DataControler::echoItsOnYou(){
    std::string s = "Nelze zobrazit správné řešení ke kontrole, znáte ho jen Vy.";
    CMDInterface::print(s);
}

/**
 * Načte ohodnocení od uživatele.
 * kde true znamená správné místo a barvu
 * kde false znamená správnou barvu
 * @brief DataControler::readClues
 * @return vektor ohodnocení
 */
std::vector<bool> DataControler::readClues(){
    return CMDInterface::readClues();
}
