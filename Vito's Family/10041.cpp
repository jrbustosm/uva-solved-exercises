/* 

Vito's Family

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int r;
    cin >> r;
    int* v = new int[r]; 
    for(int i=0; i<r; ++i) cin >> v[i];
    sort(v, v+r);
    int s = v[r/2];
    int d=0;
    for(int i=0; i<r; ++i) d+=abs(s-v[i]);
    cout << d << endl;
  }
}

