#include <cstdio>
#include <cassert>

long long int numero_mosse(int n){
	/*
		Ritorna il numero di mosse per spostare una torre di n dischi 
		da un piolo a un altro.
	*/
	assert(n >= 1);
	if(n == 1) return 1;
	return 2 * numero_mosse(n-1) + 1;
}

void sposta_disco(int n, int from, int to){
	printf("Sposta il disco %d da %d a %d\n", n, from, to);
}

void stampa_mosse(int n, int from, int to, int terzo_piolo){
	/*
		Stampa le mosse per spostare una torre di n dischi 
		dl piolo 'from' al piolo 'to'.
	*/
	assert(n >= 0);
	if(n == 0) return;

	//int terzo_piolo = 6 - from - to; // invariante
	stampa_mosse(n-1, from, terzo_piolo, to);
	sposta_disco(n, from, to);
	stampa_mosse(n-1, terzo_piolo, to, from);
}

int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    scanf("%d", &N);

    printf("Numero di mosse: %lld\n", numero_mosse(N));
    stampa_mosse(N, 1, 2, 3);

    return 0;
}