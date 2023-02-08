#include <iostream>
using namespace std;

void escreve_matriz(int** matriz, int tamanho);


int main(){
    int tamanho, soma = 0;
    cin >> tamanho;

    int** matriz = new int*[tamanho];

    for (int i = 0; i < tamanho; i++){
        matriz[i] = new int[tamanho];
    }

    escreve_matriz(matriz,tamanho);

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if(i+j <= 3){
                soma += matriz[i][j];
            }
        }
    }
    cout << soma;
    
    
    return 0;
}

void escreve_matriz(int** matriz, int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            cin >> matriz[i][j]; 
        }
    }
}

