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

ifstream in;
ofstream out;


vector<int> successori[100001];

/*array di coppie: [0] = lung. del percorso massimo che passa per quel nodo
				   [1] = nodo successivo in un percorso masssimo
				   [2] = calcolo già effettuato (1) o non ancora effettuato (0)
				   [3] = se è un antenato (1) oppure no (0)
*/ 
int path_max[100001][4];
bool trovato=false;
int cicloStart;
int N,M;



void leggi_grafo(){
	// lettura del grafo dall'input.txt
	int u;
	in >> u;

	int prossimo_nodo;
	in >> prossimo_nodo;
	
	successori[u].push_back(prossimo_nodo);
}
	
	

void trova_percorso(int radice){

	if(path_max[radice][3]==1){
		trovato=true;
		cicloStart=radice;
		return;
	}
	
	
	
	//radice ha 0 successori
	if(successori[radice].size() == 0){
		path_max[radice][0]=0;
		path_max[radice][1]=-1;
	}
	
	//radice ha 1 solo successore
	else if(successori[radice].size() == 1){
		
		path_max[radice][3]=1;
		int successore = successori[radice][0];
		
		//se il nodo successore NON è stato processato
		if(path_max[successore][2]==0){
				path_max[successore][2]=1;
				trova_percorso(successore);
		}
		
		path_max[radice][0]=1+path_max[successore][0];
		path_max[radice][1]=successore;

	}
	
	//radice successori >= 2
	else{
		
		path_max[radice][3]=1;
		for(int i=0; i<successori[radice].size(); i++)
			if(path_max[ successori[radice][i] ][2]==0){
				path_max[ successori[radice][i] ][2]=1;
				trova_percorso(successori[radice][i]);
			}
		
		int max=-1;
		int successore=radice;
		for(int i=0; i<successori[radice].size(); i++){
			
			int t = path_max[successori[radice][i]][0];
			
			if(t>max){
				max=t;
				successore=successori[radice][i];
			}
		}
		path_max[radice][0]=1+max;
		path_max[radice][1]=successore;
	
	
	}

}


int main() {

	//apro il file INPUT
	in.open("input03.txt", ios::in);
	
    in >> N >> M;

    // lettura grafo
    for(int i = 0; i < M; i++)
    	leggi_grafo();
    	
    //chiudo il file
    in.close();
    
    /*
    	aggiungo il nodo radice:
    	ogni nodo del grafo originale viene raggiunto da un arco che parte da radice
    	Id radice = 0
    */
    
    for(int i=1; i<=N; i++)
    	successori[0].push_back(i);
    

    // sort array ed eliminazione duplicati
    for(int i = 1; i <= N; i++){
    	std::sort( successori[i].begin(), successori[i].end() );
    	successori[i].erase( std::unique( successori[i].begin(), successori[i].end() ), successori[i].end() );
    }
    
#if 1    
    for(int u = 0; u <= N; u++){
    	cout<<"Successore di "<<u<<": ";
    	for(int i = 0; i < successori[u].size(); i++)
    		cout<<successori[u][i];
    	cout<<endl;
    }
#endif    
        
    //apro il file OUTPUT
	out.open("output.txt", ios::out);
	
	//lancio la funzione
	trova_percorso(0);
	
#if 1
	for(int i=0; i<=N; i++){
		cout<<"path_max["<<i<<"]: ";
    	cout<<path_max[i][0]<<" "<<path_max[i][1]<<" "<<path_max[i][2]<<" "<<path_max[i][3];
    	cout<<endl;
	}
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
		for(int i=0; i<path.size(); i++)
			out<<path[i]<<" ";
	}
	
	else{
		
		//stampo la lunghezza del percorso massimo
		out<<path_max[0][0]<<endl;
		
		next=path_max[0][1];
		while(next!=-1){
			path.push_back(next);
			next=path_max[next][1];
		}
	
		for(int i=0; i<path.size(); i++)
			out<<path[i]<<" ";
	
	}
		
	out.close();

    return 0;
}
