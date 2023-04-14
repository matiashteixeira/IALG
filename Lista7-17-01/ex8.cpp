#include <iostream>
#include <cstring>
using namespace std;

char* redimensiona_vetor(char *vet, int& tam){
    char *aux = new char[tam];
    int j = 0;
    for (int i = 0; i < tam; i++){
        if(vet[i] != -1){
            aux[j] = vet[i];
            j++;    
        }
    }
    tam--;
    delete[] vet;
    vet = aux;

    return vet;
}

int main(){
    string numero;
    cin >> numero;
    int tam, digitos,aux;
    cin >> digitos;
    tam = numero.length();
    aux = tam;

    char *num = new char[tam];
    
    for (int i = 0; i < tam; i++)
        num[i] = numero[i];
    
    char menor = num[0], maior = num[0];
    int posicao_menor = 0, posicao_maior = 0, pos = 0, cont;

    while(digitos > 0){
        for (int i = pos; i < aux; i++){
            if(num[i] >= maior){
                maior = num[i];
                posicao_maior = i+1;
            }
        }
        pos = posicao_maior;
        cout << pos << endl;
        cont = posicao_maior;
        while(digitos > 0 && cont > 0){
            menor = num[0], posicao_menor = 0;
            for (int i = 0; i < posicao_maior; i++){
                if(num[i] <= menor){
                    menor = num[i];
                    posicao_menor = i;
                }
            }
            num[posicao_menor] = -1;
            num = redimensiona_vetor(num,aux);
            digitos--;
            cont--;
        }
    }

    for (int i = 0; i < aux; i++)
        cout << num[i];

    return 0;
}