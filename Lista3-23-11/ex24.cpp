#include <iostream>


using namespace std;

int main() 
{
    float multa, base;
    int velmax, vel;
    cin >> base >> velmax >> vel;

    if(vel > (velmax*1.3)){
        multa = base*1.5;
        cout << "R$ " << multa;
    } else{
        cout << "NAO SE APLICA";
    }
    
}