#ifndef __Simulation__
#define __Simulation__

#include "Header.hpp"
#include "Chromosome.hpp"

class Simulation
{
private:
    /* Static Variables */
    static const int SEED = 1024;
    static const int N = 100;

    /* Private Variables */
    mt19937_64 mt;
    string Target;
    vector<Chromosome> Population;

public:
    /* Constructor */
    Simulation() {}
    Simulation(const string &_Target);
    ~Simulation() {}

    /* Public Methods */
    void Run();
};

#endif