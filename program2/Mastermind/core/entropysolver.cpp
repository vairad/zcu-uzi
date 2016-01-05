#include "entropysolver.h"

#include "limits.h"
#include "math.h"
//#include <iostream>
#include <map>

#include "core/solutionfactory.h"


EntropySolver::EntropySolver(unsigned int colors, unsigned int places)
{
    //generate solutions using solution factory
    SolutionFactory *factory = new SolutionFactory(colors, places);

    while(factory->hasNextSolution()){
        solutions.push_back(factory->getNextSolution());
        points.push_back(0);
    }

    delete factory;
}

/**
 * Vypočte heuristický počet bodů z vektoru nápovědy.
 * @brief EntropySolver::computePoints
 * @param clue vektor nápovědy
 * @return hodnota bodů
 */
int EntropySolver::computePoints(std::vector<bool> clue){
    int points = 0;

    for(unsigned int i = 0; i < clue.size(); ++i){
        if(clue.at(i) == true){ //pokud je v ohodnocení správné místo
            points += PLACE_POINTS;   //započti 10 bodů
        }
        if(clue.at(i) == false){ // pokud je v ohodnocení pouze správná barvy
            points += COLOR_POINTS;    // započti 1 bod
        }
    }

    return points;
}

/**
 * Vypočte heuristický počet bodů ze dvou vektorů řešení.
 * Za shodnou barvu na stejném místě připočte @code{PLACE_POINTS} bodů.
 * Za shodnou barvu na špatném místě připočte @code{COLOR_POINTS} bodů
 * @brief EntropySolver::computePoints
 * @param clue vektor nápovědy
 * @return hodnota bodů
 */
int EntropySolver::computePoints(std::vector<unsigned int> v1, std::vector<unsigned int> v2){
    int points = 0;
    // kontrola shodných pozic
    for(unsigned int i = 0; i < v1.size(); ++i)
    {
        if(v1.at(i) == v2.at(i) ){          //na stejném místě
            v1.erase(v1.begin()+i);         //odstraň ohodnocené z vektoru
            v2.erase(v2.begin()+i);         //      ""
            i--;                            //zmenši index za odebraný prvek

            points += PLACE_POINTS;                   //připočti body
        }
    }
    //kontrola barev na nesprávných místech
    for(unsigned int i = 0; i < v1.size(); ++i)
    {
        for(unsigned int j = 0; j < v2.size(); ++j)
        {
            if(v1.at(i) == v2.at(j) ){
                v1.erase(v1.begin()+i);
                v2.erase(v2.begin()+j);
                i--;
                j--;

                points += COLOR_POINTS;
                break;
            }
        }
    }
    return points;
}

std::vector<unsigned int> EntropySolver::nextTry(){
    //pro včechny řešení propočti entropii a hledej maximum

    unsigned int indexOfMaximumEntropy = 0;
    double maximumEntropy = 0.0;

    //std::cout << "************************************ in next try \n";

    for(unsigned int i = 0; i < solutions.size(); ++i){
        //std::cout << "***********************incycle\n";
        double tmpEntropy = computeEntropy(solutions.at(i));
        if(tmpEntropy > maximumEntropy){
            maximumEntropy = tmpEntropy;
            indexOfMaximumEntropy = i;
        }
    }

    //std::cout << "************************************ after cycle next try \n";
    //std::cout << "max index: " << indexOfMaximumEntropy;

    //vyber to s nejvyšší hodnotou
    lastSolution = solutions.at(indexOfMaximumEntropy);
    return lastSolution;
}

double EntropySolver::computeEntropy(std::vector<unsigned int> sol){
    double entropy = 0.0;

    std::map<int, int> points_map;
    points_map.clear();

    //std::cout << "************************************ in computeEntropy \n";
    //std::cout << "points size: " << points.size();


    for(unsigned int i = 0; i < solutions.size(); ++i){
       // napočti ohodnocení

       //std::cout << "**" << i << "\n";
       points.at(i) = computePoints(sol, solutions.at(i));
    }

    //std::cout << "************ in after 1 cycle \n";

    for(unsigned int i = 0; i < solutions.size(); ++i){
        //vytvarej histogram cetnosti
        if(points_map[points.at(i)] > 0){
           points_map[points.at(i)] += 1 ;
        }else{
           points_map[points.at(i)] = 1 ;
        }
    }


    // projdi mapu a spocti entropii
    for (auto& x: points_map){
        double ppst = (double)x.second / (double)solutions.size();
        entropy += ppst * log2(ppst);
    }

    return entropy;
}

void EntropySolver::getClue(std::vector<bool> clue){
    // napočti body z ohodnocení
    int pointsClue = computePoints(clue);

    for(unsigned int i = 0; i < solutions.size(); ++i){
       // spočítej body od předchozího tipu k ostatním řešením
       points.at(i) = computePoints(lastSolution, solutions.at(i));

       //vyřaď všechny řešení, které mají odlišné ohodnocení
       if( points.at(i) != pointsClue){
           points.erase(points.begin()+i);
           solutions.erase(solutions.begin()+i);
           i--;
       }
    }
}

unsigned int EntropySolver::numberOfSolutions(){
    return solutions.size();
}
