#include "core/usermind.h"
#include "core/exception.h"
#include "core/datacontroler.h"
#include "cli/cmdinterface.h"

#include <iostream>

Usermind::Usermind(int colors, int places)
{
    this->colors = colors;
    this->places = places;
}

std::vector<bool> Usermind::trySolution(std::vector<unsigned int> guess_colors)
{  
    if(guess_colors.size() != places)
    {
        throw WrongCountException(); //hádám jiný počet míst než hra předpokládá
    }

    printColors(guess_colors);
    return readClues();
}

std::vector<bool> Usermind::readClues()
{
    std::vector<bool> tmp_clues;
    tmp_clues = CMDInterface::readClues();

    if(tmp_clues.size() == this->places && tmp_clues.at(0) == true){
        this->solved = true;
    }
    return tmp_clues;
}

void Usermind::printColors(std::vector<unsigned int> guess_colors)
{
    CMDInterface::printColors(guess_colors);
}

/** getters for private atributs */
bool Usermind::isSolved(){
    return solved;
}


unsigned int Usermind::getPlacesNumber()
{
    return places;
}

std::vector<unsigned int> Usermind::getSolution(){
    DataControler::echoItsOnYou();
}

unsigned int Usermind::getColorNumber()
{
    return colors;
}

