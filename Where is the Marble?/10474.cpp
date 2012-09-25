/* 

Where is the Marble?

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, M;
  int cases = 0;
  cin >> N >> M;
  while(N!=0){
    ++cases;
    cout << "CASE# " << cases << ":" << endl;
    vector<int> v(N);
    for(int i=0; i<N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<M; ++i){
      int f;
      cin >> f;
      vector<int>::iterator low = find(v.begin(), v.end(), f);
      if(low != v.end()){
        int pos=int(low-v.begin()) + 1;
        cout << f << " found at " << pos << endl;
      }else{
        cout << f << " not found" << endl;
      }
    }
    cin >> N >> M;
  }
  return 0;
}
