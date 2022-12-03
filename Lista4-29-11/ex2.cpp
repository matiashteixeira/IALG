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

    while(cont<qtd){                //A repetição do programa depende de qtd, ou seja, da quantidade de alunos informada
        
        cont++;
        nomeanterior = nome;        //estava com um problema de sair com dois nomes iguais, aí esse nome_anterior resolve o problema
        entrada >> nome >> nota1 >> nota2;
        media = (nota1+nota2)/2;    //média das notas 1 e 2
        if(media<7){                //se a média for abaixo de 7
            if(nomeanterior != nome){            //resolver o problema de printar duas vezes o mesmo nome
        saida << nome << endl;
            }
        }
    }

  return 0;
}