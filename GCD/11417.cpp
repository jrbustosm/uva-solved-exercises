/* 

GCD

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

using namespace std;

int GCD(int i, int j);

int cache[501][501];

int main(){
  memset(cache, -1, sizeof(int)*501*501);
  int N;
  cin >> N;
  while(N!=0){
    int G=0;
    for(int i=1;i<N;++i) for(int j=i+1;j<=N;++j) G+=GCD(i,j);
    cout << G << endl;
    cin >> N;
  }
}

int GCD(int i, int j){
  if(cache[i][j]!=-1) return cache[i][j];
  int auxi = i, auxj = j;
  while(j!=0){
    int aux = j;
    j = i % j;
    i = aux;
  }
  cache[auxi][auxj] = i;
  cache[auxj][auxi] = i;
  return i;
}

