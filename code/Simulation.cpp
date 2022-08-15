#include "Simulation.hpp"

Simulation::Simulation()
{
    mt.seed(1024);
}

void Simulation::Run()
{
    uniform_int_distribution uid(0, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << uid(mt) << endl;
    }
}