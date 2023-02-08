#include <iostream>
using namespace std;

int main(){
    int linha, coluna;
    cin >> linha >> coluna;

    int **matriz;
    matriz = new int*[linha];

    for (int i = 0; i < linha; i++){
        matriz[i] = new int[coluna];
    }

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            cin >> matriz[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < linha; i++){
        if(i%2 == 0){
            for (int j = 0; j < coluna; j++)
                cout << matriz[i][j] << " ";
        }else{
            for (int j = (coluna-1); j >= 0; j--)
                cout << matriz[i][j] << " ";
        }

    }

    for (int i = 0; i < linha; i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}