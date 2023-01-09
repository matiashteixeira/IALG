#include <iostream>

using namespace std;

int main(){
    int N, quantidade_alunos = 0;
    cin >> N;
    int matricula[N];
    bool aluno = false;

    for(int i =0;i<N;i++) 
        cin >> matricula[i];
    
    for (int i = 0; i < (N-1); i++){
        int j;
        j= i+1;
        aluno = false;
        while(j < N && !aluno){
            if(matricula[i] != matricula[j])
                quantidade_alunos++;
                aluno = true;
        }
    }

    cout << quantidade_alunos;
    return 0;
}