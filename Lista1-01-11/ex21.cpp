#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    float l1, l2, area, pot;
    const int parametro = 18;
    cin >> l1 >> l2;
    area = l1*l2;
    pot = area * parametro;
    cout << fixed << setprecision(1);
    cout << area << "m2" << endl;
    cout << pot << "W";

    return 0;
}
