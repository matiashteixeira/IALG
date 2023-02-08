#include <iostream>
#include <cstring>
using namespace std;

void aumenta_vetor(int* vetor, int i, int& max);
void imprime(int i,int* vetor);

int main(){
    int Num, i = 0, max = 2;
    int *vetor = new int[2];

    do{
        cin >> vetor[i];
        Num = vetor[i];
        i++;
        if((i) == max){
            aumenta_vetor(vetor, i, max);
        }
        
    } while (Num != -1);
    
    
    imprime(i,vetor);
    
    return 0;
}

void aumenta_vetor(int* vetor, int i, int& max){
    
    max = max + 2;   //incrementa o valor correto do vetor principal
    int *aux = new int[max];   //cria um vetor auxiliar
     
    aux = vetor;    //copia o vetor principal

    delete[] vetor;  //deleta o vetor principal
    vetor = new int[max]; //aumenta o tamanho do vetor principal

    vetor = aux;     //copia os valores de volta para o vetor principal
    
    delete[] aux;  //deleta o auxiliar
}

void imprime(int i,int* vetor){
    if(i%2 == 0){
        float divisao;
        divisao = vetor[(i/2)-1];
        cout << divisao/2;
    }else{
        float divisao;
        divisao = (vetor[i/2] + vetor[i/2-1])/2;
        cout << divisao;
    }
}