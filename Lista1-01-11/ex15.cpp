#include <iostream>
using namespace std;

int main() 
{
    int saque, n50, n10, n5, n1;
    cin >> saque;
    n50 = saque/50;
    n10 = (saque - n50*50)/10;
    n5 = (saque - n50*50 - n10*10)/5;
    n1 = (saque - n50*50 - n10*10 - n5*5);
    cout << n50 << endl;
    cout << n10 << endl;
    cout << n5 << endl;
    cout << n1 << endl;
    return 0;
}
