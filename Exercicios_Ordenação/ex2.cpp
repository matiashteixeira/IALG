#include <iostream>
using namespace std;

int fatorial_duplo(int num){
    if(num == 1 or num == 0)
        return 1;
    else
        return num * fatorial_duplo(num-2);
}


int main(){
    int num;
    cin >> num;

    cout << fatorial_duplo(num);

    return 0;
}