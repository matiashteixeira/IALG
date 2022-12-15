#include <iostream>


using namespace std;

int main() 
{
    double peso, altura;
     cin >> peso >> altura;
    
    if (altura < 1.2){
        if(peso < 60){
        cout << 'A';
        } else if(peso <= 90){
            cout << 'D';
        } else{
            cout << 'G';
        }
    }

    else if (altura <= 1.7){
        if(peso < 60){
        cout << 'B';
        } else if(peso <= 90){
            cout << 'E';
        } else{
            cout << 'H';
        }
    } else {
        if(peso < 60){
        cout << 'C';
        } else if(peso <= 90){
            cout << 'F';
        } else{
            cout << 'I';
        }
    }
    
    return 0;
}