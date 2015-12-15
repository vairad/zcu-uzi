#ifndef USERMIND_H
#define USERMIND_H

#include "core/imind.h"

class Usermind : public IMind
{
    public:
        Usermind(int colors, int places);
        virtual std::vector<bool> trySolution(std::vector<int> colors);

        /** getters for private atributs */
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();
    private:
        unsigned int places;
        unsigned int colors;

        void printColors(std::vector<int> guess_colors);
        /** nacte ohodnocení tipu počítače */
        std::vector<bool> readClues();
};

#endif // USERMIND_H
