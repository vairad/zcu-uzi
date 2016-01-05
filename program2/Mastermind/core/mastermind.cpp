#include <iterator>
#include <random>
#include <algorithm>
#include <cstdlib>

#include "core/mastermind.h"
#include "core/exception.h"
#include "core/datacontroler.h"


/**
 * Constructor prepare one combination to solve.
 * Instance of this class represents "one game round"
 * @brief Mastermind::Mastermind
 * @param colors number of colors which places may contains
 * @param places number of places for different colors
 */
Mastermind::Mastermind(int colors, int places)
{
    this->colors = colors;
    this->places = places;
    this->solved = false;

    std::uniform_int_distribution<int> distributor(1, colors);
    //std::default_random_engine generator;
    std::random_device generator;

    for(int i = 0; i < places; ++i)
    {
        unsigned int tmp = distributor(generator);
        solution.push_back(tmp);
    }
    DataControler::printColors(solution);

}

/**
 * @brief Mastermind::trySolution
 * @param colors vector of colors
 * @throws WrongCountException defined in mastermind.h
 * @return sorted vectro of solution
 */
std::vector<bool> Mastermind::trySolution(std::vector<int> guess_colors)
{
    std::vector<bool> clues;
    std::vector<int> tmpSolution(solution);
    std::vector<int> tmpGuess(guess_colors);

    DataControler::printColors(guess_colors);

    if(guess_colors.size() != places)
    {
        throw WrongCountException(); //hádám jiný počet míst než hra předpokládá
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

    if(clues.size() == this->places){ //pokud je počet prvků na stejných místech shodný s počtem pozic je hra vyřešena
        this->solved = true;
        return clues;
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

    sort(clues.begin(), clues.end());
    return clues;
}

/**
 * @brief Mastermind::isSolved
 * @return bool if game was solved
 */
bool Mastermind::isSolved(){
    return solved;
}

/**
 * @brief Mastermind::getPlacesNumber
 * @return number of places to guess
 */
unsigned int Mastermind::getPlacesNumber()
{
    return places;
}

/**
 * @brief Mastermind::getColorNumber
 * @return number of colors which place might contains
 */
unsigned int Mastermind::getColorNumber()
{
    return colors;
}
