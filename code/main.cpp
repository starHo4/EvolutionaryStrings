#include "Simulation.hpp"

int main()
{
    string TargetString;
    cout << "Input the favorite string not using space key." << endl;
    cin >> TargetString;
    bool f_crossover = false;
    while (true)
    {
        cout << "Do you need crossover process? y/n" << endl;
        string answer_f_crossover;
        cin >> answer_f_crossover;
        if (answer_f_crossover == "y" || answer_f_crossover == "Y")
        {
            f_crossover = true;
            break;
        }
        else if (answer_f_crossover == "n" || answer_f_crossover == "N")
        {
            f_crossover = false;
            break;
        }
    }

    Simulation simulation(TargetString);
    if (f_crossover)
    {
        simulation.RunWithCrossover();
    }
    else
    {
        simulation.Run();
    }
}