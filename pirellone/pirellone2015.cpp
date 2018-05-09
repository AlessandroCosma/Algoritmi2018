#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;


int main(){
	
	//apro il file input
	ifstream in;
	in.open("input.txt");
	
	int M,N;
	
	in>>M>>N;
	
	char matrix[M][N];
	char resM[M];
	char resN[N];
	bool fattibile=true;
	
	memset(resM, '0', sizeof(resM[0])*M);
	memset(resN, '0', sizeof(resN[0])*N);
	
	//salvo i valori di input in matrix
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			in >> matrix[i][j];
		}
	}
	//chiudo il file 
	in.close();
	
	//scorro la prima riga i=0, j = 0->N
	for(int j=0 ; j<N ; j++) {
		//se trovo un elemento della riga che vale 1, inverto tutta la colonna sottostante
		if( matrix[0][j]=='1'){
			//salvo nella posizione j-esima di resN valore 1
			resN[j]='1';
			
			for(int i=0; i<M; i++)
		   	 {
				if (matrix[i][j]=='0')
					matrix[i][j]='1';
				else
					matrix[i][j]='0';
		    	}
		    	
		}
	}
	
	//scorro la prima colonna
	for(int i=0; i<M; i++){
		//se la colonna ha un elemento a 1 allora inverto la riga
		/* OSS: perchè sia fattibile devo avere tutti 1 nella riga. se ho 0 allora termino con 
				tanti zeri come da consegna */
		if(matrix[i][0]=='1'){
			//salvo nella posizione i-esima di resN valore 1
			resM[i]='1';
			//l'inversione non la faccio realmente perchè nel risultato finale non serve modificare la matrice
			for(int j=0; j<N; j++){
				if(matrix[i][j]=='0'){
					//ho trovato uno zero che mi indica che il pirellone non è spegnibile
					fattibile=false;
					break;
				}
				/*else
					matrix[i][j]=0;
				*/
			}
		}
		if(!fattibile)
			//se trovo che c'era uno zero nelle righe di soli uni allora esco dal tutto dal ciclo
			break;
	}
	
	//scrivo su file output
	
	ofstream f("output.txt"); //se il file non esiste lo crea, altrimenti lo sovrascrive!
	if(!f) {
		cout<<"Errore nella creazione del file!";
	return -1;
	}

	
	
	if(fattibile){
		for(int i=0 ; i<M ; i++)
			f << resM[i] << ' ';
		f << endl;
		for(int j=0 ; j<N ; j++)
			f << resN[j] << ' ';
		
	}
	
	else{
		for(int i=0 ; i<M ; i++)
			f << '0' << ' ';
		f << endl;
		for(int j=0 ; j<N ; j++)
			f << '0' << ' ';
	}

	f.close(); //chiudo il file
	
	
		    
	
	
	/*
	for(int i=0 ; i<M ; i++) {
		for(int j=0 ; j<N ; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	return 0;
}
