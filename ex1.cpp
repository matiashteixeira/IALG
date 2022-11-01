#include <iostream>
using namespace std;

int main() 
{
    int numero, dig1, dig2, dig3, dig4;
    cin >> numero;
    dig1 = numero/1000;
    dig2 = (numero%1000)/100;
    dig3 = ((numero%1000)%100)/10;
    dig4 = ((numero%1000)%100)%10;
    cout << dig1+dig4 << endl; 
    cout << dig2+dig3; 
    return 0;
}