#ifndef IMIND_H
#define IMIND_H


/**
 * Interface for game Mastermind
 * @brief The IMind class
 */
class IMind
{
    public:
        virtual std::vector<bool> trySolution(std::vector<int> colors) = 0;

        /** getters for private atributs */
        virtual int getPlacesNumber() = 0;
        virtual int getColorNumber() = 0;
};

#endif // IMIND_H
