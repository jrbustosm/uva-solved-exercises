/* 

Cubes

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

int m[10001][2];

using namespace std;

int main(){
  memset(m, -1, sizeof(int)*10001*2);
  for(int x=1;; ++x){
    int x3 = x*x*x;
    if(x3-(x-1)*(x-1)*(x-1) > 10000) break;
    for(int y=x-1; y>=0; --y){
      int p = x3 - y*y*y;
      if(p>10000) break;
      if(m[p][1]==-1 || y<m[p][1]){
        m[p][0] = x;
        m[p][1] = y;
      }
    }
  }
  int N;
  cin >> N;
  while(N!=0){
    if(m[N][0] == -1) cout << "No solution" << endl;
    else cout << m[N][0] << " " << m[N][1] << endl;
    cin >> N;
  }
}
