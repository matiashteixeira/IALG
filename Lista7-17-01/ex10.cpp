#include <iostream>
#include <cstring>

using namespace std;

void imprime(char *v, int tamanho){
    for (int i = 0; i < tamanho; i++)
        cout << v[i] << " ";
        
    
}

int main(){

    //---------------------------Entrada de Dados------------------------------
    int tam1;
    cin >> tam1;
    char *vetor1 = new char [tam1];

    for (int i = 0; i < tam1; i++)
        cin >> vetor1[i];

    int tam2;
    cin >> tam2;
    char *vetor2 = new char [tam2];

    int repete = 0;
    int k = 0;


    for (int i = 0; i < tam2; i++)
        cin >> vetor2[i];

    for (int i = 0; i < tam1; i++){
        for (int j = 0; j < tam2; j++){
            if(vetor1[i] == vetor2[j]){
                repete++;
            }
        }
    }
    
    int tam3;
    bool printa = true;
    tam3 = tam1 - repete;
    char *vetor3 = new char [tam3];


    for (int i = 0; i < tam1; i++){
        for (int j = 0; j < tam2; j++){
            if(vetor1[i] == vetor2[j]){
                printa = false;
            }    
        }
        
        if(printa){    
                vetor3[k] = vetor1[i];
                k++; 
        }else{
                printa = true;
            }
    }
    
    
    imprime(vetor3,tam3);

    return 0;
}