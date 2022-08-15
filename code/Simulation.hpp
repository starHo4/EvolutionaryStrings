#ifndef __Simulation__
#define __Simulation__

#include "Header.hpp"

class Simulation
{
private:
    /* Static Variables */
    static const int SEED = 1024;

    /* Private Variables */
    mt19937_64 mt;
    string Target;

public:
    /* Constructor */
    Simulation() {}
    Simulation(const string _Target);
    ~Simulation() {}

    /* Public Methods */
    void Run();
};

#endif