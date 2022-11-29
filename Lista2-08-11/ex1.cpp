#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    string nome, palavra;
    cin >> nome;
    ifstream arquivo(nome);
    arquivo >> palavra;
    cout << palavra;
    return 0;
}