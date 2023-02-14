#include <iostream>
using namespace std;

int soma_recursiva(int n1,int n2){
    if(n2 == 1)
        return n1;
    if(n2 == 0 or n1 == 0)
        return 0;
    else
        return n1 + soma_recursiva(n1,n2-1);
}


int main(){
    int n1,n2;
    cin >> n1 >> n2;
    cout << soma_recursiva(n1,n2);
    return 0;
}