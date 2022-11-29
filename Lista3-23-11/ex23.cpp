#include <iostream>

using namespace std;

int main() {

    float maior, menor, n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    if(n1>n2 && n1>n3 && n1>n4){
        maior = n1;

        if(n2>n3 && n2>n4){
            menor = n2;
        } else if(n3>n4){
            menor = n3;
        } else{
            menor = n4;
        }
    } 

    else if(n2>n3 && n2>n4 && n2>n1){
        maior = n2;

        if(n1>n3 && n1>n4){
            menor = n1;
        } else if(n3>n4){
            menor = n3;
        } else{
            menor = n4;
        }

    } 

    else if(n3>n1 && n3>n2 && n3>n4){
        maior = n3;

        if(n1>n2 && n1>n4){
            menor = n1;
        } else if(n2>n4){
            menor = n2;
        } else{
            menor = n4;
        }
    }

    else{
        maior = n4;

        if(n1>n3 && n1>n2){
            menor = n1;
        } else if(n3>n2){
            menor = n3;
        } else{
            menor = n2;
        }
    }

    cout << maior << endl;
    cout << menor << endl;

    return 0;
}
    
    