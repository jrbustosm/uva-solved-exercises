/* 

Squares

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

using namespace std;

int cache[10001];

int min(int N);

int main(){
  memset(cache, 10000, sizeof(int)*10001);
  for(int i=1; i<=100; ++i) cache[i*i]=1; 
  int T;
  cin >> T;
  min(10000);
  while(T--){
    int N;
    cin >> N;
    cout << cache[N] << endl;
  }
}

int min(int N){
  for(int i=1; i<=N; ++i){
    if(cache[i]==1) continue;
    for(int j=1; j<=i/2; ++j){
      int v = cache[j]+cache[i-j];
      if(v<cache[i]) cache[i] = v;
    }
  }
}

