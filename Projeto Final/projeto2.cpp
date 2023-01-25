#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Cadastro {
    string nome;
    string endereco;
    string email;
    string telefone;
};

// Função para mostrar os detalhes dos usuários
void mostrarDetalhes(Cadastro c) {
    cout << "Nome: " << c.nome << endl;
    cout << "Endereco: " << c.endereco << endl;
    cout << "Email: " << c.email << endl;
    cout << "Telefone: " << c.telefone << endl;
    cout << endl;
}

// Função para salvar no arquivo
void salvarNoArquivo(Cadastro c) {
    ofstream arquivo("cadastro.bin", ios::binary | ios::app);
    arquivo.write((char*)&c, sizeof(c));
    arquivo.close();
}

// Função para buscar no arquivo
void buscarNoArquivo(string nome) {
    ifstream arquivo("cadastro.bin", ios::binary);
    Cadastro c;
    while(arquivo.read((char*)&c, sizeof(c))) {
        if(c.nome == nome) {
            mostrarDetalhes(c);
        }
    }
    arquivo.close();
}

// Função para atualizar no arquivo
void atualizarNoArquivo(string nome, Cadastro atualizado) {
    fstream arquivo("cadastro.bin", ios::binary | ios::in | ios::out);
    Cadastro c;
    int posicao = -1;
    int contador = 0;
    while(arquivo.read((char*)&c, sizeof(c))) {
        if(c.nome == nome) {
            posicao = contador;
        }
        contador++;
    }
    if(posicao != -1) {
        arquivo.seekp(posicao * sizeof(atualizado), ios::beg);
        arquivo.write((char*)&atualizado, sizeof(atualizado));
    }
    arquivo.close();
}

int main() {
    // Criando um novo cadastro
    Cadastro c;
    c.nome = "Maria";
    c.endereco = "Rua das Flores, 123";
    c.email = "maria@email.com";
    c.telefone = "9999-9999";
    // Salvando no arquivo
    salvarNoArquivo(c);
    // Buscando no arquivo
    buscarNoArquivo("Maria");
    // Atualizando no arquivo
    c.endereco = "Rua das Rosas, 123";
    atualizarNoArquivo("Maria", c);
    // Buscando no arquivo
    buscarNoArquivo("Maria");
    return 0;
}