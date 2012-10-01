/* 

Cost Cutting

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=0; t<T; ++t){
    unsigned int A, B, C;
    cin >> A >> B >> C;
    if(A > B) swap(A, B);
    if(B > C) swap(B, C);
    if(A > B) swap(A, B);
    cout << "Case " << t+1 << ": " << B << endl; 
  }
}

