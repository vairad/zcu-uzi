/****************************************************************************************
 *Hlavní soubor programu AutoMastermind představuje automatický řešitel hry Mastermind
 *Program implementuje algoritmus Donalda Knutha (1977), který redukuje mnozinu vsech
 *resení za pomoci entropie informace.
 *
 *
 *Pravidla hry Mastemind:
 *Ve hře Mastermind (neboli Logik) jde o to, uhádnout tajnou kombinaci pro-
 *tivníka. Kombinace je dána rozmístěním různě barevných prvků na pevný
 *počet pozic. Obvyklé parametry hry jsou šest možných barev na čtyřech růz-
 *ných pozicích, ale není to striktně určeno. K hádání dostává hráč nápovědu
 *v podobě černých a bílých kolíků. Každý barevný prvek,
 *který hádající hráč umístil do správné pozice, je ohodnocen černým kolíkem,
 *každý barevný prvek, který se v zadané tajné kombinaci vyskytuje, ale není
 *v dané pozici, je ohodnocen kolíkem bílým. Pokud není kombinace hádají-
 *cího hráče ohodnocena žádným kolíkem, znamená to, že se v tajné kombinaci
 *žádná z použitých barev v hodnocené kombinaci nevyskytuje
 *
 * Verze: 1.0.0
 *
 *Autor:
 *  Radek VAIS
 *  A13B045P
 *  vaisr@students.zcu.cz
 ****************************************************************************************/

#include <unistd.h>
#include <iostream>
#include <exception>

#include "cli/cmdinterface.h"

#include "core/imind.h"
#include "core/isolver.h"
#include "core/exception.h"
#include "core/mastermind.h"
#include "core/usermind.h"
#include "core/entropysolver.h"
#include "core/solutionfactory.h"


/**
 * Funkce, která představuje průběh hry.
 * @brief execGame
 * @return návratová hodnota programu
 */
int execGame(){
      IMind* round;
      ISolver* solver;
      unsigned int colors;
      unsigned int places;
      char gameType;

      CMDInterface::printInfo();

beginOfRound:
      CMDInterface::newGame();

      //zjisti počty (set up hry)
      colors = CMDInterface::getColorsCount();
      places = CMDInterface::getPlacesCount();

      // zjisti typ hry -> kdo zadává ohodnocení: (Player (P) / Computer (C))
      gameType = CMDInterface::getGameType();

      //připrav hru dle typu
      if(gameType == 'P'){
          round = new Usermind(colors, places);
      }else if(gameType == 'C'){
          round = new Mastermind(colors, places);
      }

      //připrav řešitel
      CMDInterface::strategy();
      solver = new EntropySolver(colors, places);

      // hraj hru
      while(!round->isSolved() && solver->numberOfSolutions() > 0){
          std::vector<bool> clue;
          std::vector<unsigned int> solution;

          //napln řešení odhadem
          CMDInterface::thinking();
          solution = solver->nextTry();
          try{
              clue = round->trySolution(solution); //získej ohodnocení odhadu
              CMDInterface::printClue(clue);

          }catch(WrongCountException &e){
              std::cout << "Špatný počet hádaných cifer" << "\n";
              std::cout << "Předcházela špatná inicializace počítadla" << "\n";
              break;
          }

          if(!round->isSolved()){ //pokud kolo neskončilo
            solver->getClue(clue);      //pouč se z řešení
          }
      }

      if(solver->numberOfSolutions() == 0){ // pokud řešiteli došly odhady, vzdal to
          CMDInterface::badPlayer();
      }else{
        CMDInterface::congratulation(); //jinak hru vyřešil
        round->showSolution();
      }

       //ukonči kolo - dotaz na konec aplikace/nove kolo
      gameType = CMDInterface::getNextRound();
      if(gameType == 'A'){
          goto beginOfRound;
      }


      delete round;
      delete solver;

      return 0;
    }

/**
 * Funkce, která představuje průběh jedné automatické hry
 * @brief autoGame
 * @return návratová hodnota programu
 */
int autoGame(unsigned int colors, unsigned int places){
      IMind* round;
      ISolver* solver;

      CMDInterface::printAutoInfo();
      CMDInterface::newGame();

      round = new Mastermind(colors, places);

      //připrav řešitel
      solver = new EntropySolver(colors, places);

      // hraj hru
      while(!round->isSolved() && solver->numberOfSolutions() > 0){
          std::vector<bool> clue;
          std::vector<unsigned int> solution;

          //napln řešení odhadem
          solution = solver->nextTry();
          try{
              clue = round->trySolution(solution); //získej ohodnocení odhadu
              CMDInterface::printClue(clue);

          }catch(WrongCountException &e){
              std::cout << "Špatný počet hádaných cifer" << "\n";
              std::cout << "Předcházela špatná inicializace počítadla" << "\n";
              break;
          }

          if(!round->isSolved()){ //pokud kolo neskončilo
            solver->getClue(clue);      //pouč se z řešení
          }
      }

      if(solver->numberOfSolutions() == 0){ // pokud řešiteli došly odhady, vzdal to
            CMDInterface::badPlayer();
      }else{
            CMDInterface::congratulation(); //jinak hru vyřešil
            round->showSolution();
      }

      delete round;
      delete solver;

      return 0;
    }

 /**
 * Funkce určená pro ověření funkčnosti továrny řešení hry Mastermind
 * @brief testSolutionFactory
 * @param colors počet barev
 * @param places počet pozic
 */
void testSolutionFactory(unsigned int colors, unsigned int places){
    std::cout << "Spoustim test tovarny reseni:" << "\n";
    SolutionFactory *factory = new SolutionFactory(colors, places);

    long counter = 0;
    std::vector<unsigned int> sol;
    while(factory->hasNextSolution()){
        counter ++;
        sol = factory->getNextSolution();
        for(unsigned int i = 0; i < sol.size(); ++i){
            std::cout << sol.at(i)  << " ";
        }
        std::cout << "\n";
    }
    std::cout << "suma: " << counter << "\n";
}


/**
 * Vytiskne nápovědu na konzoli.
 * @brief printHelp
 */
void printHelp(){
    std::cout << "Napoveda ke spusteni programu AutoMastermind:" << "\n";
    std::cout << "" << "\n";
    std::cout << "Spusteni bez parametru spustí hru." << "\n";
    std::cout << "Spusteni s parametrem h zobrazi tuto napovedu." << "\n";
    std::cout << "Spusteni s parametrem ? zobrazi tuto napovedu." << "\n";
    std::cout << "Spusteni s parametrem t u_int u_int otestuje generátor kombinací." << "\n";
    std::cout << "Spusteni s parametrem a u_int u_int spusti automatickou verzi." << "\n";
}




/**
 * funkce main() kontroluje argumenty a spouští program
 * @param argv mozno zadat kombinace parametru h / ? / t cislo cislo
 * @return
 */
int main(int argc, char *argv[])
{
    if(argc == 4 && *argv[1] == 't'){
        unsigned int a = atoi(argv[2]);
        unsigned int b = atoi(argv[3]);
        if(a > 0 && b > 0){
             testSolutionFactory(a, b);
             return 0;
        }else{
            std::cout << "Šparná čísla: " << a << " a " << b;
            return 5;
        }
        return 0;
    }else if(argc == 2 && (*argv[1] == 'h' || *argv[1] == '?' )){
        printHelp();
        return 0;
    }else if(argc == 4 && (*argv[1] == 'a')){
        unsigned int a = atoi(argv[2]);
        unsigned int b = atoi(argv[3]);
        if(a > 0 && b > 0){
        return autoGame(a, b);
        }else{
            std::cout << "Šparná čísla: " << a << " a " << b;
            return 5;
        }
    }else{
        return execGame();
    }
}

