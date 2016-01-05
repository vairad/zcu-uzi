#ifndef ISOLVER_H
#define ISOLVER_H

#include <vector>

class ISolver
{
public:
    virtual std::vector<unsigned int> nextTry() = 0;
    virtual void getClue(std::vector<bool> clue) = 0;
    virtual unsigned int numberOfSolutions() = 0;

    virtual ~ISolver(){}
};

#endif // ISOLVER_H
