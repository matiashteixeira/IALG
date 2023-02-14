#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std; 

string le_celula(ifstream &arquivo)
{
    string celula;
    char c;
    arquivo.read(&c, 1);
    if (c == '\"')
    {
        arquivo.read(&c, 1); // elimina a aspas
        do
        {
            celula += c;
            arquivo.read(&c, 1);
        } while (c != '\"');
        arquivo.read(&c, 1); // elimina o ";"
    }
    else
    {
        do
        {
            celula += c;
            arquivo.read(&c, 1);
        } while (c != ';' and c != '\n' and !arquivo.eof());
    }
    return celula;
}

struct dados
{
    bool apagado = false;
    float preco;
    char codigo_barras[20];
    char descricao[50];
    char status[10];
    char tarja[40];
};

void importarcsv(string entrada, string saida)
{
    ifstream arquivo(entrada.c_str());
    dados base10;
    ofstream arqvsaida(saida.c_str(), ios::binary);
    while (!arquivo.eof()) // Lê o arquivo até o ; e faz o tratamento dos dados
    {
        string preco = le_celula(arquivo);
        int posicao = preco.find(',');
        if (posicao < preco.length())
            preco.replace(preco.find(','), 1, ".");
        base10.preco = stof(preco);
        string codigo_barras = le_celula(arquivo);
        strcpy(base10.codigo_barras, codigo_barras.c_str());
        string descricao = le_celula(arquivo);
        strcpy(base10.descricao, descricao.c_str());
        string status = le_celula(arquivo);
        strcpy(base10.status, status.c_str());
        string tarja = le_celula(arquivo);
        strcpy(base10.tarja, tarja.c_str());

        arqvsaida.write((const char *)&base10, sizeof(dados)); // Convertendo para arquivo binário
    }
}
int main (){

    importarcsv("base10.csv", "arqsaida");
    return 0;
}