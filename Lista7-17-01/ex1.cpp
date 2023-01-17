#include <iostream>

using namespace std;

void imprime(float *v, int tamanho){
    for (int i = 0; i < tamanho; i++)
        cout << *(v+i) << " " << endl;
    
}

int main(){
    int N;
    cin >> N;
    float *vetor_entrada = new float[N];
    float *vetor_saida = new float[N-2];

    for (int i = 0; i < N; i++)
        cin >> vetor_entrada[i];

    float maior = vetor_entrada[0], segundo_maior = vetor_entrada[0], menor = vetor_entrada[0];
    float segundo_menor = vetor_entrada[0] ;
    int posicao_maior = 0, posicao_segundo_maior = 0, posicao_menor = 0, posicao_segundo_menor = 0;;

    
    
    for (int i = 0; i < N; i++){
        if(vetor_entrada[i] > maior){
            segundo_maior = maior;
            posicao_segundo_maior = posicao_maior;

            posicao_maior = i;
            maior = vetor_entrada[i];
        }
        else if(vetor_entrada[i] > segundo_maior){
            segundo_maior = vetor_entrada[i];
            posicao_segundo_maior = i;
        }

        if(vetor_entrada[i] < menor){
            segundo_menor = menor;
            posicao_segundo_menor = posicao_menor;

            posicao_menor = i;
            menor = vetor_entrada[i];
        }
        else if(vetor_entrada[i] < segundo_menor){
            segundo_menor = vetor_entrada[i];
            posicao_segundo_menor = i;
        }
        
    }
    
    int j = 0;
    for (int i = 0; i < N; i++){
        if(i != posicao_segundo_maior && i != posicao_segundo_menor){
            vetor_saida[j] = vetor_entrada[i];
            j++;
        }
    }
    
    imprime(vetor_saida,N-2);

    return 0;
}