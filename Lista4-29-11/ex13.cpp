#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    float soma, valor;
    int dia;
    char categoria; 
    ifstream ingressos("ingresso.txt");
    
    ingressos >> valor;

    while(ingressos >> dia >> categoria && dia != -1){
        
        if(dia<6){
            soma += valor;
        }
        else if(dia <= 13){
            if(categoria == 'E'){
                soma += valor*0.85;
            } else if (categoria == 'A'){
                soma += valor*0.9;
            }
        } else if(dia <= 24){
            if(categoria == 'E'){
                soma += valor*0.9;
            } else if(categoria == 'A'){
                soma += valor*0.95;
            }
        }
    }
    
    cout << soma;

  return 0;
}