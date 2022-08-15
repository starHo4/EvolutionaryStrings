#ifndef __Chromosome__
#define __Chromosome__

#include "Header.hpp"

class Chromosome
{
private:
    string Target;

    //* Main Body *//
    vector<char> Genome;

public:
    /* Constructors & Destructor */
    Chromosome() {}
    Chromosome(mt19937_64 &mt, const string &_Target);
    ~Chromosome() {}

    /* Public Varibles */
    double Fitness;

    /* Public Methods */
    void OutputGenome();
};

#endif