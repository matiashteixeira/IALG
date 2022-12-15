#include <iostream>

using namespace std;

int main(){
    int qtd;
    double altura = 0, menor = 3.0, maior = 0, altura_anterior = 0, media_m = 0, media_f = 0, cont_f = 0, cont_m = 0, media_turma, soma_f = 0, soma_m = 0;
    char genero;

    cin >> qtd;

    while(qtd>0){
        qtd--;
        cin >> altura >> genero;

        if(altura > maior){
            maior = altura;
        }
        else if(altura < menor){
            menor = altura;
        }

        if(genero == 'f'){
            cont_f++;
            soma_f += altura;
            media_f = soma_f/cont_f;
        } else{
            cont_m++;
            soma_m += altura;
            media_m = soma_m/cont_m;
        }
    }

    cout << maior << endl << menor << endl;

    if(cont_f == 0){
        cout << "erro" << endl;
    } else{
        cout << media_f << endl;
    }

    if(cont_m == 0){
        cout << "erro" << endl;
    } else{
        cout << media_m << endl;
    }

    media_turma = (media_m*cont_m + media_f*cont_f)/(cont_m+cont_f);
    cout << media_turma;

    return 0;
}