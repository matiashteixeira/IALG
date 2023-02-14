#include <iostream>
using namespace std;

int main(){
    int tam1;
    cin >> tam1;
    string* lista1 = new string[tam1];

    for (int i = 0; i < tam1; i++){
        cin >> lista1[i];
    }

    int tam2;
    cin >> tam2;
    string* lista2 = new string[tam2];

    for (int i = 0; i < tam2; i++){
        cin >> lista2[i];
    }

    cout << endl;
    bool verifica, nada = 1;

    for (int i = 0; i < tam1; i++){
        verifica = 0;
        for (int j = 0; j < tam2; j++){
            if(lista1[i] == lista2[j]){
                verifica = 1;
            }
        }
        if(!verifica){
            cout << lista1[i] << endl;
            nada = 0;
        }
    }

    if(nada)
        cout << "NADA";

    return 0;
}