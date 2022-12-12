#include <iostream>
#include <iomanip>

using namespace std;

float milhas(float dist){
    float milha;
    milha = dist/1.852;

    return milha; 
}

float calculo(float dist, float velocidade, float tempo){
    float vai_percorrer;
    vai_percorrer = velocidade*tempo + dist;
    vai_percorrer = vai_percorrer/1.852;
    return vai_percorrer;
}

int main(){
	float distancia, velocidade, tempo;

    while(distancia != -1){
        cin >> distancia >> velocidade >> tempo; 

        cout << fixed << setprecision(2);
        cout << milhas(distancia) << " ";
        cout << calculo(distancia,velocidade,tempo);
    }
	return 0;
}
