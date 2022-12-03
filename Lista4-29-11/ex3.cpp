#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream turma("turma.txt");
    ifstream notas("notas.txt");
    ofstream saida("notas-turma.txt");

    int matricula = 0, matricula_comparativo = 0, cont = 0;
    float nota;
    
    while (turma >> matricula){  //enquanto tiver lendo os arquivos
        notas >> matricula_comparativo;
        cout << matricula_comparativo << endl;

        if(matricula == matricula_comparativo){
            notas >> nota;
            saida << matricula << " " << nota << endl;
        }

    }
    return 0;
}