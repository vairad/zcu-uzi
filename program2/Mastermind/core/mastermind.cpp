#include "mastermind.h"

#include <iterator>
#include <random>
#include <cstdlib>

Mastermind::Mastermind(int colors, int places)
{
    this->colors = colors;
    this->places = places;

    for(int i = 0; i < places; ++i)
    {
        unsigned int tmp = generateRandomNumber(1, colors);
        solution.push_back(tmp);
    }


}

unsigned int Mastermind::generateRandomNumber(unsigned int lowEnd, unsigned int highEnd)
{
    if(highEnd < lowEnd)
    {
        unsigned int tempForSwap = highEnd;
        highEnd = lowEnd;
        lowEnd = tempForSwap;
    }

    int rangeVal = (highEnd - lowEnd) + 1;
    return (std::rand() % rangeVal) + lowEnd;
}

/**
 * @brief Mastermind::trySolution
 * @param colors vector of colors
 * @throws WrongCountException defined in mastermind.h
 * @return
 */
std::vector<bool> Mastermind::trySolution(std::vector<int> guess_colors)
{
    std::vector<bool> clues;
    std::vector<int> tmpSolution(solution);
    std::vector<int> tmpGuess(guess_colors);

    if(guess_colors.size() != places)
    {
        throw new WrongCountException(); //hádám jiný počet míst než hra předpokládá
    }

    // kontrola shodných pozic
    for(unsigned int i = 0; i < tmpSolution.size(); ++i)
    {
        if(tmpSolution.at(i) == tmpGuess.at(i) ){ //na stejném místě
            tmpSolution.erase(tmpSolution.begin()+i);   //odstraň ohodnocené
            tmpGuess.erase(tmpGuess.begin()+i);         //      ""
            i--;                                        //zmenši index za odebraný prvek

            clues.push_back(true);                  //vlož prvek do nápověd
        }
    }

    //kontrola barev na nesprávných místech
    for(unsigned int i = 0; i < tmpSolution.size(); ++i)
    {
        for(unsigned int j = 0; j < tmpGuess.size(); ++j)
        {
            if(tmpSolution.at(i) == tmpGuess.at(j) ){
                tmpSolution.erase(tmpSolution.begin()+i);
                tmpGuess.erase(tmpGuess.begin()+j);
                i--;
                j--;

                clues.push_back(false);
            }
        }
    }


    return clues;
}


/**
 * @brief Mastermind::getPlacesNumber
 * @return number of places to guess
 */
int Mastermind::getPlacesNumber()
{
    return places;
}

/**
 * @brief Mastermind::getColorNumber
 * @return number of colors which place might contains
 */
int Mastermind::getColorNumber()
{
    return colors;
}
