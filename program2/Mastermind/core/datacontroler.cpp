#include "datacontroler.h"

#include <iostream>
#include <algorithm>
#include <random>

DataControler::DataControler(){

}

/*defines command line interface version of methods*/
#ifdef CLI

    /**
     * Nacte vstup oduživatele a seřadí hodnoty true/false v pořadí false ... true
     * @brief DataControler::readClues
     * @return sorted list of clues to solve mastermind
     */
    std::vector<bool> DataControler::readClues(){
        std::vector<bool> clues;

        std::cout << "Zadej ohodnocení 1 nebo 0 (zadávání ukončte znakem N)" << "\n";

        char read = 0;
        while(read != 'N'){
            std::cout << "ohodnocení (1/0/N): " ;
            std::cin >> read;
            if(read == '0'){
                clues.push_back(false);
            }
            if(read == '1'){
                clues.push_back(true);
            }
        }
        sort(clues.begin(), clues.end());

        std::cout << "Zadal jste ohodnocení tahu";
        for(unsigned int i = 0; i < clues.size(); ++i)
        {
            std::cout << " " << clues.at(i);
        }

        std::cout << "\n";

        return clues;
    }

    void DataControler::printColors(std::vector<int> guess_colors)
    {
        std::cout << "Počítač odhaduje:" << "\n";
        for(unsigned int i = 0; i < guess_colors.size(); ++i)
        {
            std::cout << i+1 << ". " << guess_colors.at(i) << "\n";
        }
    }

#endif /*end of CLI*/

