#ifndef __Chromosome__
#define __Chromosome__

#include "Header.hpp"

class Chromosome
{
private:
    string Target;

public:
    /* Constructors & Destructor */
    Chromosome() {}
    Chromosome(mt19937_64 &mt, const string &_Target); // Initialization
    Chromosome(const string &_Target, const vector<char> &_Genome); // Inheritation
    ~Chromosome() {}

    //* Main Body *//
    vector<char> Genome;
    /* Public Varibles */
    int Fitness;

    /* Public Methods */
    string OutputGenome();
    void CalcFitness();
    void Mutation(mt19937_64 &mt, const double &_MutationRate);
};

#endif