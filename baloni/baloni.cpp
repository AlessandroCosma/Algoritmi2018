#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

const int N_MAX = 1000000;

int N;
int p[N_MAX];
int r[N_MAX+1];

//ritorna la posizione di num se è presente in v
//ritorna -1 se non è presente
int trova(int num, vector<int> v){

    vector <int>::iterator element;
    element = find(v.begin(), v.end(), num);

    // Controlliamo se l’elemento e’ stato trovato
    if (element != v.end())
        return distance(v.begin(), element);
    else
        return -1;
}

int main() {

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //leggo N
    scanf("%d", &N);

    //leggo il vettore delle altezze
    for (int i = 0; i < N; i++)
        scanf("%d", &p[i]);

    //inizializzo il vettore dei risultati a 0
    for(int i=0; i<N; i++){
            r[i]=0;
        }
    
#if 0
    printf("p=");
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);
    printf("\n");
#endif    

    //scorro il vettore delle altezze
    for(int i=0; i<N; i++){

        if(i == 0){
            r[p[i]-1]+=1;
            continue;
        }

        //se NON c'è una freccia in r all altezza 'i' incremento il valore della posizione 'i' di 1
        if(r[p[i]] == 0)
            r[p[i]-1]+=1;
        
        //se c'è una freccia in r all altezza 'i' incremento il valore della posizione 'i-1' di 1
        //deceremento il valore della posizione i di -1
        else{
            r[p[i]-1]+=1;
            r[p[i]]-=1;
        }
    }
    
    int frecce = 0;
    //sommo le frecce che ho salvato nelle celle i-esime del vettore r
    for(int i=0; i<N; i++){
        frecce+=r[i];
    }

    printf("%d",frecce);

#if 0
    printf("r=");
    for (int i = 0; i < N; i++)
        printf("%d ", r[i]);
    printf("\n");
#endif       
    
    return 0;
    
}
