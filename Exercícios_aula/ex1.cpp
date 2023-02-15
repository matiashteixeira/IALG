#include <iostream>
using namespace std;

int binariaRecursiva(int vetor[], int inicio, int fim, int procurado, int& cont) {     
    if (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (procurado > vetor[meio]){
            cont++;
            return binariaRecursiva(vetor,meio+1,fim,procurado, cont);
        }
        else if (procurado < vetor[meio]){
            cont++;
            return binariaRecursiva(vetor,inicio,meio-1,procurado, cont);
        }
        else
            return meio;
    }
    return -1;
}



int main(){
    int vetor[10] = {1, 5, 20, 45, 46, 47, 50, 78, 99, 102};
    int cont = 0;
    cout << binariaRecursiva(vetor,0,9,99,cont) << endl;
    cout << cont;

    



    return 0;
}