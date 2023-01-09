#include <iostream>

using namespace std;

int main(){
    //----------------------------Variáveis---------------------------------------------------------------

    int tam, posicao, cont = 0, adiciona = 0, aux = 0;
    cin >> tam;
    int primeiro_vetor[tam];
    int segundo_vetor[(tam*2)];

//---------------------------------Entrada-de-dados--------------------------------------------------------
    for (int i = 0; i < tam; i++)
        cin >> primeiro_vetor[i];
    
    for (int i = 0; i < tam; i++)
        cin >> segundo_vetor[i];

    cin >> posicao;

//-------------------------Adição-no-segundo-vetor-----------------------------------------------------------------

    for (int i = 0; i < tam; i++){

        while((tam-cont+aux)>posicao){
            segundo_vetor[(tam-cont+aux)] = segundo_vetor[(tam-cont+aux-1)]; 
            cont++;
        }
        cont= 0;

        segundo_vetor[posicao] = primeiro_vetor[aux];
        aux++;

        for (int i = 0; i < (tam+aux); i++){
            cout << segundo_vetor[i] << " ";
        }
        cout << endl; 
    }
    return 0;
}