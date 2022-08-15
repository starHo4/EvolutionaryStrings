#include "Chromosome.hpp"

Chromosome::Chromosome(mt19937_64 &mt, const string &_Target)
{
    Target = _Target;

    Genome = vector<char>(Target.size(), 0);

    uniform_int_distribution<char> uid_ch(33, 126);
    for (int i = 0; i < Target.size(); i++)
    {
        Genome[i] = uid_ch(mt);
    }

    OutputGenome();
}

void Chromosome::OutputGenome()
{
    string o = "";

    for (int i = 0; i < Genome.size(); i++)
    {
        string tmp(1, Genome[i]);
        o += tmp;
    }

    cout << o << endl;
}