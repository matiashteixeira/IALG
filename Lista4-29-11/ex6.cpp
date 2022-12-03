#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int num;
    ifstream entrada("numeros");
    ofstream pares("pares");
    ofstream impar("impares");

    while(entrada >> num){
        if(num%2 == 0){
            pares << num << " ";
        } else{
            impar << num << " ";
        }
    }

  return 0;
}