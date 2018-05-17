#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> p;
vector<int> soluzione;

int poldo()
{
    for(int i = 1; i < N; i++)
        for(int j = i-1; j >= 0; j--)
            if(p[j] > p[i] && soluzione[j] >= soluzione[i]) 
                soluzione[i] = soluzione[j] + 1;
    
    int max = *max_element(soluzione.begin(), soluzione.end());
    return max;
}


int main() 
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);

    p.resize(N);
    soluzione.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p[i]);
        soluzione[i] = 1;
    }
    
    printf("%d\n", poldo());
    return 0;
}