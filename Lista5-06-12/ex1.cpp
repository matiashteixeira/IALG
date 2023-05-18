#include <iostream>

using namespace std;



float Media(float num1, float num2){
	float media = (num1 + num2)/2;
	return media;
}
	
int main(){
	float num1,num2;
	cin >> num1 >> num2;
	cout << Media(num1,num2);
	return 0;
}

asd