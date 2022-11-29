#include <iostream>


using namespace std;

int main() 
{
    int numerador, denominador;
    cin >> numerador >> denominador;
    if (denominador != 0){
        cout << numerador/denominador << endl;
        cout << numerador%denominador << endl;
    } else{
        cout << "erro" << endl;
    }
    return 0;
}