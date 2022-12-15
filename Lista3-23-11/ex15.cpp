#include <iostream>


using namespace std;

int main() 
{
    int dia, hora, minuto, duracao, diaf, horaf, minutof;
    cin >> dia >> hora >> minuto >> duracao;

        diaf = dia + duracao/1440;
        horaf = (duracao%1440)/60 + hora;
        minutof = (duracao%1440)%60 + minuto;
        
         if(minutof>=60){
            horaf = horaf + minutof/60;
            minutof = minutof%60;  
        }
        
        if(horaf>=24){
            diaf = diaf + horaf/24; 
            horaf = horaf%24;  
        }

       

    cout << diaf << " " << horaf << " " << minutof;
    
    return 0;
}