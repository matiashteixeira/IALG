#include <iostream>
using namespace std;

void escreve(int vetor[], int tam){
    for (int i = 0; i < tam; i++)
        cout << vetor[i] << " ";
    cout << endl;
}

void insertion_sort(int vetor[], int tam){
    int pivo, j;
    for (int i = 1; i < tam; i++){
        pivo = vetor[i];
        j = i - 1;
        while(j>=0 && (pivo < vetor[j])){
            vetor[j+1] = vetor[j];
            j--; 
        }
        vetor[j+1] = pivo;
    
        cout << "pivo: " << pivo << endl;
        escreve(vetor, tam);
    }
}

int main(){
    int vetor[6] = {100, 33, 68, 93, 14, 77};

    insertion_sort(vetor,6);


    return 0;
}