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
vector<int> path_max;
vector<int> temp;
vector<int> ciclo;
bool trovato=false;

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
	
	int L;
	int i=0;
	int successore;
	
	/*
	cout<<"temp";
	for(int z=0; z<temp.size(); z++)
		cout<<"["<<temp[z]<<"]";
	cout<<endl;
	
	cout<<"max";
	for(int z=0; z<path_max.size(); z++)
		cout<<"["<<path_max[z]<<"]";
	cout<<endl;
	*/
	
	//controllo che non ci sia già --> per il controllo CICLO
	//salvo in pos la posizione dell'elemento radice
	int pos = std::find(temp.begin(), temp.end(), radice) - temp.begin();
	
	//se c'è elemento RADICE
	if(pos < temp.size() ){
		trovato=true;
		ciclo.assign(temp.begin()+pos,temp.end());
	}
	/*
	for(int k=0; k<temp.size(); k++){
		if(radice==temp[k]){
			trovato=true;
			ciclo.assign(temp.begin()+k,temp.end());
			break;
		}
	}
	*/
	
	if(trovato)
		return;
		
	else{
		
		//inserisco il nodo in temp[]
		temp.push_back(radice);
	
	
		do{
			
				if(successori[radice].size()>0){
					successore = successori[radice][i++];
					trova_percorso(successore);
				}
				
				else{
					
					/*	
						copio il vettore temp[] nel vettore path_max[]
						<=> la sua lunghezza è maggiore di path_max
					*/
					if(temp.size()>path_max.size()){
						//copio il vettore
						path_max.assign(temp.begin(),temp.end());				
					}
					
					//cancello ultimo elemento inserito in temp[]
					L = temp.size();
					temp.erase(temp.end()-1);	
					//esco dalla funzione
					return;
				}
			 	
		}
		while(i<successori[radice].size() && trovato==false);
		
			
		//cancello ultimo elemento inserito in temp[] a meno che non sia la radice iniziale
		L = temp.size();
		if(L>1)
				temp.erase(temp.end()-1);	
	
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
    
    /*
    for(int u = 0; u <= N; u++){
    	cout<<"Successore di "<<u<<": ";
    	for(int i = 0; i < successori[u].size(); i++)
    		cout<<successori[u][i];
    	cout<<endl;
    }
    */
    
    trova_percorso(0);
        
    //apro il file OUTPUT
	out.open("output.txt", ios::out);
	
	//cout<<"\ntrovato="<<trovato<<endl;
	
    if(!trovato){
    	out<<path_max.size()-1<<endl;
		for(int i=1; i<path_max.size(); i++)
			out<<path_max[i]<<" ";
	}
	
	else{
		out<<"-1 "<<ciclo.size()<<endl;
		for(int i=0; i<ciclo.size(); i++)
			out<<ciclo[i]<<" ";
	}
	
	out.close();

    return 0;
}
