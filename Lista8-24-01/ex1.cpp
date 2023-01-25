#include <iostream>

using namespace std;

void redimensionar(float *x, int &tamanho) {
    float *aux = new float[tamanho + 1];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho += 1;
    delete[] aux;
}

int main(){
    float Num;
    int k = 0, tamanho = 2;
    float *vetor1 = new float[2];
    
    do{
        cin >> vetor1[k];
        Num = vetor1[k];
        k++;
        redimensionar(vetor1,tamanho);
    } while (Num > 0);
    
    if(tamanho%2 == 0){

    }

    return 0;
}

