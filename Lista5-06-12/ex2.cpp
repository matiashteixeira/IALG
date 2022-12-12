#include <iostream>

using namespace std;

void geraSequencia(int n, int& total){
	cout << n << " ";
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		} else{
			n = 3*n + 1;
		}
		cout << n << " ";
	total++;
	}
}
		


int main()
{
	int valor, quantidade = 1;
	cin >> valor;
	geraSequencia(valor, quantidade);
	cout << endl << quantidade << endl;
    return 0;
}
