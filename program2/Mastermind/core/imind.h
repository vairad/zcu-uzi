#ifndef IMIND_H
#define IMIND_H

#include <vector>
/**
 * Interface for game Mastermind
 * @brief The IMind class
 */
class IMind
{
    public:
        virtual std::vector<bool> trySolution(std::vector<unsigned int> guess_colors) = 0;

        /** getters for private atributs */
        virtual bool isSolved() = 0;
        virtual unsigned int getPlacesNumber() = 0;
        virtual unsigned int getColorNumber() = 0;


        virtual ~IMind(){}
};
#endif // IMIND_H
