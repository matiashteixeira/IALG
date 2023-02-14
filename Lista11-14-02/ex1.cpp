#include <iostream>
#include <fstream>
using namespace std;

void preenche(float vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        cin >> vetor[i];
}

void escreve(float vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        cout << vetor[i] << " ";
    
}


int main(){
    int K;
    cin >> K;
    float vetor[K];
    preenche(vetor,K);

    
    escreve(vetor,K);


    return 0;
}