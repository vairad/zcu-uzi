#ifndef DATACONTROLER_H
#define DATACONTROLER_H

#include <vector>
#include <random>

/**
 * Třída která kontroluje tok dat z tříd jádra aplikace do tříd uživatelského rozhraní.
 * (Momentálně pouze do CLI resp CMDInterface)
 *
 * @author Radek VAIS - A13B0457P
 * 4.1.2016
 * @version verze 1.0.0
 */
class DataControler
{
public:
    static void showGuess(std::vector<unsigned int> guess_colors);
    static void echoItsOnYou();
    static void showSolution(std::vector<unsigned int> guess_colors);
    static void notSolved();
    static std::vector<bool> readClues();

    /** objekt pro generování náhodných čísel */
    static std::random_device random_generator;
};

#endif // DATACONTROLER_H
