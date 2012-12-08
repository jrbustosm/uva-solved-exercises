/* 

Brother & Sisters!

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int N, Q, D=0;
    cin >> N >> Q;
    while(N--){
      int v;
      cin >> v;
      D |= v;
    }
    while(Q--){
      int a;
      cin >> a;
      cout << (D&a) << endl;
    }
  }
}
