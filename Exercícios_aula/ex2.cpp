#include <iostream>
using namespace std;

struct animal{
    int identificador;
    char nome_animal[50];
    char nome_dono[50];
    int dia, mes, ano;
};



int binariaRecursiva(animal* vetor, int inicio, int fim, int procurado) {     
    if (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (procurado > vetor[meio].identificador)
            return binariaRecursiva(vetor,meio+1,fim,procurado);
        else if (procurado < vetor[meio].identificador)
            return binariaRecursiva(vetor,inicio,meio-1,procurado);
        else
            return meio;
    }
    return -1;
}




int main(){
    animal* dados;
    dados = new animal[100];
    int i = 0, animal, acho;

    cin >> dados[i].identificador;

    while(dados[i].identificador != 0){
        cin >> dados[i].nome_animal >> dados[i].nome_dono;
        cin >> dados[i].dia >> dados[i].mes >> dados[i].ano;
        i++;
        cin >> dados[i].identificador;
    }

    cin >> animal;
    acho = binariaRecursiva(dados,0,i-1,animal);
    if(acho == -1){
        cout << "Inexistente";
    }else{
        cout << dados[acho].nome_animal << " " 
             << dados[acho].dia << "/" << dados[acho].mes << "/" << dados[acho].ano;
    }

    
    
    
    

    

    return 0;
}