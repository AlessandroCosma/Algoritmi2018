#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;

int N;
vector<int> cost;
vector<vector<int> > adj;

vector<int> P, Q;
vector<bool> S;

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    P[u] = 0;
    for(int v : adj[u]) {
        if(v == p) continue;
        P[u] += Q[v];
    }

    Q[u] = cost[u];
    for(int v : adj[u]) {
        if(v == p) continue;
        Q[u] += std::min(P[v], Q[v]);
    }
}

void soluzione(int u, int p) {
    S[u] = (p != -1 && !S[p]) || (Q[u] < P[u]);
    for(int v : adj[u]) {
        if(v == p) continue;
        soluzione(v, u);
    }
}


int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);
    cost.resize(N);
    
    for(int u = 0; u < N; u++)
        scanf("%d", &cost[u]);

    adj.resize(N);
    
    for(int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    P.resize(N);
    Q.resize(N);
    dfs(0, -1);

    S.resize(N);
    soluzione(0, -1);

    vector<int> T;
    for(int u = 0; u < N; u++)
        if(S[u]) 
            T.push_back(u);

    printf("%lu\n", T.size());
    for(int u : T) 
        printf("%d ", u+1);
    printf("\n");
}