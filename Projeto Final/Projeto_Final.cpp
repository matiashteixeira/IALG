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

struct cadastro   //Registro para leitura e escrita em binário
{
    string codigo;
    string produto;
    string situacao;
    float valor_atual;
    float valor_meta;
};

int tamanho_arquivo(cadastro* vetor,ifstream& fin){ //função que define o tamanho do arquivo csv
    streampos size;
    size = fin.tellg();
    vetor = new cadastro [size];
    fin.seekg(0, ios::beg);
    fin.read((char*)&vetor, size);
    fin.close();
    return size;
}

void escrever_binario(cadastro* vetor,ofstream& fon,int size){
    fon.write((char*)&vetor,size);
}



int main(){
    cadastro* informacoes;
    ifstream fin;
    ofstream fon;

    fin.open("base10.csv");

    if(!fin.is_open()){
        return EXIT_FAILURE;
    }else{
        //cout << tamanho_arquivo(vetor,fin);
        int size = tamanho_arquivo(informacoes,fin);
        fon.open("dados.bin", ios_base::out);

        if(!fon.is_open()){
            return EXIT_FAILURE;
        }else{
            escrever_binario(informacoes,fon,size);
            cout << "oi";
        }  
    }
    
    
}
/*

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

*/
