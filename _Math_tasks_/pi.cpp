#include <cmath>
#include <functional>
#include <algorithm>
#include <array>
#include <iostream>
#include <random>
using namespace std;

template <typename E = mt19937, typename D = uniform_real_distribution<>>
double compute_pi(E& engine, D& dist, int const samples = 1000000)
{
    auto hit = 0;
     for (auto i = 0; i < samples; i++)
     {
         auto x = dist(engine);
         auto y = dist(engine);
         if ( y <= sqrt(1 - pow(x, 2))) hit += 1;
     }
     return 4.0 * hit / samples;
}

int main (int argc, char* argv[])
{
    random_device rd;
    auto seed_data = array<int, mt19937::state_size> {};
    generate(begin(seed_data), end(seed_data), ref(rd));
    seed_seq seq(begin(seed_data), end(seed_data));
    auto eng = mt19937 { seq };
    auto dist = uniform_real_distribution<> { 0, 1 };
    
    for (auto j = 0; j < 10; j++)
        cout << compute_pi(eng, dist) << "\n";
}
