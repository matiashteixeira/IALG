#include <iostream>

using namespace std;

int main(){
    int numeros[7];
    bool quebra_linha = 0;



    for (int i = 0; i < 7; i++)
        cin >> numeros[i];


    for (int i = 0; i < 7; i++){

        if(numeros[i]%2 == 0){
            cout << numeros[i] << " ";
            quebra_linha = 1;
            
        }
    }

    if(quebra_linha){    
        cout << endl;            
        quebra_linha = 0;
    }else{
        cout << "0" << endl;
    }


    for (int i = 0; i < 7; i++){

        if(numeros[i]%3 == 0){
            cout << numeros[i] << " ";
            quebra_linha = 1;
        }
    }

    if(quebra_linha){    
        cout << endl;
        quebra_linha = 0;
    }else{
        cout << "0" << endl;
    }

    for (int i = 0; i < 7; i++){
    
        if(numeros[i]%2 == 0 && numeros[i]%3 == 0){
            cout << numeros[i] << " ";
            quebra_linha = 1;
        }
    }

    if(!quebra_linha)
        cout << "0";

    return 0;
}