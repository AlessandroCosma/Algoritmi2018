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
	
	//apro il file output
	ofstream f("output.txt"); //se il file non esiste lo crea, altrimenti lo sovrascrive!
	
	
	//la prima riga di postrelle lunghe 1 la stampo a parte
	for(int i=0; i<lung; i++)
		f<<"[O]";
	f<<endl;
	
		
	//indica quanto spazio ho a sinistra del corridoio
	int spaziosinistra=lung-2;
	
		
	
	//stampo le combinazioni di piastrelle con 1 o più piastrelle doppie che iniziano per una SINGOLAs
	while(spaziosinistra>=1){
	
		int quantedoppie=(lung-spaziosinistra)/2;
		int rep=1;
		
		/* in base al numero di piastrelle doppie che posso mettere
		   dopo le piastrelle singole a sinistra, andrò a iterare in
		   modo da disporre tali piastrelle in ordine		
		*/
		for(int j=0; j<quantedoppie; j++){
			
			//stampo le singole
			for(int i=0; i<spaziosinistra; i++){
				f<<"[O]";
			}
			
			//stampo le doppie
			for(int i=0; i<rep; i++){
				f<<"[OOOO]";
			}
			
			//stampo le rimanenti singole
			for(int i=0; i<(lung-spaziosinistra-(rep*2)); i++){
				f<<"[O]";
			}
				
			//vado a capo riga
			f<<endl;
			
			rep++;
		}
		spaziosinistra--;
	}
	
	
	//stampo le combinazioni di piastrelle con 1 o più piastrelle doppie che iniziano per una DOPPIA
	
	//indica quanto spazio ho a sinistra del corridoio
	int rep=lung/2;
	int h=1;
	while(rep>0){
		
		for(int i=0; i<h; i++){
			f<<"[OOOO]";
		}
		
		for(int j=0; j<(lung-(2*h)); j++){
			f<<"[O]";
		}
		
		f<<endl; 
		
		h++;
		rep--;
	}
			
	f.close();
	
	return 0;

}
