#include <iostream>
using namespace std;

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
    }
    
}


int main(){
    int tam1, tam2, tam3, repete = 0, aux = 0;
    cin >> tam1;
    int *vet1 = new int[tam1];

    for (int i = 0; i < tam1; i++)
        cin >> vet1[i];

    cin >> tam2;
    int *vet2 = new int[tam2];
    
    for (int i = 0; i < tam2; i++)
        cin >> vet2[i];

    for (int i = 0; i < tam1; i++){
        for (int j = 0; j < tam2; j++){
            if(vet1[i] == vet2[j])
                repete++;
        }
    }

    tam3 = tam1+tam2-repete;
    int *vet3 = new int[tam3];
    bool imprime = 1;

    vet3 = vet1;
    
    for (int i = 0; i < tam2; i++){
        imprime = 1;
        for (int j = 0; j < tam3; j++){
            if(vet3[j] == vet2[i]){
                imprime = 0;
            }
        }
        if(imprime){
            vet3[tam1+aux] = vet2[i];
            aux++;
        }
    }

    selection_sort(vet3,tam3);

    for (int i = 0; i < tam3; i++){
        cout << vet3[i] << " ";
    }

    delete[] vet1, vet2, vet3;

    return 0;
}