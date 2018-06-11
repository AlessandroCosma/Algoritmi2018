#include <cstdio>
#include <cassert>

int massimo(int N1 , int N2, int N3){

	int Max;

	if (N1 > N2)
        Max = N1;
    else
        Max = N2;
 
   	if (N3 > Max)
        Max = N3;

    return Max;
}



int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    scanf("%d", &M);
    scanf("%d", &N);

    //matrice di input
    int celle[M][N];

    //leggo la matrice
    for(int i=0; i<M; i++)
    	for(int j=0; j<N; j++)
    		scanf("%d", &celle[i][j]);
#if 0
	for(int i=0; i<M; i++){
    	for(int j=0; j<N; j++)
    		printf("%d ", celle[i][j]);
    	printf("\n");
	}
#endif

    if(M==1){
    	int max=0;
    	for(int j=0; j<N; j++)
    		max+=celle[0][j];
    	printf("%d\n", max);
    }

    else if(N==1){
		int max=0;
    	for(int i=0; i<M; i++)
    		if(celle[i][0]>max)
	    		max=celle[i][0];
    	printf("%d\n", max);

    }

    else{
	    //salvo in percorso il massimo valore che ottengo da quella cella visitata
	    int percorso[M][N];
	    for(int i=0; i<M; i++)
	    	for(int j=0; j<N; j++)
	    		percorso[i][j]=0;

	    //l'ultima colonna avrà valori uguali alla matrice di input
	    for(int i=M-1; i>=0; i--)
	    	percorso[i][N-1]=celle[i][N-1];

	    for(int j=N-2; j>=0; j--){
	    	for(int i=M-1; i>=0; i--){
	    		if(i==0)
	    			percorso[i][j]=celle[i][j]+massimo(percorso[i][j+1], percorso[i+1][j+1],0);
	    		else if(i==M-1)
	    			percorso[i][j]=celle[i][j]+massimo(percorso[i][j+1], percorso[i-1][j+1],0);
	    		else
	    			percorso[i][j]=celle[i][j]+massimo(percorso[i][j+1], percorso[i-1][j+1],percorso[i+1][j+1]);

	    	}

	    }

	    //stampa di prova cella matrice
		#if 0
			for(int i=0; i<M; i++){
		    	for(int j=0; j<N; j++)
		    		printf("%d ", percorso[i][j]);
		    	printf("\n");
			}
		#endif

	    int max=0;
	    for(int i=0; i<M; i++){
	    	if(percorso[i][0]>max)
	    		max=percorso[i][0];
	    }

	    printf("%d\n", max);
   	}



    return 0;
}