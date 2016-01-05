#ifndef CMDINTERFACE_H
#define CMDINTERFACE_H

#include <iostream>

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
};

#endif // CMDINTERFACE_H
