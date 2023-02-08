#include <iostream>
using namespace std;

struct funcionarios{
    string nome;
    int idade, filhos;
    char sexo;
    float salario;
};


int main(){
    int qtd, s_salario = 0, s_filhos = 0;
    cin >> qtd;
    funcionarios* funcionario = new funcionarios[qtd];

    for (int i = 0; i < qtd; i++){
        cin >> funcionario[i].nome >> funcionario[i].idade >> funcionario[i].sexo
            >> funcionario[i].salario >> funcionario[i].filhos;
    }

    for (int i = 0; i < qtd; i++){
        s_salario += funcionario[i].salario;
        s_filhos += funcionario[i].filhos;
    }

    cout << endl;

    for (int i = 0; i < qtd; i++){
        if(funcionario[i].salario < (s_salario/qtd) && funcionario[i].filhos > (s_filhos/qtd)){
            cout << funcionario[i].nome << endl;
        }
    }
    delete[] funcionario;

    return 0;
}