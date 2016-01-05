#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <vector>
#include <random>

#include "core/imind.h"

/**
 * Třída Mastermind symboliuje automatický ohodnocující systém hry Mastermind
 * Automaticky vygeneruje náhodnou kombinaci dle zadaných parametrů,
 * vůči které následně ohodnocuje odhady řešení.
 *
 * Implementuje rozhraní IMind.
 *
 * @author Radek VAIS - A13B0457P
 * 12.12.2015
 * @version verze 1.0.0
 */
class Mastermind : public IMind
{
    public:
        Mastermind(int colors, int places);

        virtual std::vector<bool> trySolution(std::vector<unsigned int> guess_colors);

        virtual bool isSolved();

        /** getters for private atributs */
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();
        virtual void showSolution();

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
