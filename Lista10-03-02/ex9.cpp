#include <iostream>
#include <cstring>
using namespace std;

struct atletas{
    int codigo, idade, peso;
    string nome;
    char sexo;
};

struct treinamento{
    int dia, tempo, codigo;
    float distancia;
};

void aumenta_vetor(int& tamanho, treinamento* vetor){
    treinamento* aux = new treinamento[tamanho];

    for(int i = 0; i < tamanho;i++)
        aux[i] = vetor[i];

    delete[]vetor;
    vetor = new treinamento[tamanho+1];

    for(int i = 0; i < tamanho;i++){
        vetor[i] = aux[i];
    }
    
    tamanho++;
    delete[] aux;
}

int main(){
    int qtd, tam = 1, j = 0, velho = 0, pos_velho = -1;
    cin >> qtd;
    atletas* atleta = new atletas[qtd];
    treinamento* treino = new treinamento[1];

    for (int i = 0; i < qtd; i++){
        cin >> atleta[i].codigo >> atleta[i].nome
            >> atleta[i].idade >>  atleta[i].peso >> atleta[i].sexo;
    }

    for (int i = 0; i < qtd; i++){
        if(atleta[i].idade > velho && atleta[i].sexo == 'M'){
            velho = atleta[i].idade;
            pos_velho = i;
        }
    }
    
    cin >> treino[j].dia;

    while(treino[j].dia != -1){
        cin >> treino[j].codigo >> treino[j].distancia >> treino[j].tempo;
        aumenta_vetor(tam,treino);
        j++;
        cin >> treino[j].dia;
    }   


    float soma = 0;

    for (int i = 0; i < tam; i++){
        if(atleta[pos_velho].codigo == treino[i].codigo){
            soma += treino[i].distancia;
        }
    }

    int qtd_treino[qtd+1], pos_esforcado, dias = 0;
    memset(&qtd_treino, 0, sizeof(qtd_treino));

    for (int i = 0; i < tam; i++){
        qtd_treino[treino[i].codigo-1]++; 
    }


    for (int i = 0; i < qtd; i++){
        if(qtd_treino[i] > dias){
            dias = qtd_treino[i];
            pos_esforcado = i;
        }
    }


    /*
    for (int i = 0; i < qtd; i++){
        int horas = 0;
        for (int j = 0; j < tam; j++){
            if(treino[j].codigo == 1){
                horas += treino[j].tempo;
                cout << "joao";
            }
        }
        float divisao;
        divisao = horas/qtd_treino[atleta[i].codigo-1];
        //cout << atleta[i].nome << " " << horas << endl;
    }
*/


    cout << atleta[pos_velho].nome << " " << soma << endl;
    cout << atleta[pos_esforcado].nome << " " << atleta[pos_esforcado].idade << endl; 
    
    delete[] treino;
    delete[] atleta;
    return 0;
}
