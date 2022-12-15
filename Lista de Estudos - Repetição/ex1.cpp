#include <iostream>

using namespace std;

int main(){
    int divisor, dividendo, cont = 0;
    cin >> dividendo >> divisor;

    if(dividendo > divisor){
        while(cont*divisor != dividendo){
            cont++;
        }
    }else{
        cont = 0;
    }
    cout << cont;

    return 0;
}