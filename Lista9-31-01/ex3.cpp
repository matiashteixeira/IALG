#include <iostream>
using namespace std;


int main(){
    int N, M, qtd_linhas, soma;
    cin >> N >> M;

    int** matriz = new int* [N];

    for (int i = 0; i < N; i++){
        matriz[i] = new int[M];
    }
        
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cin >> matriz[i][j];
    }
        
    cin >> qtd_linhas;
    int* vetor = new int [qtd_linhas];

    for (int i = 0; i < qtd_linhas; i++)
        cin >> vetor[i];

    for (int j = 0; j < qtd_linhas; j++){

        soma = 0;
        int linha;
        linha = vetor[j] - 1;

        for (int i = 0; i < M; i++){
            soma += matriz[linha][i];
        }
        cout << soma << endl;
    }

    for (int i = 0; i < N; i++)
    {
        delete[] matriz[i];
    }

    delete[] matriz;
    delete[] vetor;
        


    return 0;
}