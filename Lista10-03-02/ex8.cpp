#include <iostream>
using namespace std;    

struct funcionario{
    int codigo;
    float salarios[];
};

void aumenta_vetor(funcionario* vetor,int tamanho){
    funcionario* aux;
    aux = new funcionario[tamanho];
    aux = vetor;
    delete[] vetor;
    vetor = new funcionario[tamanho];
    vetor = aux;
    delete[] aux;
}

void aumenta_vetor_inteiro(int* vetor,int tamanho){
    int* aux;
    aux = new int[tamanho];
    aux = vetor;
    delete[] vetor;
    vetor = new int[tamanho];
    vetor = aux;
    delete[] aux;
}



int main(){
    funcionario* informacoes;
    informacoes = new funcionario[1];
    float salario;
    int* posicao_salario = new int[1];
    cin >> salario;

    cin >> informacoes->codigo;

    aumenta_vetor(informacoes,informacoes->codigo);
    aumenta_vetor_inteiro(posicao_salario,informacoes->codigo);

    while(informacoes->codigo != -1){

        cin >> informacoes[informacoes->codigo].salarios[];


    }




    return 0;
}