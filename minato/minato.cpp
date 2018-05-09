#include <iostream>
#include <fstream>

using namespace std;



int main(){
	
	ifstream in;
	ofstream out;
	
	//apro il file
	in.open("input.txt", ios::in);
	
	int N;
	int M;
	
	//salvo i valori M e N
	in >> N;
	in >> M;
	
	
	//dichiaro una matrice di CHAR campo contenente caratteri + e *
	char campo[N][M];

	
	//dichiaro una matrice INT in cui salvo il numero di percorsi
	//eseguibili e sicuri per ogni cella 
	int percorsi[N][M];
	
	//inizializzo percorsi[][] a 0
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			percorsi[i][j]=0;
	
	//salvo la griglia
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			in >> campo[i][j];
		}
	}
	
	//chiudo il file di input
	in.close();
	
	//apro il file di output
	out.open("output.txt", ios::out);
	
	if(campo[N][M]=='+'){
		out<<0;
		out.close();
		return 0;
	}
	
	
	for(int i=N-1; i>=0; i--){
		for(int j=M-1; j>=0; j--){
			
			
			//se la cella è l'arrivo allora l'unico percorso è stare fermi
			if(i==N-1 && j==M-1)
				percorsi[i][j]=1;
				
			else if(campo[i][j]=='+')
				percorsi[i][j]=0;
			
			else{
								
				//se la cella sotto NON è fuori range e NON è una mina allora la considero
				if( (i+1 < N) && (campo[i+1][j] != '+'))
					percorsi[i][j]+=percorsi[i+1][j];
				
				//se la cella a destra NON è fuori range e NON è una mina allora la considero	
				if( (j+1 < M) && (campo[i][j+1] != '+'))
					percorsi[i][j]+=percorsi[i][j+1];
			
			}
				
		}
	}
			
	//metto nel file di putput il valore di percorsi[0][0]
	out<<percorsi[0][0];
	//chiudo il file output
	out.close();
	
	
	return 0;
}
