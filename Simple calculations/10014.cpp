/* 

Simple calculations
(n+1)A1 = nA0 + An+1 - 2Cn - 4Cn-1 - 6Cn-2 - ... - (2n)C1

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  int M;
  cin >> M;
  for(int k=0; k<M; ++k){
    int n;
    double a_0, a_nx1;
    cin >> n >> a_0 >> a_nx1;
    double d = 0;
    for(int i=0; i<n; ++i){
      double c;
      cin >> c;
      d += c * (2*n-i*2);
    }
    double a_1 = (n*a_0 + a_nx1 - d)/(n+1);
    if(k>0) cout << endl;
    cout << a_1 << endl;
  }
}

