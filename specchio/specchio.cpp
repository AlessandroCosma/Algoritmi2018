#include <cstdio>
#include <cassert>
#include <vector>

using std::vector;

int prossimo_nodo = 0;
// figli[u] = sequenza ordinata degli ID dei figli del nodo u
vector<int> figli[1000000];

void leggi_albero(){
	// legge un intero sottoalbero radicato in 'prossimo_nodo'
	// e incrementa 'prossimo_nodo' al più piccolo
	// ID ancora non usato
	int u = prossimo_nodo;
	prossimo_nodo++;

	int n_figli;
	scanf("%d", &n_figli);
	figli[u].resize(n_figli);
	
	for(int i = 0; i < n_figli; i++){
		figli[u][i] = prossimo_nodo;
		leggi_albero();
	}
}

void stampa_albero(int radice){
	// stampa il sottoalbero radicato in 'radice'
	int n_figli = figli[radice].size();
	printf("%d ", n_figli);
	for(int i = 0; i < n_figli; i++){
		int figlio = figli[radice][i];
		stampa_albero(figlio);
	}
}

void stampa_albero_specchio(int radice){
	// stampa il sottoalbero radicato in 'radice'
	int n_figli = figli[radice].size();
	printf("%d ", n_figli);
	for(int i = n_figli - 1; i >= 0; i--){
		int figlio = figli[radice][i];
		stampa_albero_specchio(figlio);
	}
}

int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    leggi_albero();

#if 0
    for(int u = 0; u < prossimo_nodo; u++){
    	printf("Figlio di %d: ", u);
    	for(int i = 0; i < figli[u].size(); i++)
    		printf("%d ", figli[u][i] );
    	printf("\n");
    }

    stampa_albero(0);
    printf("\n");
#endif

    stampa_albero_specchio(0);
    printf("\n");

    return 0;
}