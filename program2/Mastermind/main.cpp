#include <iostream>
#include <QApplication>

#ifdef CLI
#include "cli/cmdinterface.h"
#elif GUI
#include "gui/mainwindow.h"
#endif

#include "core/mastermind.h"
#include "core/usermind.h"
#include "core/imind.h"
#include "core/exception.h"


#ifdef CLI
    int execGame(){
      IMind* round;
      unsigned int colors;
      unsigned int places;
      char gameType;

beginOfRound:

      CMDInterface::printInfo();

      //zjisti počty (set up hry)
      colors = CMDInterface::getColorsCount();
      places = CMDInterface::getPlacesCount();

      // zjisti typ hry -> kdo zadává ohodnocení: (Player (P) / Computer (C))
      gameType = CMDInterface::getGameType();

      if(gameType == 'P'){
          round = new Usermind(colors, places);
      }else if(gameType == 'C'){
          round = new Mastermind(colors, places);
      }
      // hraj
      while(!round->isSolved()){
          std::vector<bool> clue;
          std::vector<int> solution;

          //napln řešení odhadem
         // solution = //dej mi odhad
          try{
              clue = round->trySolution(solution);
          }catch(WrongCountException &e){
              std::cout << "Špatný počet hádaných cifer" << "\n";
              std::cout << "Předcházela špatná inicializace počítadla" << "\n";
              break;
          }
          if(!round->isSolved()){
            //pouč se z řešení
          }
      }
      gameType = CMDInterface::getNextRound();
      if(gameType == 'N'){
          goto beginOfRound;
      }
      //ukonči kolo - dotaz na konec aplikace/nove kolo


      delete round;
      return 1;
    }
#elif GUI
    int execGame(){
        QApplication app(argc, argv);
        MainWindow w;
        w.show();

        return app.exec();
    }
#else
    int execGame(){
       std::cout << "Wrong compiled program!" << "\n"
       std::cout << "Define macro CLI for compiling program with command line interface" << "\n";
       std::cout << "Define macro GUI for compiling with using Qt framework and graphics interface" << "\n";
        return 99
    }
#endif


int main(int argc, char *argv[])
{
    return execGame();
}
