#include <iostream>


using namespace std;

int main() 
{
    char notas;
    cin >> notas;

    switch(notas){

        case 'C':
            cout << "Do";
            break;
        
        case 'D':
            cout << "Re";
            break;

        case 'E':
            cout << "Mi";
            break;    

        case 'F':
            cout << "Fa";
            break;

        case 'G':
            cout << "Sol";
            break;

        case 'A':
            cout << "La";
            break;

        case 'B':
            cout << "Si";
            break;

    }
    return 0;
}