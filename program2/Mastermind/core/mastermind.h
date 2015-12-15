#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <vector>

#include "core/imind.h"

class Mastermind : public IMind
{
    public:
        Mastermind(int colors, int places);

        virtual std::vector<bool> trySolution(std::vector<int> guess_colors);

        /** getters for private atributs */
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();

    private:
        /** number of used colors */
        unsigned int colors;
        /** number of places to place color */
        unsigned int places;
        /** structure to keep solution in memory */
        std::vector<int> solution;

        unsigned int generateRandomNumber(unsigned int lowEnd, unsigned int highEnd);

};

#endif // MASTERMIND_H
