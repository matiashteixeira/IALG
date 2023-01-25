#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int N, cont = 0;
    cin >> N;
    char *vetor = new char [N];

    for (int i = 0; i < N; i++)
        cin >> vetor[i];
    
    int j = N-1;

    for (int i = 0; i < j; i++){
        if(vetor[i] != vetor[j]){
            cont++;
        }
        if(cont == 0)
            cout << i << " " << vetor[i] << " " << j << " " << vetor[j] << " ";
        j--;
    }


    cout << endl;

    if(cont > 0){
        cout << "nao";
    }else{
        cout << "sim";
    }
    return 0;
}