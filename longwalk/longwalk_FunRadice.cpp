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
vector<int> percorsi[100001];
int gradouscente[100001];
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
	gradouscente[u]++;
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


int trova_radice(int N){
	int radice[N];
	for(int i = 0; i < N ; i++) // inizializzo tutto l'array a 1
		radice[i] = 1;

	for(int i = 1; i < N + 1; i++){ // metto a 0 tutti i nodi che non hanno nessun arco uscente, non possono essere la radice
		if(gradouscente[i] == 0)
			radice[ i - 1 ] = 0;
		for(int j = 0; j < successori[i].size(); j++) // metto a zero tutti i nodi che hanno archi entranti, non possono essere la radice
			radice[ successori[i].at(j) - 1 ] = 0;
	}
	
	int miaRadice=-1;
	for (int i = 0; i < N; i++) // trovo la prima radice e mi fermo subito, me ne basta una
		if (radice[i] == 1){
			miaRadice = i + 1;
			break;
		}
	
	//se non c'è radice prendo un nodo con grado>0
	if(miaRadice==-1){
		
		for(int i = 1; i < N + 1; i++)
			if(gradouscente[i]!=0){
				miaRadice=i;
				break;
			}
	}
	
	/*	
	cout<<"radice";
    for(int i=0; i<N; i++)
    	cout<<"["<<radice[i]<<"]";
    */	

	return miaRadice;
}


int main() {

	//apro il file INPUT
	in.open("input.txt", ios::in);
	
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
    

    // sort grafo ed eliminazione duplicati
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
    
    /*
    cout<<" grado";
    for(int i=1; i<N+1; i++)
    	cout<<"["<<gradouscente[i]<<"]";
    cout<<endl;
    */
      
    //int radice = trova_radice(N);
    //cout<<"\nradice="<<radice<<endl;
    trova_percorso(0);
    /*
    if(radice!=-1)
    	trova_percorso(radice);
    else{
    	for(int i=1; i<N; i++)
    		trova_percorso(i);
    }
    */
    
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
