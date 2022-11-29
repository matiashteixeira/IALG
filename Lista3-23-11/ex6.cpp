#include <iostream>


using namespace std;

int main() 
{
    float nota1, nota2, nota3, ponderada;
    cin >> nota1 >> nota2 >> nota3;
    ponderada = (nota1*2+nota2*3+nota3*5)/10;
    cout << ponderada << endl;
    if (ponderada < 5){
        cout << "E";
    } else if (ponderada <6){
        cout << "D";
    } else if (ponderada <7){
        cout << "C";
    } else if (ponderada <8){
        cout << "B";
    } else{
        cout << "A";
    }
    return 0;
}