#include <cstdio>
#include <cassert>

/*	definisico una array DIFF dove l' i-esima cella mi identifica il valore
	per quella data differenza.
	dimensione 5000000 -> valore preso dalla soluzione di Rizzi (per non incorrere in errori nel CMS).
*/
int DIFF[5000000];

int f(int a, int b) {

	/*
	sia delta=a-b
	Ad ogni delta corrisponde un numero di chiamate di f sempre uguale
	*/

	if(a<=b)
		return 1;

	if(DIFF[a-b]==0){
		//calcolo il numero di chiamate di f su quella differenza
		DIFF[a-b] = (1 + 2*f(a-1, b) + f(a-5, b + 5))%1024;
	}

	return DIFF[a-b];

}

int main() {
  #ifdef EVAL
      assert( freopen("input.txt", "r", stdin) );
      assert( freopen("output.txt", "w", stdout) );
  #endif

  //il parametro c è un parametro farlocco, non serve
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  
  printf("%d\n", f(a,b));
  return 0;
}