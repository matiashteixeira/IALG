#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    float v1, v2, distancia, tempo;
    cin >> v1 >> v2 >> distancia;
    tempo = distancia/(v1+v2);
    if (tempo <= 10){
        cout << "COLISAO";
    } else{
        cout << setprecision(4) << tempo;
    }

    return 0;
}