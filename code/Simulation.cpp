#include "Simulation.hpp"

#pragma region Constructor
Simulation::Simulation(const string &_Target)
{
    // Initialize the random generator with "SEED" as seed.
    mt.seed(SEED);

    // The target of this program is "Target".
    Target = _Target;
    PerfectScore = Target.size() * Target.size();

    Population = vector<Chromosome>(N);

    BestGenome = "";
    BestFitness = 0;
}
#pragma endregion Constructor

#pragma region PublicMethods
void Simulation::RunWithCrossover()
{
    // Output the target.
    cout << "Target is \"" << Target << "\"" << endl;

    // Initialize Population including the genome.
    int g = 0;
    for (int i = 0; i < N; i++)
    {
        Population[i] = Chromosome(mt, Target);
    }
    OutputBestGenome(g);
    g++;

    // Evolutionary Simulation
    for (; g <= MaxGenerations; g++)
    {
        InheritNewGenerationWithCrossover();
        OutputBestGenome(g);

        if (BestGenome == Target)
        {
            exit(0);
        }
    }
}

void Simulation::Run()
{
    // Output the target.
    cout << "Target is \"" << Target << "\"" << endl;

    // Initialize Population including the genome.
    int g = 0;
    for (int i = 0; i < N; i++)
    {
        Population[i] = Chromosome(mt, Target);
    }
    OutputBestGenome(g);
    g++;

    // Evolutionary Simulation
    for (; g <= MaxGenerations; g++)
    {
        InheritNewGeneration();
        OutputBestGenome(g);

        if (BestGenome == Target)
        {
            exit(0);
        }
    }
}
#pragma endregion PublicMethods

#pragma region PrivateMethods
void Simulation::InheritNewGenerationWithCrossover()
{
    //* Selection *//
    // Select the better genomes with Roulette selection
    // First, calculating the sum of fitness of the population
    vector<Chromosome> newFathers = vector<Chromosome>(N);
    vector<Chromosome> newMothers = vector<Chromosome>(N);
    double sumFitness = 0;
    for (int i = 0; i < Population.size(); i++)
    {
        sumFitness += Population[i].Fitness;
    }
    // Roulette Selection
    uniform_real_distribution<double> udd_1(0, 1);
    for (int i = 0; i < newFathers.size(); i++)
    {
        double r = udd_1(mt);
        int j = 0;
        for (j = 0; j < Population.size(); j++)
        {
            if (sumFitness == 0)
            {
                r -= (1 / Population.size());
            }
            else
            {
                r -= (Population[j].Fitness / sumFitness);
            }
            if (r < 0)
            {
                break;
            }
        }
        newFathers[i] = Population[j];
    }
    for (int i = 0; i < newMothers.size(); i++)
    {
        double r = udd_1(mt);
        int j = 0;
        for (j = 0; j < Population.size(); j++)
        {
            if (sumFitness == 0)
            {
                r -= (1 / Population.size());
            }
            else
            {
                r -= (Population[j].Fitness / sumFitness);
            }
            if (r < 0)
            {
                break;
            }
        }
        newMothers[i] = Population[j];
    }

    //* Crossover *//
    if (N % 2 == 1)
    {
        cout << "Set the value of \"N\" as an even value" << endl;
        abort();
    }
    vector<Chromosome> newPopulation(0);
    for (int i = 0; i < N / 2; i++)
    {
        vector<char> newGenome1 = newFathers[i].Genome;
        vector<char> newGenome2 = newMothers[i].Genome;
        double r = udd_1(mt);
        double r_c = udd_1(mt);
        for (int j = 0; j < Target.size(); j++)
        {
            if (r < 0.5)
            {
                newGenome1[j] = newMothers[i].Genome[j];
                newGenome2[j] = newFathers[i].Genome[j];
            }
        }
        Chromosome newChrom1(Target, newGenome1);
        Chromosome newChrom2(Target, newGenome2);
        newPopulation.push_back(newChrom1);
        newPopulation.push_back(newChrom2);
    }
    Population = newPopulation;

    //* Mutation *//
    for (int i = 0; i < Population.size(); i++)
    {
        Population[i].Mutation(mt, MutationRate);
    }

    //* Evaluation of Fitness *//
    // Calc all fitnessess of population
    for (int i = 0; i < Population.size(); i++)
    {
        Population[i].CalcFitness();
    }
}

void Simulation::InheritNewGeneration()
{
    //* Selection *//
    // Select the better genomes with Roulette selection
    // First, calculating the sum of fitness of the population
    vector<Chromosome> newPopulation = vector<Chromosome>(N);
    double sumFitness = 0;
    for (int i = 0; i < Population.size(); i++)
    {
        sumFitness += Population[i].Fitness;
    }
    // Roulette Selection
    uniform_real_distribution<double> udd_1(0, 1);
    uniform_int_distribution<int> uid_N(0, N - 1);
    if (sumFitness == 0)
    {
        for (int i = 0; i < Population.size(); i++)
        {
            double n = uid_N(mt);
            newPopulation[i] = Population[i];
        }
    }
    else
    {
        for (int i = 0; i < Population.size(); i++)
        {
            double r = udd_1(mt);
            int j = 0;
            for (j = 0; j < Population.size(); j++)
            {
                r -= (Population[j].Fitness / sumFitness);
                if (r < 0)
                {
                    break;
                }
            }
            newPopulation[i] = Population[j];
        }
    }
    Population = newPopulation;

    //* Mutation *//
    for (int i = 0; i < Population.size(); i++)
    {
        Population[i].Mutation(mt, MutationRate);
    }

    //* Evaluation of Fitness *//
    // Calc all fitnessess of population
    for (int i = 0; i < Population.size(); i++)
    {
        Population[i].CalcFitness();
    }
}

void Simulation::OutputBestGenome(const int &_g)
{
    cout << _g << " :: ";

    // Search the best genome from population.
    sort(Population.begin(), Population.end(), [](const Chromosome &a, const Chromosome &b)
         { return a.Fitness > b.Fitness; });
    BestGenome = Population[0].OutputGenome();
    BestFitness = Population[0].Fitness;

    cout << "BestGenome : " << BestGenome << " , BestFitness : " << Population[0].Fitness << endl;
}
#pragma endregion PrivateMethods