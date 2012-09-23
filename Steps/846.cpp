/* 

Steps

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N;
  cin >> N;
  while(N--){
    int A, B;
    cin >> A >> B;
    int d = B-A;
    int m = d/2;
    int n = (int)(-1+sqrt(1+8*m))/2;
    int v = n*(n+1)/2;
    if(d == 2*v) cout << 2*n << endl;
    else{
      int dd = d-2*v;
      if(dd%(n+1)==0 || dd%(n+1)==n) cout << 2*n + dd/(n+1) + (dd%(n+1)>0?1:0) << endl;
      else cout << 2*n + dd/n + (dd%n>0?1:0) << endl;
    }
  }
  return 0;
}
