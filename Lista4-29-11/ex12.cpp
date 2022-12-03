#include <iostream>
#include <fstream>


using namespace std;

int main() {
    
    int qtd, produzidos, vendidos, estoque = 0, estoque_anterior, maior_estoque;
    string nome, nome_maior_estoque;
    ifstream entrada("estoque.txt");
    
    entrada >> qtd;

    while(qtd>0){
        qtd--;
        estoque_anterior = estoque;
        entrada >> nome >> produzidos >> vendidos;
        estoque = produzidos-vendidos;
        cout << nome << " " << estoque << " ";

        
        if(estoque < 50){
            cout << "BAIXO ESTOQUE" << endl;
        } else{
            cout << endl;
        }
        
        if(estoque > estoque_anterior){
            nome_maior_estoque = nome;
            maior_estoque = estoque;
        }
    }
    cout << nome_maior_estoque << " " << maior_estoque;

    return 0;
}