#ifndef DATACONTROLER_H
#define DATACONTROLER_H

#include <vector>
#include <random>

class DataControler
{
public:
    DataControler();

    /** metoda pro načtení ohodnocení implementace je různá dle požadovaného UI*/
    static std::vector<bool> readClues();
    /** metoda pro zobrazení tipu implementace je různá dle požadovaného UI*/
    static void printColors(std::vector<int> guess_colors);

    /** objekt pro generování náhodných čísel */
    static std::random_device random_generator;
};

#endif // DATACONTROLER_H
