#include <map>
#include <math.h>

#include "entropysolver.h"
#include "core/solutionfactory.h"

/** ***************************************************************************
 * Konstruktor pomocí @code{SolutionFactory} naplní pole možných řešení.
 * A vlajku prvního pokusu.
 * @brief EntropySolver::EntropySolver
 * @param colors počet barev
 * @param places počet pozic
 */
EntropySolver::EntropySolver(unsigned int colors, unsigned int places)
{
    //generate solutions using solution factory
    SolutionFactory *factory = new SolutionFactory(colors, places);

    while(factory->hasNextSolution()){
        solutions.push_back(factory->getNextSolution());
        points.push_back(0);
    }

    delete factory;

    first = true;
}

/** ***************************************************************************
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

/** ***************************************************************************
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

/** ***************************************************************************
 * Metoda vybere nejvhodnější odhad řešení. Nejvodnější řešení jeurčeno pomocí
 * výpočtu entropie. Odhadujeme tedy řešení, které nám přenese nejvíce nové infomace.
 * Proto je odhadnuto řešení s maximáln entropií.
 * @brief EntropySolver::nextTry
 * @return vektor odhadnutého řešení
 */
std::vector<unsigned int> EntropySolver::nextTry(){
   /* if(first == true){ //poprvé zvol náhodný odhad
        first = false;
        lastSolution = solutions.at(rand() % solutions.size());
        return lastSolution;
    }*/ //špatný přístup k randomizaci začátku

    //pro včechny řešení propočti entropii a hledej maximum
    unsigned int indexOfMaximumEntropy = 0;
    double maximumEntropy = 0.0;

    for(unsigned int i = 0; i < solutions.size(); ++i){
        double tmpEntropy = computeEntropy(solutions.at(i));
        if(tmpEntropy > maximumEntropy){
            maximumEntropy = tmpEntropy;
            indexOfMaximumEntropy = i;
        }
    }

    //vyber to s nejvyšší hodnotou
    lastSolution = solutions.at(indexOfMaximumEntropy);
    return lastSolution;
}

/** ***************************************************************************
 * Metoda vypočte entropii konkrétního řešení.
 * @brief EntropySolver::computeEntropy
 * @param sol odhad pro který počítáme entropii
 * @return hodnotu entropie pro dané řešení
 */
double EntropySolver::computeEntropy(std::vector<unsigned int> sol){
    double entropy = 0.0;

    std::map<int, int> points_map;
    points_map.clear();

    for(unsigned int i = 0; i < solutions.size(); ++i){
       // napočti ohodnocení

       points.at(i) = computePoints(sol, solutions.at(i));
    }

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

    return (-entropy);
}

/** ***************************************************************************
 * Metoda se poučí z nápovědy vrácené po předchozím pokusu.
 * Vyřadí ze seznamu možných řešení všechny, co mají odlišné ohodnocení.
 * @brief EntropySolver::getClue
 * @param clue ohodnocení pokusu
 */
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

/** **************************************************************************
 * Vrací počet zbývajících řešení
 * @brief EntropySolver::numberOfSolutions
 * @return počet zbývajících řešení
 */
unsigned int EntropySolver::numberOfSolutions(){
    return solutions.size();
}
