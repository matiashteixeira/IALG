#include <iostream>

using namespace std;

int main(){
    int n1, n2, cont1 = 0, cont2 = 0;
    bool erro = 0;
    cin >> n1 >> n2;
    float vetor1[n1];
    float vetor2[n2];

    for (int i = 0; i < n1; i++)
        cin >> vetor1[i];

    for (int i = 0; i < n2; i++)
        cin >> vetor2[i];
    
    while(cont1 < n1){
        while(cont2 < n2){
            if(vetor2[cont2] == vetor1[cont1]){
                cout << vetor1[cont1] << " ";
                erro = 1;
            }
            cont2++;
        }      
    cont2 = 0;
    cont1++;
    }

    if(!erro){
        cout << "-1";
    }

    return 0;
}