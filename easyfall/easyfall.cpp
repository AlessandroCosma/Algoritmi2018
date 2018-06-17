#include <cassert>
#include <cstdio>

#define NMAX 1000000

int N;
int tessera[NMAX+1]; 	//vettore che per ogni cella i contiene una tessera di altezza tessera[i]
int isole[NMAX+1];	//vettore che per ogni cella i contiene quante isole hanno dimensione i
int main(){

	#ifdef EVAL
      assert( freopen("input.txt", "r", stdin) );
      assert( freopen("output.txt", "w", stdout) );
  #endif

	scanf("%d", &N);

	for(int i=1; i<=N; i++)
		scanf("%d", &tessera[i]);

	int i=1;
	int min_arrivo=1;
	int num_isole=0;
	bool incrementa;

	/*
	ciclo for e while per andare a scorrere l'array tessera e salvare in
	isole[i] il numero di isole aventi lunghezza i.
	*/

	for(int i=1; i<=N; ){

		int dim_isola = 1;
		num_isole++;
		min_arrivo = i+tessera[i]-1;
		incrementa = true;

		while(i<=N && i<=min_arrivo){

			if(min_arrivo < i+tessera[i]-1){
				min_arrivo = i+tessera[i]-1;
			}

			
			i++;
			if(i<=N && i<=min_arrivo)
				dim_isola++;
			else
				incrementa = false;

		}

		if(incrementa)
			i++;
		isole[dim_isola]++;	
		
	}

	/*
	Manca ora la parte difficile sulla stampa dei valori in output
	Suggerimento Rizzi: usare metodo greedy dalle isole più grandi alle isole più piccole
	*/

	
	

	int somma = 0;
	int num_stampe=0;
	for (int dim = N; dim >= 1; dim--){
		
		while(isole[dim]>0){
			somma += dim;
			printf("%d ", somma );
			num_stampe++;
			isole[dim] -= 1;
		}
	}

	for(int z=num_stampe; z<N; z++)
		printf("%d ", N );


#if 0

	printf("Numero isole: %d\n", num_isole);
	for(int j=0; j<=6; j++){

		printf("[%d]", isole[j]);
	}
	printf("N=%d\n[", N);
	for(int i=0; i<N; i++)
		printf("%d", tessera[i]);
	printf("]\n");
#endif

	return 0;
}
