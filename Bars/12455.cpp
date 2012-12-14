/* 

Bars

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

bool solder(int *v, int n, int z, int sum, int &L);

int main(){
  int T;
  cin >> T;
  while(T--){
    int K, N;
    cin >> K >> N;
    int* v = new int[N];
    for(int i=0; i<N; ++i) cin >> v[i];
    cout << (solder(v, N, 0, 0, K)?"YES":"NO") << endl;
  }
}

bool solder(int *v, int n, int z, int sum, int &L){
  if(sum == L) return true;
  if(sum > L) return false;
  for(int i=z; i<n; ++i) if(solder(v, n, i+1, sum+v[i], L)) return true;
  return false;
}

