#include <iostream>
#include <fstream>
using namespace std;

int main() {
    float nota1, nota2, media;
    int qtd, cont = 0;
    string nome = "Oi", nomeanterior;
    ifstream entrada("entrada.txt");
    ofstream saida("saida.txt");

    entrada >> qtd;

    while(cont<qtd){
        
        cont++;
        nomeanterior = nome;
        entrada >> nome >> nota1 >> nota2;
        media = (nota1+nota2)/2;
        if(media<7){
            if(nomeanterior != nome){
        saida << nome << endl;
            }
        }
    }

  return 0;
}