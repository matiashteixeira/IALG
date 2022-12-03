#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string arq1, palavra, dados;
    int cont = 0;

    cin >> arq1 >> palavra;
    ifstream entrada(arq1);

    while(entrada >> dados){

        if(dados == palavra){
            cont++;
        }
    }

    cout << cont;
    

    return 0;
}