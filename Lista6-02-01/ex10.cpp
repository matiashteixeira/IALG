#include <iostream>

using namespace std;

int main(){

    string meses[12] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    float temperaturas[12], maior_temperatura = 0, menor_temperatura;
    int mes_maior, mes_menor;


    for (int i = 0; i < 12; i++){
        cin >> temperaturas[i];

        if(i == 0)
            menor_temperatura = maior_temperatura = temperaturas[i];

        if(temperaturas[i] >= maior_temperatura){
            maior_temperatura = temperaturas[i];
            mes_maior = i;
        }

        if(temperaturas[i] < menor_temperatura){
            menor_temperatura = temperaturas[i];
            mes_menor = i;
        }
    }
    cout << meses[mes_maior] << endl;
    cout << meses[mes_menor];
    return 0;
}