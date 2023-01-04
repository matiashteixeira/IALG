#include <iostream>

using namespace std;

int main(){
    string funcionarios[5];
    float salario[5];
    int anos[5];
    bool enunciado_sem_ajuste = 1;
    bool enunciado_com_ajuste = 1;

//-------------------------Entrada-de-Dados-----------------------------------------------------------------

    for (int i = 0; i < 5; i++)
        cin >> funcionarios[i];
     
    for (int i = 0; i < 5; i++)
        cin >> salario[i];

    for (int i = 0; i < 5; i++)
        cin >> anos[i];

//-----------------------------------------------------------------------------------------------------------

    for (int i = 0; i < 5; i++){

        if(anos[i] < 5 && salario[i] > 400){
            
            if(enunciado_sem_ajuste){
                enunciado_sem_ajuste = 0;
                cout << "SEM REAJUSTE:" << endl;
            }
            cout << funcionarios[i] << endl;
        }    
    }

    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        if(anos[i] >= 5 || salario[i] <= 400){
            
            if(enunciado_com_ajuste){
                enunciado_com_ajuste = 0;
                cout << "COM REAJUSTE:" << endl;
            }

            if(salario[i] <= 400){
                if(anos[i] >= 5){
                    salario[i] = salario[i]*1.35;
                }else{
                    salario[i] = salario[i]*1.15;
                }
            }
            else if(anos[i] >= 5){
                salario[i] = salario[i]*1.25;
            }
            cout << funcionarios[i] << " " << salario[i] << endl;
        }
    }
    return 0;
}