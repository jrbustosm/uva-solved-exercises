/* 

Jolly Jumpers

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int v[3000];
  int N;
  while(cin >> N){
    int a;
    cin >> a;
    for(int i=0; i<N-1; ++i){
      int b;
      cin >> b;
      v[i]=abs(b-a);
      a = b;
    }
    bool f = true;
    sort(v,v+N-1);
    for(int i=1; i<=N-1 && f; ++i) f &= v[i-1]==i;
    cout << (f?"Jolly":"Not jolly") << endl;
  }
}

