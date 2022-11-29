#include <iostream>


using namespace std;

int main() 
{
    char monstro;
    int pessoas, dias, centena, dezena, unidade;

    cin >> monstro >> pessoas >> dias;

    if (monstro == 'z' || monstro == 'm'){
        centena = 1;
    } 
    else if (monstro == 'l' || monstro == 'd'){
        centena = 2;
    } 
    else if (monstro == 'h' || monstro == 's'){
        centena = 3;
    }
    else if (monstro == 'v' || monstro == 'f'){
        centena = 4;
    }



    if (pessoas >= 3){
        dezena = 3;
    } else {
        dezena = pessoas;
    }
    

    if(dias <=2){
        unidade = 1;
    } 
    else if(dias <=4){
        unidade = 2;
    }
    else if(dias <=6){
        unidade = 3;
    } else{
        unidade = 4;
    }
    
    cout << centena << dezena << unidade;

    return 0;
}