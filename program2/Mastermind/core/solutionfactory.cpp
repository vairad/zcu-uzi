#include "solutionfactory.h"

SolutionFactory::SolutionFactory(unsigned int colors, unsigned int places)
{
    this->colors = colors;
    this->places = places;

    this->allSolutions = false;

    //prepare last solution - napln ho samými jedničkami
    for(int i = 0; i < places; ++i){
        lastSolution.push_back(1);
    }
}


std::vector<unsigned int> SolutionFactory::getNextSolution(){

}

bool SolutionFactory::hasNextSolution(){
    return !allSolutions;
}

SolutionFactory::~SolutionFactory(){
    //není třeba použít destruktor
}
