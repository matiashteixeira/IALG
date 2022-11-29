#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

int main() {
    ifstream turma("turma.txt");
    ifstream notas("notas.txt");
    ofstream saida("notas-turma.txt");

    int matricula = 0, matricula_comparativo = 0, cont = 0;
    float nota;
    
    while (turma >> matricula){  //enquanto tiver lendo os arquivos
        //cout << matricula << endl;

    
            while(notas >> matricula_comparativo){
                if(matricula != matricula_comparativo){
                    notas >> nota;
                    
                }else{
                cout << nota << endl;
            }
    
        
    }
    
    
    

  return 0;
}