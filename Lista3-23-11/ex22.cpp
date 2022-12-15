#include <iostream>

using namespace std;

int main() 
{
    int carga, qtd_cavalos, qtd_vacas, qtd_galinha, cavalo_restantes, vaca_restantes, galinha_restantes;

    cin >> carga >> qtd_cavalos >> qtd_vacas >> qtd_galinha;

    if(carga > (qtd_galinha*2)){

        galinha_restantes = 0;
        carga = carga - qtd_galinha*2;

        if(carga > (qtd_vacas*150)){

            carga = carga - qtd_vacas*150;
            vaca_restantes = 0;

            if(carga > (qtd_cavalos*250)){
                cavalo_restantes = 0;
            } else{
                cavalo_restantes = qtd_cavalos - (carga/250);
            }

        } else{
            vaca_restantes = vaca_restantes - (carga/150);
            cavalo_restantes = qtd_cavalos;
        }
    
    } else{
        galinha_restantes = qtd_galinha - (carga/2);
        cavalo_restantes = qtd_cavalos;
        vaca_restantes = qtd_vacas;
    }

    cout << cavalo_restantes << endl;
    cout << vaca_restantes << endl;
    cout << galinha_restantes;

    return 0;
}