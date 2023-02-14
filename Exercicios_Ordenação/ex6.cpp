#include <iostream>
using namespace std;

void preenche(int vetor[], int tam);
void escreve(int vetor[], int tam);

void ordena_vetor(int vetor[], int tam, int posicao){
    int posMenor, aux;
    for (int i=0; i <= posicao; ++i) {
        posMenor = i;
    for (int j=i+1; j < tam; ++j) {
        if (vetor[j] > vetor[posMenor])
            posMenor = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[posMenor];
    vetor[posMenor] = aux;
}
}


int main(){
    int tam;
    cin >> tam;
    int v[tam];
    preenche(v,tam);
    int posicao;
    cin >> posicao;
    ordena_vetor(v,tam, posicao);
    escreve(v, tam);


    return 0;
}

void preenche(int vetor[], int tam){
    for (int i = 0; i < tam; i++)
        cin >> vetor[i];
}

void escreve(int vetor[], int tam){
    for (int i = 0; i < tam; i++)
        cout << vetor[i] << " ";
}