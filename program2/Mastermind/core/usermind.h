#ifndef USERMIND_H
#define USERMIND_H

#include "core/imind.h"

class Usermind : public IMind
{
    public:
        Usermind(int colors, int places);
        virtual std::vector<bool> trySolution(std::vector<unsigned int> colors);

        /** getters for private atributs */
        virtual bool isSolved();
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();
        virtual std::vector<unsigned int> getSolution();
    private:
        unsigned int places;
        unsigned int colors;
        bool solved;

        /** zobrazí hádané barvy */
        void printColors(std::vector<unsigned int> guess_colors);
        /** nacte ohodnocení tipu počítače od uživatele */
        std::vector<bool> readClues();
};

#endif // USERMIND_H
