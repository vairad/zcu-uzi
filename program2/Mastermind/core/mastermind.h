#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <vector>
#include <random>

#include "core/imind.h"

class Mastermind : public IMind
{
    public:
        Mastermind(int colors, int places);

        virtual std::vector<bool> trySolution(std::vector<unsigned int> guess_colors);

        virtual bool isSolved();

        /** getters for private atributs */
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();
        virtual std::vector<unsigned int> getSolution();

    private:
        /** number of used colors */
        unsigned int colors;
        /** number of places to place color */
        unsigned int places;
        /** flag that symbolized end of game*/
        bool solved;
        /** structure to keep solution in memory */
        std::vector<unsigned int> solution;

        std::random_device *random;
        std::uniform_int_distribution<int> *distributor;

};

#endif // MASTERMIND_H
