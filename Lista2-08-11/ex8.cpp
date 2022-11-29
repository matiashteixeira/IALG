#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    float custo, preco;
    int convites;
    ifstream arquivo1 ("teatro.txt");
    ofstream arquivo2 ("convite.txt");
    arquivo1 >> custo >> preco;
    convites = ceil(custo/preco);
    arquivo2 << convites;
    cout << convites;
    return 0;
}