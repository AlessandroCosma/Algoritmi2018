#include <iostream>
#include <fstream>
#include <string> 
#include <cstdio>
#include <vector>
#include <algorithm>


/*
	

new_vector.assign(old_vector.begin(),old_vector.end()); // Method 1
new_vector = old_vector; // Method 2
std::vector<int> newvector(oldvector);

*/

using namespace std;
using std::vector;

ifstream in("input.txt");
ofstream out("output.txt");


vector<int> successori[100001];

/* array di 3 elementi: [0] = lung. del percorso massimo che passa per quel nodo
				    	[1] = nodo successivo in un percorso masssimo
				   		[2] = colore nodo: 0->bianco, 1->grigio, 2->nero
*/ 
vector<int>path_max[100001];

int occorrenze[100001];


bool trovato=false;
int cicloStart;
int N,M, maxId=-1;



void leggi_grafo(){
	// lettura del grafo dall'input.txt
	int u;
	in >> u;
	
	occorrenze[u]=1;
	if(u>maxId)
		maxId=u;
	
	int prossimo_nodo;
	in >> prossimo_nodo;
	
	occorrenze[prossimo_nodo]=1;
	if(prossimo_nodo>maxId)
		maxId=prossimo_nodo;
	
	successori[u].push_back(prossimo_nodo);
}
	
	

void trova_percorso(int radice){
	
	//se è nero allora ha già gli attributi settati
	if(path_max[radice][2]==2)
		return;
	
	//se grigio ho il ciclo
	else if(path_max[radice][2]==1){
		trovato=true;
		cicloStart=radice;
		return;
	}
	
	//se bianco
	else{
		
		//lo setto a grigio, cioè inizio a processarlo
		path_max[radice][2]=1;
		
		//radice ha 0 successori
		if(successori[radice].size() == 0){
			path_max[radice][0]=0;
			path_max[radice][1]=0;
			//colore diventa subito nero
			path_max[radice][2]=2;
		}
		
		//radice ha 1 solo successore
		else if(successori[radice].size() == 1){
			
			int successore = successori[radice][0];
			
			trova_percorso(successore);
					
			path_max[radice][0]=1+path_max[successore][0];
			path_max[radice][1]=successore;
			
			path_max[radice][2]=2;
			
			if(trovato)
				return;
							

		}
		
		//radice successori >= 2
		else{
			int successore;

			for(int i=0; i<successori[radice].size(); i++){
				
				successore=successori[radice][i];
				trova_percorso(successore);
				
				if(trovato)
					break;				
			}
			
										
			int max=-1;
			successore=radice;
			int next;
			for(int i=0; i<successori[radice].size(); i++){
				
				next=successori[radice][i];
				int t = path_max[next][0];
				
				if(t>max){
					max=t;
					successore=next;
				}
			}
			path_max[radice][0]=1+max;
			path_max[radice][1]=successore;
			path_max[radice][2]=2;
			
			if(trovato)
				return;
		
		}
	}

}


int main() {

	//apro il file INPUT
	//in.open("input.txt", ios::in);
	
    in >> N >> M;

    // lettura grafo
    for(int i = 0; i < M; i++)
    	leggi_grafo();
    	
    //chiudo il file
    //in.close();
    
    /*
    	aggiungo il nodo radice:
    	ogni nodo del grafo originale viene raggiunto da un arco che parte da radice
    	Id radice = 0
    */
    
    for(int i=1; i<=maxId; i++){
    	if(occorrenze[i]==1)
    		successori[0].push_back(i);
    }
    

    // sort array ed eliminazione duplicati
    for(int i = 1; i <= N; i++){
    	std::sort( successori[i].begin(), successori[i].end() );
    	successori[i].erase( std::unique( successori[i].begin(), successori[i].end() ), successori[i].end() );
    }
    
    //inizializzo l'array path_max
    for(int i=0; i<=maxId; i++)
    	for(int j=0; j<3; j++)
    		path_max[i].push_back(0);
    
#if 0 
    for(int u = 0; u <= maxId; u++){
    	cout<<"Successore di "<<u<<":";
    	for(int i = 0; i < successori[u].size(); i++)
    		cout<<" "<<successori[u][i];
    	cout<<endl;
    }
#endif      
    
        
    //apro il file OUTPUT
	//out.open("output.txt", ios::out);
	
	//lancio la funzione
	trova_percorso(0);
		
#if 1
	for(int i=0; i<=maxId; i++){
		cout<<"path_max["<<i<<"]: ";
    	cout<<path_max[i][0]<<" "<<path_max[i][1];
    	cout<<endl;
	}
  
    cout<<"colore:";
    for(int i=0; i<=maxId; i++)
    	cout<<"["<<path_max[i][2]<<"]";
    cout<<endl;

    cout<<"trovato="<<trovato<<endl;
#endif 
	
	vector<int> path;
	int next;
	
	if(trovato){
		

		cout<<"nodo di inizio ciclo: "<<cicloStart<<endl;
		//inserisco il primo nodo del ciclo
		path.push_back(cicloStart);
		
		next=path_max[cicloStart][1];
		while(next!=cicloStart){
			path.push_back(next);
			next=path_max[next][1];
		}
		
		out<<"-1 "<<path.size()<<endl;
		out<<path[0];
		for(int i=1; i<path.size(); i++)
			out<<" "<<path[i];
	}
	
	else{
		
		int lunghezza=path_max[0][0];
		//stampo la lunghezza del percorso massimo
		out<<lunghezza<<endl;
		
		next=path_max[0][1];
		
		#if 0
		while(next!=0){
			path.push_back(next);
			next=path_max[next][1];
		}
		#endif
		
		for(int step=0; step<lunghezza; step++){
			path.push_back(next);
			next=path_max[next][1];
		}
		
		out<<path[0];
		for(int i=1; i<path.size(); i++)
			out<<" "<<path[i];
	
	}
		
	//out.close();

    return 0;
}
