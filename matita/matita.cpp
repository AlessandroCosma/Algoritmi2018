#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

// GLOBALI
vector <int> adj[100000];

// FUNZIONE
void searc(int n){
	for (int i = 0; i < adj[n].size(); i++){
		if (adj[n][i] >= 0){
			int x = adj[n][i];
			adj[n][i] = -1;
			for (int k = 0; k < adj[x].size(); k++){
				if(adj[x][k] == n){
					adj[x][k] = -1;
					break;
				}
			}
			searc(x);
			printf("%d %d\n", x, n );
		}
	}
}

// MAIN
int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N, M, A, B;
	scanf("%d%d%d%d", &N, &M, &A, &B);

	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	searc(B);
}