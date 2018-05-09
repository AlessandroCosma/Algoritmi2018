#include <string> 
#include <string.h>
#include <vector>
#include <algorithm>

using std::vector;
int N;

//stampa il vector dato in input
void print_vector(vector<int> vettore){
	for(int i = 0; i < vettore.size(); i++)
		printf("%d ", vettore[i] );
	printf("\n");
}

void stampa_intermedia(vector<int> vettore, int passo, int start){
	vector<int> tmp;
	
	/*
	se l'indice start da dove iniziare a sommare le cifre, è oltre il limite del vettore,
	allora ritorno al chiamante
	*/
	if(vettore[start-1] < passo || start >= vettore.size())
		return;
	
	//copio la prima parte del vettore precedente, da begin a start escluso
	tmp.assign(vettore.begin(), vettore.begin()+start);
	
	/*inserisco la nuova cifra sommata -->  ESSENDO SOMME DI SOLI 1 POSSO METTERE IL
											VALORE DI 'PASSO' ANZICHÈ LA RELATIVA SOMMA DI 1
	*/
	tmp.push_back(passo);
	
	//se la parte rimanente da copiare del vettore precedente esiste la copio, altrimenti no
	if(start + passo < vettore.size())
		tmp.insert(tmp.end(), vettore.begin()+start+passo, vettore.end());
	print_vector(tmp);
	
	for(int step = 2; step < tmp.size() - start; step++){
		if(tmp[start-1] < step)
			return;
		else
			stampa_intermedia(tmp, step, start+1);	
	}
}

void stampa_ricorsiva(vector<int> vec){
	if(vec.size() == 2){
		printf("%d\n", vec[0] + vec[1]);
		return;
	}
	
	int somma = vec[0] + vec[1];
	
	vector<int> new_vec;
		
	//carico in new_vec il vettore 'base' del tipo <2 1 1 1>, <3 1 1 1>...
	new_vec.push_back(somma);
	new_vec.insert(new_vec.end(), vec.begin()+2, vec.end());
	
	//stampo il new_vec
	print_vector(new_vec);
	
	//stampe intermedie
	for(int passo = 2; passo <= new_vec.size() - 1; passo++){
		if(new_vec[0] < passo)
			break;
		else
			stampa_intermedia(new_vec,passo,1);
	}	
	
	//chiamata ricorsiva su nuovo vettore new_vec
	stampa_ricorsiva(new_vec);
}

void stampa_borse(int N){
	vector<int> primo;
	for(int i = 0; i < N; i++)
		primo.push_back(1);
	
	print_vector(primo);
	stampa_ricorsiva(primo);
}


int main(){
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d", &N);
	
	if(N==1)
		printf("1\n");
	else
		stampa_borse(N);
		
	return 0;
}