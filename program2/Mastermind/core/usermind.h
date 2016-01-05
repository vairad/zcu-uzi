#ifndef USERMIND_H
#define USERMIND_H

#include "core/imind.h"

/**
 * Třída Usermind symboliuje hru, kde kombinace ohodnocujeu uživatel.
 * Zaručuje korektní komunikaci s UI a získání potřebných informací.
 *
 * Implementuje rozhraní IMind.
 *
 * @author Radek VAIS - A13B0457P
 * 12.12.2015
 * @version verze 1.0.0
 */
class Usermind : public IMind
{
    public:
        Usermind(int colors, int places);

        /* implementované metody z IMind */
        virtual std::vector<bool> trySolution(std::vector<unsigned int> colors);
        virtual bool isSolved();
        virtual unsigned int getPlacesNumber();
        virtual unsigned int getColorNumber();
        virtual void showSolution();
    private:
        unsigned int places;
        unsigned int colors;
        bool solved;

        /** nacte ohodnocení tipu počítače od uživatele */
        std::vector<bool> readClues();
};

#endif // USERMIND_H
