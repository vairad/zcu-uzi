#ifndef IMIND_H
#define IMIND_H

#include <vector>

/**
 * Rozhraní pro hru Mastermind.
 * Zaručuje možnosti:
 *       hádat hlavolam,
 *       zjistit, zda byl vyřešen
 *       zjistit parametry hlavolamu
 *       zobrazit řešení ... (pokud byl hlavolam řešen)
 *
 * @author Radek VAIS - A13B0457P
 * 12.12.2015
 * @version verze 1.0.0
 */
class IMind
{
    public:
        /** hádej hlavolam */
        virtual std::vector<bool> trySolution(std::vector<unsigned int> guess_colors) = 0;

        /** zda je hlavolam vyřešen */
        virtual bool isSolved() = 0;
        /** parametry hry */
        virtual unsigned int getPlacesNumber() = 0;
        virtual unsigned int getColorNumber() = 0;
        /** zobraz řešení */
        virtual void showSolution() = 0;

        virtual ~IMind(){}
};
#endif // IMIND_H
