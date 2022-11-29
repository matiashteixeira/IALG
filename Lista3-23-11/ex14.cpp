#include <iostream>
#include <cmath>


using namespace std;

int main() 
{
    char funcao, unidade;
    float angulo;

    cin >> funcao >> unidade >> angulo;

    if(funcao == 's'){

        if (unidade == 'g'){
            angulo = angulo*M_PI/180;
            cout << sin(angulo);
        } 

        else if (unidade == 'r'){
            cout << sin(angulo);
        }

    } else if(funcao == 'c'){
        
        if (unidade == 'g'){
            angulo = angulo*M_PI/180;
            cout << cos(angulo);
        } 

        else if (unidade == 'r'){
            cout << cos(angulo);
        }
    }
    return 0;
}