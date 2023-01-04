#include <iostream>
#include <cstring> 

using namespace std;

int main(){
    int vogal = 0;
    char palavra[256];

    cin >> palavra;
    
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
            vogal++;
    }
    cout << vogal;

    return 0;
}