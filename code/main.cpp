#include "Simulation.hpp"

int main()
{
    string TargetString;
    cout << "Input the favorite string not using space key." << endl;
    cin >> TargetString;

    Simulation simulation(TargetString);
    simulation.Run();
}