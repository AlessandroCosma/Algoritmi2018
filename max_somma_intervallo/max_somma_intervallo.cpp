#include <cstdio>
#include <cassert>
 
const int N_MAX = 1000000;
int num[N_MAX];
int result[N_MAX];

int main(){
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    	scanf("%d", &num[i]);

#if 0
    for(int i = 0; i < N; i++)
        printf("%d ", array[i]);    
    printf("\n");
#endif

    result[0] = num[0];

    for(int i = 1; i < N; i++){
        if(result[i - 1] < 0)
            result[i] = num[i];
        else
            result[i] = result[i - 1] + num[i];
    }

#if 0
    for(int i = 0; i < N; i++)
        printf("%d ", result[i]);    
    printf("\n");
#endif

    int somma = -1000000;

    for(int i = 0; i < N; i++)
        if(result[i] > somma){
            somma = result[i];
    }
    
    printf("%d\n", somma);

    return 0;
}