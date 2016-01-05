#include <string>

#include "datacontroler.h"
#include "cli/cmdinterface.h"

void DataControler::showGuess(std::vector<unsigned int> guess_colors){
    CMDInterface::guess();
    CMDInterface::printColors(guess_colors);
}

void DataControler::showSolution(std::vector<unsigned int> guess_colors){
    CMDInterface::show();
    CMDInterface::printColors(guess_colors);
}

void DataControler::notSolved(){
    CMDInterface::print("Hlavolam jeste neni vyreseny.");
}

void DataControler::echoItsOnYou(){
    std::string s = "Vy jste zadával ohodnocení....";
    CMDInterface::print(s);
}

std::vector<bool> DataControler::readClues(){
    return CMDInterface::readClues();
}
