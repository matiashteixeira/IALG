#include <iostream>


using namespace std;

int main() 
{
    char letra1, letra2;
    cin >> letra1 >> letra2;

    if(letra1 > letra2){
        cout << letra1;
    } else{
        cout << letra2;
    }
    return 0;
}