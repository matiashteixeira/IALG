#include <iostream>
#include <cmath>

using namespace std;

//função que recebe um vetor e redimensiona o vetor adicionando duas novas posições a cada redimensionamento
void redimensionar(int *x, int &tamanho) {
    int *aux = new int[tamanho + 1];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho += 1;
    delete [] aux;
}



//função que recebe um vetor e redimensiona o vetor adicionando duas novas posições a cada redimensionamento
void redimensionar2(int *x, int &tamanho) {
    int *aux = new int[tamanho + 2];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho += 2;
}

//função que redimensiona o vetor adicionando três novas posições a cada redimensionamento

void redimensionar3(int *x, int &tamanho) {
    int *aux = new int[tamanho + 3];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho += 3;
}

//função que redimensiona o vetor adicionando quatro novas posições a cada redimensionamento

void redimensionar4(int *x, int &tamanho) {
    int *aux = new int[tamanho + 4];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho += 4;
}

//função que dobra o vetor de tamanho a cada redimensionamento

void dobrarVetor(int *x, int &tamanho) {
    int *aux = new int[tamanho * 2];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho *= 2;
}

//função que aumenta o vetor com 20% a mais de posições (usando arredondamento para cima)

void aumentarVetor(int *x, int &tamanho) {
    int *aux = new int[ceil(tamanho * 1.2)];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho = ceil(tamanho * 1.2);
}

//função que aumenta o vetor com 40% a mais de posições (usando arredondamento para cima)

void aumentarVetor2(int *x, int &tamanho) {
    int *aux = new int[ceil(tamanho * 1.4)];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho = ceil(tamanho * 1.4);
}

//função que aumenta o vetor com 50% a mais de posições (usando arredondamento para cima)

void aumentarVetor3(int *x, int &tamanho) {
    int *aux = new int[ceil(tamanho * 1.5)];
    for(int i = 0; i < tamanho; i++){
        aux[i] = x[i];
    }
    delete [] x;
    x = aux;
    tamanho = ceil(tamanho * 1.5);
}

//base para os exercicios

void redimensionarCapacidade() {
    nomeStruct *aux = new nomeStruct[capacidadeMaxima + 2];
    for(int i = 0; i < capacidadeMaxima; i++){
        aux[i] = listaDeAlgo[i];
    }
    delete [] listaDeAlgo;
    listaDe = aux;
    capacidadeMaxima += 2;
}