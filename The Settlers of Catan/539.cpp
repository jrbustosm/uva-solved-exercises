/* 

The Settlers of Catan

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

using namespace std;

void maxcatan(bool** g, int c, int &max, int i, int N);

int main(){
  int n, m;
  cin >> n >> m;
  while(!(n==0 && m==0)){
    bool** g = new bool*[n];
    for(int i=0; i<n; ++i){
      g[i] = new bool[n];
      memset(g[i], false, sizeof(bool)*n);
    }
    for(int i=0; i<m; ++i){
      int u, v;
      cin >> u >> v;
      g[u][v] = true;
      g[v][u] = true;
    }
    int max = 0;
    for(int i=0; i<n; ++i) maxcatan(g, 0, max, i, n);
    cout << max << endl;
    cin >> n >> m;
  }
}

void maxcatan(bool** g, int c, int &max, int i, int N){
  if(c>max) max = c;
  //tour all edges
  for(int j=0; j<N; ++j){
    if(g[i][j]){
      g[i][j] = false;
      g[j][i] = false;
      maxcatan(g, c+1, max, j, N);
      g[i][j] = true; //backtraking
      g[j][i] = true;
    }
  }
}

