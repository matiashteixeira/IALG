#include <iostream>
using namespace std;

int ricci(int num1, int num2, int qtd){
    if(qtd == 1)
        return num2;
    else if(qtd == 0)
        return num1;
    else
        return ricci (num1,num2, qtd-1) + ricci(num1,num2,qtd-2);
        
}


int main(){
    int num1, num2, qtd, cont = 0;
    cin >> num1 >> num2 >> qtd;

    while(cont < qtd){
        cout << ricci(num1, num2, cont) << " ";
        cont++;
    }

    return 0;
}