#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
    int hora, min;
    float tempo, seg;
    ifstream entrada("tempo.txt");
    ofstream saida("horario.txt");

    entrada >> tempo;

    tempo = tempo/1000;
    hora = tempo/3600;
    tempo = tempo - hora*3600;
    min = tempo/60;
    tempo = tempo - min*60;
    seg = tempo;


    saida << hora << ":" << min << ":" << fixed << setprecision(3) << seg;
    return 0;
}