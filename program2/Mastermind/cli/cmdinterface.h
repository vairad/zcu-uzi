#ifndef CMDINTERFACE_H
#define CMDINTERFACE_H

#include <iostream>
#include <vector>

class CMDInterface
{
    private:
        static unsigned int getCount();
    public:
        static unsigned int getColorsCount();
        static unsigned int getPlacesCount();
        static char getGameType();
        static char getNextRound();
        static void printInfo();
        static std::vector<bool> readClues();
        static void printColors(std::vector<unsigned int> guess_colors);

};

#endif // CMDINTERFACE_H
