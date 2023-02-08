#include <iostream>
using namespace std;

int main(){
    int linha, coluna;
    double num, soma = 0;
    cin >> linha >> coluna;

//---------------------Aloca a matriz dinamicamente---------------------------------------

    double** matriz;
    matriz = new double*[linha];

    for (int i = 0; i < linha; i++){
        matriz[i] = new double[coluna];
    }
    
//----------------Entrada de valores e soma dos mesmos--------------------------------------

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            cin >> num;
            matriz[i][j] = num;
            soma += num;
        }
    }
    cout << soma;

//-------------------------------Deleta a matriz---------------------------------------
    for (int i = 0; i < linha; i++){
        delete[] matriz[i];
    }
    delete[] matriz; 

    return 0;
}