#include <iostream>


using namespace std;

int main() 
{
    int v1, v2, v3, v4, v5, v6, v7;
    float total, desconto, final;

    cin >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7;

    total = v1*28.9 + v2*19.9 + v3*7.95 + v4*2.99 + v5*1.5 + v6*1.85 + v7*8.7;
    cout << total << endl;

    if (total >= 200){
        desconto = 0.1*total;
        final = total-desconto;
    } else{
        desconto = 0.05*total;
        final = total-desconto;
    }
    
    cout << desconto << endl; 
    cout << final << endl; 

    return 0;
}