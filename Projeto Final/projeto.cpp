#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Método de Ordenação Bubble Sort
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(arr[j], arr[j+1]); 
} 

//Método para leitura do arquivo binário
void readFile(string filename){
   ifstream file;
   file.open(filename, ios::in | ios::binary);
   
   if(!file){
      cout << "Erro ao abrir o arquivo ";
   }
   else{
      int *buffer = new int[2];
      while(!file.eof()){
         file.read((char*)buffer, sizeof(int)*2);
         cout << buffer[0] << " " << buffer[1] << endl;
      }
   }
   file.close();
}

//Método para escrita no arquivo binário
void writeFile(string filename, int arr[], int n){
   ofstream file;
   file.open(filename, ios::out | ios::binary);
   
   if(!file){
      cout << "Erro ao abrir o arquivo ";
   }
   else{
	   for (int i = 0; i < n; i++) 
		  file.write((char*)&arr[i], sizeof(int)*2); 
   }
   file.close();
}

int main(){
   int arr[] = {50, 70, 80, 10, 40, 20, 60}; 
   int n = sizeof(arr)/sizeof(arr[0]); 
   
   //Ordena o vetor
   bubbleSort(arr, n);
   
   //Escreve o vetor no arquivo
   writeFile("arquivo.bin", arr, n);
   
   //Le o arquivo
   readFile("arquivo.bin");
   
   return 0;
}