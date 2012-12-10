/* 

Bafana Bafana

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    int N, K, P;
    cin >> N >> K >> P;
    cout << "Case " << t << ": " << (P+K-1)%N+1 << endl;
  }
}
