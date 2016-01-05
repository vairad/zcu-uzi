#ifndef SOLUTIONFACTORY_H
#define SOLUTIONFACTORY_H

#include <vector>


/**
Třída SolutionFactory slouží k vytvoření všech kombinací řešení pro hru Mastermind.

@author Radek VAIS - A13B0457P

26.12.2015

@version verze 1.0.0
*/
class SolutionFactory
{
    /** proměnné pro uchování kombinací při generování */
    std::vector<unsigned int> nextSolution;
    std::vector<unsigned int> lastSolution;
    /** vlajka existence dalšího řešení */
    bool allSolutions;

    /** parametry generátoru */
    unsigned int colors;
    unsigned int places;

public:
    explicit SolutionFactory(unsigned int colors, unsigned int places);
    std::vector<unsigned int> getNextSolution();
    bool hasNextSolution();
    ~SolutionFactory();
};

#endif // SOLUTIONFACTORY_H
