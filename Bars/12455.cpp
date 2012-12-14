/* 

Bars

Jose Ricardo Bustos Molina

*/

#include <cstdio>

using namespace std;

bool solder(int *v, int &n, int z, int sum, int &L);

int main(){
  int v[20];
  int T, K, N, i;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &K, &N);
    for(i=0; i<N; ++i) scanf("%d",&v[i]);
    puts(solder(v, N, 0, 0, K)?"YES":"NO");
  }
}

bool solder(int *v, int &n, int z, int sum, int &L){
  if(sum == L) return true;
  if(sum > L) return false;
  for(int i=z; i<n; ++i) if(solder(v, n, i+1, sum+v[i], L)) return true;
  return false;
}

