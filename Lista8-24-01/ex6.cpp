#include <iostream>
using namespace std;

void aumenta_vetor(string* vetor,int& tamanho){
    tamanho++;
    string* aux = new string[tamanho];
    aux = vetor;
    delete[] vetor;
    vetor = new string[tamanho];
    vetor = aux;
    delete[] aux;
}

int main(){
    int tam1, k = 0;
    cin >> tam1;

    string* v1 = new string[tam1];

    for (int i = 0; i < tam1; i++)
        cin >> v1[i];
    
    string ingrediente;
    bool escreve = true;

    while(ingrediente != "bolor_laranja"){
        cin >> ingrediente;
        for (int i = 0; i < tam1; i++){
            if(ingrediente == v1[i] && escreve == true){
                escreve = false;
            }

            if(escreve){
                aumenta_vetor(v1,tam1);
                v1[tam1] = ingrediente;
            }
        }
    }
    
    return 0;
}