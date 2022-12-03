#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    int cont = 0;
    string nome; 
    char letra;

    cin >> nome;
    fstream entrada(nome);

    while(entrada >> letra){
        cont++;
    }
    
    cout << cont;

  return 0;
}