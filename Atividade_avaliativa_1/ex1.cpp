#include <iostream>

using namespace std;

int main() 
{
    int cidade1, cidade2, vel;
    float tempo;

    cin >> cidade1 >> cidade2 >> vel;
    tempo = float(cidade2-cidade1)/vel;
    cout << tempo;
    
    return 0;
}