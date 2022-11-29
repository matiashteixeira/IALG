#include <iostream>
#include <fstream>
using namespace std;

int main() {
    float numero, soma = 0;
    string nome;
    cin >> nome;
    fstream arquivo(nome);

        while (arquivo >> numero){
            soma += numero;
        }
    cout << soma << endl; 
  return 0;
}