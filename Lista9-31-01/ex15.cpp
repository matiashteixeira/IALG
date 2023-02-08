#include <iostream>
using namespace std;

void escreve_matriz(int** matriz1, int** matriz2);
void multiplica_matriz(int** matriz1, int** matriz2, int** matriz3);
void imprime_matriz(int** matriz3);

int main(){

    int **matriz1, **matriz2, **matriz3; //Declaração e alocação de variáveis

    matriz1 = new int*[3];
    matriz2 = new int*[3];
    matriz3 = new int*[3];

    for (int i = 0; i < 3; i++){
        matriz1[i] = new int[3];
        matriz2[i] = new int[3];
        matriz3[i] = new int[3];
    }

    escreve_matriz(matriz1,matriz2); //Entrada de dados das matrizes
    multiplica_matriz(matriz1,matriz2,matriz3); //Multiplica as matrizes
    imprime_matriz(matriz3);
    
    return 0;
}

void escreve_matriz(int** matriz1, int** matriz2){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz1[i][j]; 
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz2[i][j]; 
        }
    }
}

void multiplica_matriz(int** matriz1, int** matriz2, int** matriz3){
    int coluna, linha = 0, multiplicacao, soma;
    for (int k = 0; k < 3; k++){
        coluna = 0;
        for (int i = 0; i < 3; i++){
            soma = 0;
            for (int j = 0; j < 3; j++){
                multiplicacao = matriz1[k][j] * matriz2[j][i];
                soma += multiplicacao;
            }
            matriz3[linha][coluna] = soma;    
            coluna++;    
        }   
        linha++;    
    }
}

void imprime_matriz(int** matriz3){
    cout << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz3[i][j] << " ";
        }
        cout << endl;
    }
}