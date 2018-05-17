#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

const int N_MAX = 1000000;

int N;
int p[N_MAX];
vector<int> r;


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

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    
#if 0
    printf("p=");
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);
    printf("\n");
#endif    

    for(int i=0; i<N; i++){

        if(i == 0){
            r.push_back(p[i]-1);
            continue;
        }

        int posizione = trova(p[i], r);

        if(posizione == -1){
            r.push_back(p[i]-1);
        }

        else{
           r[posizione]=p[i]-1;
        }

    }
    
    printf("%d",r.size());

#if 0
    printf("r=");
    for (int i = 0; i < r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
#endif       
    
    return 0;
    
}
