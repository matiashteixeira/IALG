#include <iostream>
using namespace std;

int main(){
    int** matriz = new int*[10];

    for (int i = 0; i < 10; i++){
        matriz[i] = new int[10];
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)
            cin >> matriz[i][j];
    }

    int maior = matriz[0][0], linha_maior = 0; 
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
                linha_maior = i;
            }
        }   
    }

    int menor = matriz[linha_maior][0], coluna_menor = 0;

    for (int i = 0; i < 10; i++)
    {
        if(matriz[linha_maior][i] < menor){
            menor = matriz[linha_maior][i];
            coluna_menor = i;
        }
    }
    
    cout << menor << endl;
    cout << linha_maior << " " << coluna_menor;
    


    for (int i = 0; i < 10; i++)
        delete[] matriz[i];
    
    delete[] matriz;


    return 0;
}