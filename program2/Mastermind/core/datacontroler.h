#ifndef DATACONTROLER_H
#define DATACONTROLER_H

#include <vector>
#include <random>

class DataControler
{
public:
    DataControler();

    /** objekt pro generování náhodných čísel */
    static std::random_device random_generator;
};

#endif // DATACONTROLER_H
