#include "solutionfactory.h"

SolutionFactory::SolutionFactory(unsigned int colors, unsigned int places)
{
    this->colors = colors;
    this->places = places;

    this->allSolutions = false;

    //prepare last solution - napln ho samými jedničkami
    for(unsigned int i = 0; i < places; ++i){
        nextSolution.push_back(1);
    }
}


std::vector<unsigned int> SolutionFactory::getNextSolution(){
    lastSolution = nextSolution;

    if(allSolutions == true){
        return lastSolution;
    }

    //zvyšování prvků
    for(unsigned int i = 0; i < (places - 1); ++i){ // modified limit size of vector
        if(nextSolution.at(i) < colors){ // pokud je prvek na pozici menší než colors zvyš ho o jedna opusť cyklus
            nextSolution.at(i) += 1;
            break;
        }
        if(nextSolution.at(i) == colors){ // pokud prvek i dosahl maxima
            if(nextSolution.at(i+1) == colors){ // zjisti zda dalši je také maximální
                continue; //pookud ano, tak pokračuj v cyklu dál
            }else{
                nextSolution.at(i+1) += 1;  // pokud ne zvyš ho a ukonči cyklus
                break;
            }
        }
    }

    //kontrola zda je generátor na konci posloupnosti
    bool tmpBool = true;
    for(unsigned int i = 0; i < places; ++i){
        tmpBool &= (lastSolution.at(i) == colors);
    }
    allSolutions = tmpBool;

    return lastSolution;
}

bool SolutionFactory::hasNextSolution(){
    return !allSolutions;
}

SolutionFactory::~SolutionFactory(){
    //není třeba použít destruktor nealokuje zvláštní paměť
}
