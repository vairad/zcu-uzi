#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <vector>
#include <exception>

#include "core/imind.h"

class Mastermind : public IMind
{
    public:
        Mastermind(int colors, int places);

        std::vector<bool> trySolution(std::vector<int> colors);

        /** getters for private atributs */
        int getPlacesNumber();
        int getColorNumber();

    private:
        /** number of used colors */
        unsigned int colors;
        /** number of places to place color */
        unsigned int places;
        /** structure to keep solution in memory */
        std::vector<int> solution;

        unsigned int generateRandomNumber(unsigned int lowEnd, unsigned int highEnd);

};

class WrongCountException : public std::exception
{
  virtual const char* what() const throw()
  {
    return "Wrong number of guessed colors.";
  }
};

#endif // MASTERMIND_H
