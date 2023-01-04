#include <iostream>

using namespace std;

int main(){
    int aux_positivo = 0, aux_negativo = 0;
    int numeros[8];
    int positivos[8];
    int negativos[8];

    for (int i = 0; i < 8; i++){
        cin >> numeros[i];
        if(numeros[i] > 0){ 
            positivos[aux_positivo] = numeros[i];
            aux_positivo++;     //se der merda coloca uma variavel aqui pra ir aumentando o valor aos poucos
        } else{
            negativos[aux_negativo] = numeros[i];
            aux_negativo++;
            
        }
    }
    for (int i = 0; i < aux_positivo; i++)
        cout << positivos[i] << " ";
    
    cout << endl;
    
    for (int i = 0; i < aux_negativo; i++)
        cout << negativos[i] << " ";

    return 0;
}