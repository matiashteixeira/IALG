#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int qtd_palavras = 0, qtd_maxima = 0, qtd_letras, asterisco;
    cin >> qtd_palavras;
    string palavras[qtd_palavras];

    for (int i = 0; i < qtd_palavras; i++){
        cin >> palavras[i];
        qtd_letras = palavras[i].size();

        if(qtd_letras > qtd_maxima){
            qtd_maxima = qtd_letras;
        }
    }

    for (int i = 0; i < qtd_palavras; i++){
        asterisco = 0;
        
        if(palavras[i].size() != qtd_maxima){
            asterisco = qtd_maxima - palavras[i].size();

                while(asterisco > 0){
                    cout << "*";
                    asterisco--;
                }
        }
        cout << palavras[i] << endl;
    }
    return 0;
}