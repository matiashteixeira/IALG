#include <iostream>

using namespace std;

int main(){
    int numeros[9], divisor;
    bool primo;



    for (int i = 0; i < 9; i++)
        cin >> numeros[i];
    
    for (int i = 0; i < 9; i++){
        divisor = 2;
        primo = 1;

        while(divisor < (numeros[i]) && primo == 1){
            if(numeros[i]%divisor == 0){
                primo = 0;
            } 
            divisor++;
        }
        if(primo)
            cout << numeros[i] << " " << i << endl;
        
    }
    return 0;
}