#include "Chromosome.hpp"

#pragma region Constructor
Chromosome::Chromosome(mt19937_64 &mt, const string &_Target)
{
    Target = _Target;

    Genome = vector<char>(Target.size(), 0);

    uniform_int_distribution<char> uid_ch(33, 126);
    for (int i = 0; i < Target.size(); i++)
    {
        Genome[i] = uid_ch(mt);
    }

    CalcFitness();
}

Chromosome::Chromosome(const string &_Target, const vector<char> &_Genome)
{
    Target = _Target;
    Genome = _Genome;
    CalcFitness();
}
#pragma endregion Constructor

#pragma region PublicMethods
string Chromosome::OutputGenome()
{
    string o = "";

    for (int i = 0; i < Genome.size(); i++)
    {
        string tmp(1, Genome[i]);
        o += tmp;
    }

    return o;
}

void Chromosome::CalcFitness()
{
    int fitness = 0;
    for (int i = 0; i < Genome.size(); i++)
    {
        if (Target[i] == Genome[i])
        {
            fitness++;
        }
    }
    fitness = pow(fitness, 2);

    Fitness = fitness;
}

void Chromosome::Mutation(mt19937_64 &mt, const double &_MutationRate)
{
    uniform_real_distribution<double> udd_1(0, 1);
    uniform_int_distribution<char> uid_ch(33, 126);
    for (int i = 0; i < Genome.size(); i++)
    {
        double r = udd_1(mt);
        if (r < _MutationRate)
        {
            Genome[i] = uid_ch(mt);
        }
    }
}
#pragma endregion PublicMethods

#pragma region PrivateMethods
#pragma endregion PrivateMethods