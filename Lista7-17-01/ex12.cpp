#include <iostream>
using namespace std;

void ordena_vetor(int* vet, int tam){
    
            
            
    }
    
}


int main(){
    int tam1, tam2;
    cin >> tam1 >> tam2;

    int* v1 = new int[tam1];
    int* v2 = new int[tam2];

    for (int i = 0; i < tam1; i++)
        cin >> v1[i];
    
    for (int i = 0; i < tam2; i++)
        cin >> v2[i];
    
    verifica_sequencia(v1,tam1,tam2,v2);






    return 0;
}