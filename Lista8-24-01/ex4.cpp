#include <iostream>
using namespace std;

void aumenta_vetor(int& tamanho,int* vetor){
    tamanho++;
    int* aux = new int[tamanho];
    aux = vetor;
    delete[] vetor;
    vetor = new int[tamanho];
    vetor = aux;
    delete[] aux;
}


int main(){

//entrada de dados-----------------------------------------------
    int tam1, tam2, tam3, repete = 0;
    cin >> tam1;
    int* vetor1 = new int[tam1];

    for (int i = 0; i < tam1; i++)
        cin >> vetor1[i];
    
    cin >> tam2;
    int* vetor2 = new int[tam2];

    for (int i = 0; i < tam2; i++)
        cin >> vetor2[i];

//--------------------------------------------------------------------
    int aux, k = 0, j = 0;
    tam3 = tam1 + tam2;
    aux = tam3;
    while (aux > 0){
        if(vetor1[k] >= vetor2[j]){
            vetor3
        }
        
        
        aux--;
    }
    {
        /* code */
    }
    
    return 0;
}   