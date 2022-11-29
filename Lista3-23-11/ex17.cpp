#include <iostream>


using namespace std;

int main() 
{
    bool genero;
    int idade;
    float tempo, aposentadoria;

    cin >> genero >> idade >> tempo;

    if (genero){ //se for homem
        if(tempo > 20){
            aposentadoria = (35-tempo)*1.3;
            cout << aposentadoria + idade;
        }else{
            cout << "65";
        }
    }
    
    if (!genero){ //se for mulher
        if(tempo > 15){
            aposentadoria = (30-tempo)*1.3;
            cout << aposentadoria + idade;
        }else{
            cout << "62";
        }
    }
    return 0;
}