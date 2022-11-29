#include <iostream>


using namespace std;

int main() 
{
    int v1, v2, v3, x;
    cin >> v1 >> v2 >> v3 >> x;

    if(x <= v1){
        cout << x << " " << v1 << " " << v2 << " " << v3;
    } 

    else if(x <= v2){
        cout << v1 << " " << x << " " << v2 << " " << v3;
    }

    else if(x <= v3){
        cout << v1 << " " << v2 << " " << x << " " << v3;
    } else{
        cout << v1 << " " << v2 << " " << v3 << " " << x;

    }

    return 0;
}