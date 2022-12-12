#include <iostream>

using namespace std;

float metro(float dist)
{
	float convertida;
	convertida = dist/100;
	
	return convertida;
}

float centimetro(float dist){
	
	float convertida;
	convertida = dist*100;
	
	return convertida;
}

int main(){
	
	float dist;
	string unidade;
	cin >> dist >> unidade;
	
	if(unidade == "centimetro"){
		cout << centimetro(dist) << " cm";
	}
	else if(unidade == "metro"){
		cout << metro(dist) << " m";
	} else{
		cout << "ERRO";
	}
	
	
	
    

    return 0;
}

