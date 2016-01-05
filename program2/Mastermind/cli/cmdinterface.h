#ifndef CMDINTERFACE_H
#define CMDINTERFACE_H

#include <iostream>
#include <vector>
#include <string>

/**
* Třída CMDInterface slouží ke zprostředkování uživatelského rozhraní pomocí přkazové řádky.
*
* @author Radek VAIS - A13B0457P
* 4.1.2016
* @version verze 1.0.0
*/
class CMDInterface
{
    private:
        static unsigned int getUInt();
    public:
        /*metody pro načítání informací oduživatele */
        static unsigned int getColorsCount();
        static unsigned int getPlacesCount();
        static char getGameType();
        static char getNextRound();
        static std::vector<bool> readClues();

        /* metody pro výpis informací uživateli */
        static void printInfo();
        static void printColors(std::vector<unsigned int> guess_colors);
        static void spacing(int lines);
        static void newGame();
        static void print(std::string msg);
        static void thinking();
        static void strategy();
        static void show();
        static void guess();
        static void congratulation();
        static void badPlayer();

};

#endif // CMDINTERFACE_H
