#include "Simulation.hpp"

Simulation::Simulation(const string &_Target)
{
    // Initialize the random generator with "SEED" as seed.
    mt.seed(SEED);

    // The target of this program is "Target".
    Target = _Target;
}

void Simulation::Run()
{
    // Output the target.
    cout << "Target is \"" << Target << "\"" << endl;

    Population = vector<Chromosome>(N);

    for (int i = 0; i < N; i++)
    {
        Population[i] = Chromosome(mt, Target);
    }
}