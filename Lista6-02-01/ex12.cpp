#include <iostream>

using namespace std;

int main(){
    int tam, posicao;
    cin >> tam;
    int primeiro_vetor[tam];
    int segundo_vetor[(tam*2)];

    for (int i = 0; i < tam; i++)
        cin >> primeiro_vetor[i];
    
    for (int i = 0; i < tam; i++)
        cin >> segundo_vetor[i];

    for (int i = 0; i < tam; i++){
        
        segundo_vetor[posicao+i] = segundo_vetor[posicao+i+1]; //tem q acabar
    }
    
    


    return 0;
}