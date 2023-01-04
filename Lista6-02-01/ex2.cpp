#include <iostream>

using namespace std;

int main(){
    int N, cont = 1, quantidade_alunos = 0;
    cin >> N;
    int matricula[N];

    for(int i =0;i<N;i++) 
        cin >> matricula[i];
    
    while(cont <= N){
        if(matricula[cont] == matricula[cont-1]){
            quantidade_alunos = quantidade_alunos - 1;
        }
        quantidade_alunos++;
        cont++;
    }
    cout << quantidade_alunos;
    return 0;
}