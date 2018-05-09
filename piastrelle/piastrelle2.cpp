#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;


int main(){
	
	//apro il file input
	ifstream in;
	in.open("input.txt");
	
	int lung;
	
	//salvo in lung la lunghezza del corridoio
	in>>lung;
	
	//chiudo il file
	in.close();
	
	ofstream f("output.txt"); //se il file non esiste lo crea, altrimenti lo sovrascrive!
	
	
	//la prima riga di postrelle lunghe 1 la stampo a parte
	for(int i=0; i<lung; i++)
		f<<"[O]";
	f<<endl;
	
	
	
	//stampo le combinazioni di piastrelle con 1 o più piastrelle doppie
	
	//indica il numero di piastrelle doppie che sto usando
	int coperturadoppia;
	
	//rep mi indica quante volte ripetere una riga con una data copertura doppia
	int rep=lung-1;
	
	//riempio con piastrelle doppie fino a che non rimango con al più 1 piastrella vuota
	for(coperturadoppia = 1; lung-coperturadoppia*2>0; coperturadoppia++){
		
				
		int primaparte=lung-coperturadoppia*2;
		int secondaparte=0;
		for(int t=0; t<rep; t++){
			
			for(int i=0; i<primaparte; i++)
				f<<"[O]";
			primaparte--;
			for(int j=0; j<coperturadoppia; j++)
				f<<"[OOOO]";
			for(int z=0; z<secondaparte; z++)
				f<<"[O]";
			secondaparte++;
			f<<endl;
		}
		rep-=2;
	}
	
	
	
	
	//se la lunghezza è pari aggiungo una riga di sole piastrelle doppie
	if(lung%2==0)
		for(int i=0; i<lung; i+=2)
			f<<"[OOOO]";

			
	f.close();
	
	return 0;

}
