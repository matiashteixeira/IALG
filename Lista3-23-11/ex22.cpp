#include <iostream>


using namespace std;

int main() 
{
    int carga, dcavalos, dvacas, dgalinha, cavalo, vaca, galinha;

    cin >> carga >> dcavalos >> dvacas >> dgalinha;

    if(carga > (dgalinha*2)){
        galinha = 0;
        carga = carga - dgalinha*2;

        if(carga > (dvacas*150)){
            carga = carga - dvacas*150;
            vaca = 0;

            if(carga > (dcavalos*250)){
                
                cavalo = 0;
            } else{
                cavalo = dcavalos - carga/250;
            }

        } else{
            vaca = vaca - carga/150;
            cavalo = dcavalos;
        }
    
    } else{
        galinha = dgalinha - carga/2;
        cavalo = dcavalos;
        vaca = dvacas;
    }

    cout << cavalo << endl;
    cout << vaca << endl;
    cout << galinha << endl;

    return 0;
}