#include <iostream>
using namespace std;

int logaritimo(int num){
    if(num == 1)
        return 0;
    else
        return 1+logaritimo(num/3);
}

int main(){
    int num;
    cin >> num;
    cout << logaritimo(num);
    return 0;
}