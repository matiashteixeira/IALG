#include <iostream>

using namespace std;

int main(){
    int N, quantidade_alunos = 0;
    cin >> N;
    int *matricula = new int[N];

    for (int i = 0; i < N; i++)
        cin >> matricula[i];
    
    for (int i = 0; i < N; i++){
        for (int j = (i+1); j < N; j++){
            if(matricula[i] == matricula[j])
                matricula[j] = -1;
        }
    }
        
    for (int i = 0; i < N; i++){
        if(matricula[i] != -1){
            quantidade_alunos++;
        }
    }
    
    cout << quantidade_alunos;

    return 0;
}