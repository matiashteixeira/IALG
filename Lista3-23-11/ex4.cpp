#include <iostream>
#include <cmath>


using namespace std;

int main() 
{
    unsigned int h;
    float x, y, valor;
    cin >> h >> x >> y;

    if (h>360){
        h = h%360;
        if (h<90){
            valor = x+y;
        } else if (h<180){
            valor = x*y;
        } else if (h<270){
            valor = x/y;
        } else {
            valor = pow(x,y);
        }
    } else{
       if (h<90){
            valor = x+y;
        } else if (h<180){
            valor = x*y;
        } else if (h<270){
            valor = x/y;
        } else {
            valor = pow(x,y);
        } 
    }
    cout << valor; 

    return 0;
}