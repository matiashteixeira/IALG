#include <iostream>
using namespace std;

void escreve(int vetor[], int tam){
    for (int i = 0; i < tam; i++)
        cout << vetor[i] << " ";
    cout << endl;
}

void selection_sort(int vetor[], int tam){
    int menor, aux;
    for (int i = 0; i < tam-1; i++){
        menor = i;
        for (int j = i+1; j < tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;

        cout << menor << endl;
        escreve(vetor,tam);
    }
    
}

int main(){
    int vetor[6] = {100, 33, 68, 52, 14, 77};
    selection_sort(vetor,6);


    return 0;
}