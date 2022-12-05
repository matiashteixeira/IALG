#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int main() {

    ifstream turma("turma.txt");
    
    ofstream saida("notas-turma.txt");

    int matricula = 0, matricula_comparativo = 0, cont = 0;
    float nota;
    
    while (turma >> matricula){  //enquanto tiver lendo os arquivos
        ifstream notas("notas.txt");
        cont = 0;
        while(notas >> matricula_comparativo >> nota){
            if(matricula == matricula_comparativo){
                saida << matricula << " " << nota << endl;
                cont++;
            } 
        }
        if(cont ==0){
            saida << matricula << " 0" << endl;
        }
    }
    
    
    return 0;
}
