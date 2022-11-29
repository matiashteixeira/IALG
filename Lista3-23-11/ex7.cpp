#include <iostream>


using namespace std;

int main() 
{
    int idade;
    float peso;
     cin >> idade >> peso;
    
    if (idade<20){
        if(peso<60){
        cout << "9";
        } else if(peso<90){
            cout << "8";
        } else{
            cout << "7";
        }
    }

    else if (idade<=50){
        if(peso<60){
        cout << "6";
        } else if(peso<90){
            cout << "5";
        } else{
            cout << "4";
        }
    } else {
        if(peso<60){
        cout << "3";
        } else if(peso<90){
            cout << "2";
        } else{
            cout << "1";
        }
    }
    
    return 0;
}