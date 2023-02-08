#include <iostream>
using namespace std;

struct ponto{
    int x, y;
};


struct retangulo{
    ponto v1, v2;
};


int main(){
    int qtd, cont = 0;
    ponto p;
    cin >> p.x >> p.y;
    cin >> qtd;
    retangulo* ret = new retangulo[qtd];
    
    
    for (int i = 0; i < qtd; i++){
        cin >> ret[i].v1.x >> ret[i].v1.y
            >> ret[i].v2.x >> ret[i].v2.y;
    }

    for (int i = 0; i < qtd; i++){
        if(p.x <= ret[i].v2.x && p.x >= ret[i].v1.x){
            if(p.y <= ret[i].v2.y && p.y >= ret[i].v1.y){
                cont++;
            }
        }
    }
    cout << cont;
    delete[] ret;
    return 0;
}