#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{

    float *vetorPar = new float[2];
    float *vetorImpar;

    int cont = 0;
    float auxiliar;
    bool negativo = false;

    while (negativo == false){
        cin >> auxiliar;
        if (auxiliar < 0){
            negativo = true;
        }
        else if (cont < 2){
            vetorPar[cont] = auxiliar;
            cont++;
        }
        else if ((cont % 2) == 0){
            vetorImpar = new float[cont + 1];
            memcpy(vetorImpar, vetorPar, sizeof(float) * cont);
            vetorImpar[cont] = auxiliar;
            delete[] vetorPar;
            cont++;
        }else{
            vetorPar = new float[cont + 1];
            memcpy(vetorPar, vetorImpar, sizeof(float) * cont);
            vetorPar[cont] = auxiliar;
            delete[] vetorImpar;
            cont++;
        }
    }

    if ((cont % 2) == 0){
        int posicao = round(cont/2);
        cout << (vetorPar[posicao] + vetorPar[posicao-1])/2;
    }else{
        cout << vetorImpar[cont/2];
    }

    return 0;
}