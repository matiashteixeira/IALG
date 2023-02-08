#include <iostream>
using namespace std;


int main(){
    int N, M;
    cin >> N >> M;

    float** matriz = new float*[N];

    for (int i = 0; i < N; i++)
        matriz[i] = new float[M];
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cin >> matriz[i][j];
    }

    
    float menor = matriz[0][0], soma  = 0;
    int coluna_menor = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(matriz[i][j] < menor){
            menor = matriz[i][j];
            coluna_menor = j;
            }
        }  
    }    

    cout << menor << endl;

    for (int i = 0; i < N; i++){
        soma += matriz[i][coluna_menor];
    }
    cout << soma;
    
    
    
    for (int i = 0; i < N; i++)
        delete[] matriz[i];
    delete[] matriz;
    
    return 0;
}