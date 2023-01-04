#include <iostream>

using namespace std;

int main(){

    int N, cont = 0, aux = 0, repeticao = 0, venda_maxima = 0, venda_minima, codigo_mais_vendido, codigo_menos_vendido;
    cin >> N;
    int vetor[N];

    for(int i=0;i<N;i++){
        cin >> vetor[i];
    }

    while(cont < N){
        while(aux < N){
            if(vetor[cont] == vetor[aux]){
                repeticao++;
            }
            aux++;
        }

        if(cont == 0){    //define os valores de venda máximo e mínimo no primeiro código de pronduto para depois usar como parâmetro
            venda_maxima = repeticao;
            venda_minima = repeticao;
        }

        if(repeticao >= venda_maxima){
            venda_maxima = repeticao;
            codigo_mais_vendido = vetor[cont];
        }
        else if(repeticao <= venda_minima){
            venda_minima = repeticao;
            codigo_menos_vendido = vetor[cont];
        }
        repeticao = 0;
        aux = 0;
        cont++;
    }

    cout << codigo_mais_vendido << endl << venda_maxima << endl;
    cout << codigo_menos_vendido << endl << venda_minima;

    return 0;
}