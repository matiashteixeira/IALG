/*  
    Tema Projeto Prático:
        Sistema de Cadastro em Arquivos com Ordenação
    Membros:
        Mateus Henrique Teixeira - 202210162 - 22A
        Camila
        Ana Clara 
*/

#include <iostream>
#include <fstream>

using namespace std;

//----------------------------------Registro para leitura e escrita em binário--------------------------------------------------------

struct cadastro
{
    string nome;
    string rua;
    int idade;
    string profissao;
    float salario;
};


int main(){

    cadastro informacoes;
    ifstream arq_entrada;

    arq_entrada.open("base_de_dados.csv");

    if(arq_entrada.is_open()){
        cout << "Informacoes do arquivo" << endl;
        arq_entrada >> informacoes.nome;
        while(arq_entrada.good()){
            arq_entrada >> informacoes.rua;
            cout << "Nome: " << informacoes.nome << endl;
            cout << "Rua: " << informacoes.rua << endl;
            arq_entrada >> informacoes.idade;
            cout << "Idade: " << informacoes.idade << endl;
            arq_entrada >> informacoes.profissao;
            cout << "Profissão: " << informacoes.profissao << endl;
            arq_entrada >> informacoes.salario;
            cout << "Salário: " << informacoes.salario << endl;
            arq_entrada >> informacoes.nome;
        }
        arq_entrada.close();
    }else{
        cout << "Arquivo nao abriu";
        return EXIT_FAILURE;
    }
    
   
}


