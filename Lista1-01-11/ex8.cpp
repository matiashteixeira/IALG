#include <iostream>
using namespace std;

int main() 
{
    float dmenor, dmaior, area;
    cin >> dmaior >> dmenor;
    area = dmenor*dmaior/2;
    cout << "A area do losango de lado maior " << dmaior << " e lado menor " << dmenor;
    cout << " e " << area << " metros quadrados.";
    return 0;
}

