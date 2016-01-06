#ifndef ENTROPYSOLVER_H
#define ENTROPYSOLVER_H

#include <vector>

#include "core/isolver.h"


/**
 * Třída EntropySolver implementuje Knuthův algoritmus pro odhadřešení hry Mastermind.
 * Jako ohodnocení tahů využívá entropii informace. Vždy vybírá tah, který má nejvyšší entropii
 * a tím pádem odpověď na něj přinese nejvíce informace. První odhad je náhodně vybrán.
 *
 * Implementuje rozhraní ISolver.
 *
 * @author Radek VAIS - A13B0457P
 * 4.1.2016
 * @version verze 1.0.1
 *
 * 1.0.1 - přidán náhodný první tip
 */
class EntropySolver : public ISolver
{
    /** bodové ohodnocení správného místa */
    const static int PLACE_POINTS = 10;
    /** bodové ohodnocení správné barvy na špatném místě*/
    const static int COLOR_POINTS = 1;

    /** seznam všech řešení */
    std::vector<std::vector<unsigned int>> solutions;
    /** poslední odhadované řešení */
    std::vector<unsigned int> lastSolution;
    /** pole pro uložení ohodnocení jednotlivých možností */
    std::vector<int> points;

    /** vypočte body mezi dvěma odhady řešení */
    int computePoints(std::vector<unsigned int> v1, std::vector<unsigned int> v2);
    /** vypočte body z ohodnocení */
    int computePoints(std::vector<bool> clue);

    /** vypočte entropii konkrétního odhadu */
    double computeEntropy(std::vector<unsigned int> sol);

    /** vlajka zda se jedná o první odhad */
    bool first;

public:
    EntropySolver(unsigned int colors, unsigned int places);
    /* implementace rozhraní ISolver */
    virtual std::vector<unsigned int> nextTry();
    virtual void getClue(std::vector<bool> clue);
    virtual unsigned int numberOfSolutions();
};

#endif // ENTROPYSOLVER_H
