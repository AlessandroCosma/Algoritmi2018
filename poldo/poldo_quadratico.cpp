#include <cstdio>
#include <cassert>
#include <algorithm>

const int N_MAX = 10000, P_MAX = 10000;

int N;
int p[N_MAX+1];
int memo[1000][P_MAX+2];

int ric(int i, int peso) {
    /*
    ric(i, peso) =
        la massima lunghezza di una sottosequenza di p[i], p[i+1], ..., p[N-1]
        che:
            1) sia strettamente decrescente
            2) ogni valore sia strettamente minore di peso
     */
    if (i == N)
        return 0;
    
    if (memo[i][peso] == 0)
    {
        // caso 1: p[i] NON compare nella sottosequenza
        int risp1 = ric(i+1, peso);
        // caso 2: p[i] compare nella sottosequenza
        if (p[i] < peso) 
        {
            int risp2 = 1 + ric(i+1, p[i]);
            memo[i][peso] = std::max(risp1, risp2);
        } 
        else 
            memo[i][peso] = risp1;
    }

    //fprintf(stderr, "ric(%d,%d) -> %d\n", i, peso, memo[i][peso]);
    return memo[i][peso];
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    
    printf("%d\n", ric(0, P_MAX+1));
}