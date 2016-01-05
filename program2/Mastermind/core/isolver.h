#ifndef ISOLVER_H
#define ISOLVER_H

#include <vector>


/**
 * Rozhraní pro řešitel hry Mastermind.
 * Zaručuje možnosti:
 *       získat další odhad řešení
 *       poučit se z předchozího odhadu
 *       zjistit počet zbývajících řešení
 *
 * @author Radek VAIS - A13B0457P
 * 4.1.2016
 * @version verze 1.0.0
 */
class ISolver
{
public:
    /** získej odhad řešní */
    virtual std::vector<unsigned int> nextTry() = 0;
    /** pouč se z nápovědy */
    virtual void getClue(std::vector<bool> clue) = 0;
    /** kolik zbývá řešení */
    virtual unsigned int numberOfSolutions() = 0;

    virtual ~ISolver(){}
};

#endif // ISOLVER_H
