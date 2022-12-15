#include <iostream>

using namespace std;

int main() 
{
    int matricula, matriculamaior, matriculamenor;
    float maior = -1, nota, segundomaior = -1;

    cin >> matricula;
    matriculamaior = matricula;
    matriculamenor = matricula;
    while(matricula != 0){
        
        cin >> nota;

        if(nota>maior){
            matriculamenor = matriculamaior;
            matriculamaior = matricula;
            segundomaior = maior;
            maior = nota;
            
        }else if(nota>segundomaior){
                segundomaior = nota;
                matriculamenor = matricula;
        }
        cin >> matricula;
    }
    cout << matriculamaior << " " << maior << endl;
    cout << matriculamenor << " " << segundomaior << endl;
    return 0;
}