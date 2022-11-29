#include <iostream>


using namespace std;

int main() 
{
    double a, b;
    int x;
    cin >> a >> b >> x;

    if (x == 1){
        cout << (a+b)/2;

    } else if (x == 2){
        if (a<b){
            cout << b-a;
        }else{
            cout << a-b;
        }

    } else if (x == 3){
        cout << a*b;

    } else if (x == 4){
        if (b == 0) {
            cout << "ERRO";
        } else{
            cout << a/b;
        }
    } else {
        cout << "ERRO";
    }

    return 0;
}