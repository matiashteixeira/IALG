#include <iostream>
using namespace std;

void imprime(int tamanho, int* vetor){
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
}

int main(){
    int N, divisor_3 = 0, divisor_2 = 0, divisor_comum = 0;
    cin >> N;

    int* numeros = new int[N];

    for (int i = 0; i < N; i++){
        cin >> numeros[i];
    }
    
    for (int i = 0; i < N; i++){
        if(numeros[i]%2 == 0){
            if(numeros[i]%3 == 0){
                divisor_comum++;
                divisor_3++;
            }
            divisor_2++;
        }
        else if(numeros[i]%3 == 0){
            divisor_3++;
        }
    }

    int* divisor3 = new int[divisor_3];
    int* divisor2 = new int[divisor_2];
    int* DivisorComum = new int[divisor_comum];
    int j2 = 0, j3 = 0, j_com = 0;
    
    
    for (int i = 0; i < N; i++){
        if(numeros[i]%2 == 0){
            if(numeros[i]%3 == 0){
                DivisorComum[j_com] = numeros[i];
                j_com++;
                divisor3[j3] = numeros[i];
                j3++;
            }
            divisor2[j2] = numeros[i];
            j2++;
        }
        else if(numeros[i]%3 == 0){
            divisor3[j3] = numeros[i];
            j3++;
        }
    }
    
    if(divisor_2 == 0){
        cout << "0";
        cout << endl;
    }else{
        imprime(divisor_2,divisor2);
        cout << endl;
    }
    
    if(divisor_3 == 0){
        cout << "0";
        cout << endl;
    }else{
        imprime(divisor_3,divisor3);
        cout << endl;
    }
    
    if(divisor_comum == 0){
        cout << "0";
    }else{
        imprime(divisor_comum,DivisorComum);
    }
    
    delete[] divisor2,divisor3,DivisorComum,numeros;
       
    return 0;
}