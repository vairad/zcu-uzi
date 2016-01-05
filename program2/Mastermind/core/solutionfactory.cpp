#include "solutionfactory.h"

#include <iostream>

/**
 * Konstruktor připraví továrnu do výchozího stavu pro vygenerování všech kombinací.
 * Dle zadaných parametrů.
 * @brief SolutionFactory::SolutionFactory
 * @param colors - počet možných barev na pozici
 * @param places - počet pozic hry
 */
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

/**
 * Metoda vypočte následující kombinaci hry. A zkontroluje zda byly vytvořeny všechny kombinace.
 * Pokud ano nastaví @code{allSolutions} na @code{true}
 * @brief SolutionFactory::getNextSolution
 * @return vector následujícího řešení
 */
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
                for(unsigned int j = i; j > 0; --j){
                    nextSolution.at(j) = 1; // vrat predchozi kotouce na 1
                }
                nextSolution.at(0) = 1; // ošetření podtečení unsigned int ve for cyklu při průchodu s nulou
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

/**
 * Vrací booleovskou hodnotu, která signalizuje, zda je třeba vypočítat další řešení.
 * @brief SolutionFactory::hasNextSolution
 * @return true/false zda existuje další řešení
 */
bool SolutionFactory::hasNextSolution(){
    return !allSolutions;
}

/**
 * Destruktor objektu
 * @brief SolutionFactory::~SolutionFactory
 */
SolutionFactory::~SolutionFactory(){
    //třída nealokuje paměť, kterou by bylo třeba uvolňovat
}
