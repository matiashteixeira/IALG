#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct lava_jato{
    int fase;
    string nome;
};

void selection_sort_crescente(lava_jato* vetor, int tam);
void selection_sort_decrescente(lava_jato* vetor, int inicio, int fim);

int main(){
    int K, i = 0;
    cin >> K;

    lava_jato* dados;
    dados = new lava_jato[100];
    
    ifstream arquivo("fases.txt");

    while(!arquivo.eof()){
        arquivo >> dados[i].fase >> dados[i].nome;
        i++;
    }
    
    selection_sort_crescente(dados,K);
    selection_sort_decrescente(dados,K,i);
    
    cout << endl;

    for (int j = 0; j < i; j++)
        cout << dados[j].nome << endl;
        
    delete[] dados;
    return 0;
}

void selection_sort_crescente(lava_jato* vetor, int tam){
    int menor;
    lava_jato aux;
    for (int i = 0; i < tam-1; i++){
        menor = i;
        for (int j = i+1; j < tam; j++){
            if(vetor[j].fase < vetor[menor].fase){
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

void selection_sort_decrescente(lava_jato* vetor, int inicio, int fim){
    int menor;
    lava_jato aux;
    for (int i = inicio; i < fim-1; i++){
        menor = i;
        for (int j = i+1; j < fim; j++){
            if(vetor[j].fase > vetor[menor].fase){
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}
