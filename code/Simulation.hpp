#ifndef __Simulation__
#define __Simulation__

#include "Header.hpp"
#include "Chromosome.hpp"

class Simulation
{
private:
    /* Static Variables */
    static const int SEED = 2048;
    static const int N = 400;   // Population size
    static const int MaxGenerations = 100000;
    double CrossOverRate = 0.6;
    double MutationRate = 0.001;

    /* Private Variables */
    mt19937_64 mt;
    string Target;
    double PerfectScore;
    vector<Chromosome> Population;
    // For record
    string BestGenome;
    double BestFitness;

    /* Private Methods */
    void InheritNewGenerationWithCrossover();
    void InheritNewGeneration();
    void OutputBestGenome(const int &_g);

public:
    /* Constructor */
    Simulation() {}
    Simulation(const string &_Target);
    ~Simulation() {}

    /* Public Methods */
    void RunWithCrossover();
    void Run();
};

#endif