#ifndef ENTROPYSOLVER_H
#define ENTROPYSOLVER_H

#include <vector>

#include "core/isolver.h"

class EntropySolver : public ISolver
{
    const static int PLACE_POINTS = 10;
    const static int COLOR_POINTS = 1;

    std::vector<std::vector<unsigned int>> solutions;
    std::vector<unsigned int> lastSolution;
    std::vector<int> points;

    int computePoints(std::vector<unsigned int> v1, std::vector<unsigned int> v2);
    int computePoints(std::vector<bool> clue);

    double computeEntropy(std::vector<unsigned int> sol);

public:
    EntropySolver(unsigned int colors, unsigned int places);
    virtual std::vector<unsigned int> nextTry();
    virtual void getClue(std::vector<bool> clue);
    virtual unsigned int numberOfSolutions();
};

#endif // ENTROPYSOLVER_H
