#include <iostream>
#include <cstring>

using namespace std;

void imprime(int *v, int tamanho){
    for (int i = 0; i < tamanho; i++)
        cout << *(v+i) << " " << endl;
    
}

int main(){
    int N = 2;
    
    int *vetor = new int[N];

    for (int i = 0; i < N; i++)
        cin >> vetor[i];


int *v = new int [N+2];
    memcpy(v,vetor,sizeof(int)*N);
    delete [] vetor;
    
    imprime(v,N+2);

    return 0;
}