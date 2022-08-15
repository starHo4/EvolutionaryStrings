#ifndef __Simulation__
#define __Simulation__

#include "Header.hpp"

class Simulation
{
private:
    /* Private Variables */
    mt19937_64 mt;

public:
    /* Constructor */
    Simulation();

    /* Public Methods */
    void Run();
};

#endif