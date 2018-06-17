#include <cstdio>
#include <cassert>

int tot = 0;

int matrix [5000][5000];

int f(int a, int b) {

	if(a<=b)
		return 1;
	if(matrix[a][b]==0)
			matrix[a][b] = (1 + 2*f(a-1,b) + f(a-5,b+5))%1024;
	return matrix[a][b];
}


int main() {
  #ifdef EVAL
      assert( freopen("input.txt", "r", stdin) );
      //assert( freopen("output.txt", "w", stdout) );
  #endif

  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  tot=f(a,b);
  printf("%d\n", tot);
  return 0;
}
