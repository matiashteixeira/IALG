#include <iostream>


using namespace std;

int main() 
{
    string cor1, cor2;
    unsigned int numero, dig1, dig2, dig5, dig6;

    cin >>  cor1 >> cor2 >> numero;

    dig1 = numero/100000;
    dig2 = (numero%100000)/10000;
    dig5 = ((((numero%100000)%10000)%1000)%100)/10;
    dig6 = ((((numero%100000)%10000)%1000)%100)%10;

    if(dig1 == dig6 && dig2 == dig5){
        cout << cor1;
    } else{
        cout << cor2;
    }
    
    return 0;
}