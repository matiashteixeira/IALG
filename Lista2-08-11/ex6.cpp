#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{   
    ifstream entrada("dados.txt");
    ofstream saida("media.txt");
    float v1, v2, v3, v4, v5, v6, v7, v8, media;
    entrada >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;
    media = (v1+v2+v3+v4+v5+v6+v7+v8)/8;
    saida.precision(5);
    saida << media;
    return 0;
}