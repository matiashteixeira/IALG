#include <iostream>
#include <fstream>


using namespace std;

int main(){
    int i, cont = 1, cont2 = 0, repeticao = 1;
    ofstream arquivo("jogo.txt");
    cin >> i;
    
    while(i>cont2){

        while(i>=cont){
            if(repeticao%2 == 0){
            arquivo << '#';
            } else{
            arquivo << '.';
            }
            cont++;
            repeticao++;
        }
        arquivo << endl;
        
        
        if (cont2%2 == 0)
        {
            repeticao = 2;
            cont = 1;
        }else{
            repeticao = 1;
            cont = 1;
        }
        cont2++;
    }
    return 0;
}