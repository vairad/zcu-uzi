#include "core/usermind.h"
#include "core/exception.h"

#include <iostream>

Usermind::Usermind(int colors, int places)
{
    this->colors = colors;
    this->places = places;
}

std::vector<bool> Usermind::trySolution(std::vector<int> guess_colors)
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
    std::vector<bool> clues;

    clues.push_back(true);

    return clues;
}

void Usermind::printColors(std::vector<int> guess_colors)
{
    std::cout << "Počítač odhatuje:" << "\n";
    for(unsigned int i = 0; i < places; ++i)
    {
        std::cout << i+1 << ". " << guess_colors.at(i) << "\n";
    }
}

/** getters for private atributs */
unsigned int Usermind::getPlacesNumber()
{
    return places;
}

unsigned int Usermind::getColorNumber()
{
    return colors;
}

