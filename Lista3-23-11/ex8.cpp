#include <iostream>


using namespace std;

int main() 
{
    int idade;

    cin >> idade;

    if (idade >=5){
    
        if(idade <=7){
            cout << "Infantil";
        } 

        else if(idade <= 10){
            cout << "Juvenil";
        }

        else if(idade <= 15){
            cout << "Adolescente";
        }

        else if(idade <= 30){
            cout << "Adulto";
        }

        else if(idade > 30){
            cout << "Senior";
        } 
    } else {
        cout << "Nao registrado";
    }
    return 0;
}