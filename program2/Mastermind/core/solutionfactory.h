#ifndef SOLUTIONFACTORY_H
#define SOLUTIONFACTORY_H

#include <vector>

class SolutionFactory
{
    std::vector<unsigned int> nextSolution;
    std::vector<unsigned int> lastSolution;
    bool allSolutions;
    unsigned int colors;
    unsigned int places;

public:
    SolutionFactory(unsigned int colors, unsigned int places);
    std::vector<unsigned int> getNextSolution();
    bool hasNextSolution();
    ~SolutionFactory();
};

#endif // SOLUTIONFACTORY_H
