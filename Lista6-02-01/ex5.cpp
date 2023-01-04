#include <iostream>

using namespace std;

int main(){
    int N, cont = 0;
    bool palindromo = 1;
    cin >> N;
    int valores[N];
    

    for (int i = 0; i < N; i++)
        cin >> valores[i];
    
    while (cont < (N-cont)){
        if(valores[cont] != valores[N-cont-1]){
            cont = N;
            palindromo = 0;
        }
        cont++;
    }
    
    cout << palindromo;

    return 0;
}