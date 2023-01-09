#include <iostream>

using namespace std;

int main(){
    int vendas[10], numero_vendas = 0;
    string vendedores[10], melhor_vendedor;
    float comissao[10], valor_recebido[10], maior_valor = 0;
    

    for (int i = 0; i < 10; i++)
        cin >> vendedores[i] >> vendas[i] >> comissao[i];
    
    for (int i = 0; i < 10; i++){
        valor_recebido[i] = comissao[i]*vendas[i];
        numero_vendas += vendas[i];
        if(valor_recebido[i] > maior_valor){
            maior_valor = valor_recebido[i];
            melhor_vendedor = vendedores[i];
        } 
    }
    for (int i = 0; i < 10; i++)
        cout << vendedores[i] << " " << valor_recebido[i] << endl;

    cout << endl << numero_vendas << endl;
    cout << melhor_vendedor << " " << maior_valor;
    

    return 0;
}