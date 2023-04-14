#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int* vet1 = new int[N];
    int* vet2 = new int[N];

    for (int i = 0; i < N; i++)
        cin >> vet1[i];
    
    for (int i = 0; i < N; i++)
        cin >> vet2[i];


    int aux, i = 0;
    bool igualdade = 1;
    while(i<N && igualdade){
        aux = 0;
        for (int k = 0; k < N; k++){
            if(vet1[i] != vet2[k]){
                aux++;
            }
        }
        i++;
        if(aux != N-1){
            igualdade = 0;
        }
    }
    
    if(igualdade){
        cout << "IGUAIS";
    }else{
        cout << "DIFERENTES";
    }

    return 0;
}