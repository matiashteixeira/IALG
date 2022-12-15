#include <iostream>

using namespace std;

int main(){
    char caracter;
    int cont = 0, cont_a = 0, cont_b = 0;
    
    while(cont < 10){
        cont++;
        cin >> caracter;

        if(caracter == 'a'){
            cont_a++;
        }else{
            cont_b++;
        }
    }

    if(cont_a >= cont_b){
        cout << "0";
    } else{
        cout << "1";
    }

    return 0;
}