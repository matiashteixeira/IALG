#include <iostream>


using namespace std;

int main() 
{
    int produto, pais;
    float peso, bruto, imposto;
    cin >> produto >> peso >> pais;

    cout << peso*1000 << endl;  //peso em gramas
    
    if (produto <=4){
        bruto = peso*1000*10;
        cout << bruto << endl;
    } 

    else if (produto<=7){
        bruto = peso*1000*25;
        cout << bruto << endl;
    }
    
    else if (produto<=10){
        bruto = peso*1000*35;
        cout << bruto << endl;
    }

    if (pais == 1){
        imposto = 0;
        cout << 0 << endl;
    }

    else if(pais == 2){
        imposto = bruto*0.15;
        cout << imposto << endl;
    } else{
        imposto = bruto*0.25;
        cout << imposto << endl;
    }
    cout << bruto+imposto;

    return 0;
}