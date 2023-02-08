#include <iostream>
#include <string>
using namespace std;

struct carro{
    string placa;
    string cor;
    int ano;
    string marca;
    string donos[2];
    int CPF[2];
};

void preenche_registro(int tamanho,carro *meu_carro);
void imprime(int tamanho, carro *meu_carro);
int encontrar(string marca, carro *meu_carro, int tamanho);
void imprime_encontrado(carro *meu_carro, int posicao);

int main(){
    int N, posicao;
    cin >> N;
    carro *meu_carro = new carro[N];
    string marca;

    preenche_registro(N,meu_carro);
    imprime(N, meu_carro);
    
    cout << "Digite a marca que deseja encontrar: ";
    cin >> marca;
    cout << endl;
    posicao = encontrar(marca,meu_carro, N);
    imprime_encontrado(meu_carro,posicao);

    delete[] meu_carro;

    return 0;
}

void preenche_registro(int tamanho,carro *meu_carro){
    for (int i = 0; i < tamanho; i++){
        cout << "Digite o número da placa: ";
        cin >> meu_carro->placa; 
        cout << endl;
        cout << "Digite a cor do carro: ";
        cin >> meu_carro->cor; 
        cout << endl;
        cout << "Digite o ano do carro: ";
        cin >> meu_carro->ano; 
        cout << endl;
        cout << "Digite a marca do carro: ";
        cin.ignore();
        getline(cin,meu_carro->marca);
        cout << endl;
        for (int i = 0; i < 2; i++){
            cout << "Digite o dono do carro: ";
            cin.ignore();
            getline(cin,meu_carro->donos[i]);
            cout << endl;
            cout << "Digite o CPF do dono: ";
            cin >> meu_carro->CPF[i]; 
            cout << endl;
        }
    } 
}

void imprime(int tamanho, carro *meu_carro){
    for (int i = 0; i < tamanho; i++){
        cout << meu_carro->placa << ", ";
        cout << meu_carro->cor << " ";
        cout << meu_carro->ano << " ";
        cout << meu_carro->marca << " ";
        for (int i = 0; i < 2; i++){
            cout << meu_carro->donos[i] << " ";
            cout << meu_carro->CPF[i] << " "; 
        }
    }
}

int encontrar(string marca, carro *meu_carro, int tamanho){
    int posicao;
    for (int i = 0; i < tamanho; i++){
        if(meu_carro[i].marca == marca){
            posicao = i;
        }
    }
    return posicao;
}

void imprime_encontrado(carro *meu_carro, int posicao){
    cout << meu_carro[posicao].placa << " ";
    for (int i = 0; i < 2; i++){
        cout << meu_carro[posicao].donos[i] << " "
            << meu_carro[posicao].CPF << " " << endl;
    }
}