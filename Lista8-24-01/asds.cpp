#include <iostream>
#include <cmath>

using namespace std;

class N{
	private:
	int Max = 2;
	float *Armazena;
	int tamanho;
	
	public:
	N();
	~N();
	void Put(float Num);
	bool Cheio();
	void VetorMax();
	void Depurar();
	};

N::N(){
	tamanho = 0;
	Armazena = new float[Max];
		}
		
N::~N(){
	delete [] Armazena;
	}
	
bool N::Cheio(){
	return (tamanho == Max);
	}
	
void N::Put(float Num){
	if(Cheio()){
		VetorMax();
		}
	Armazena[tamanho] = Num;
	tamanho++;
	}

void N::VetorMax(){
	float *aux = new float[Max + 1];
	for(int a = 0; a < Max; a++){
		aux[a] = Armazena[a];
		}
		delete[] Armazena;
		Armazena = aux;
		Max += 1;
	}
	
void N::Depurar(){
    if(tamanho%2 == 0){
        int posicao = round(tamanho/2);
        cout << (Armazena[posicao] + Armazena[posicao-1])/2;
    }else{
        cout << Armazena[tamanho/2];
    }
}
	


int main(){
	N Entrar;
	float Num;
	do{
		
		cin >> Num;
		if(Num < 0){
			Entrar.Depurar();
		}
		Entrar.Put(Num);
		
		} while(Num > 0);
		
	return 0;
	}