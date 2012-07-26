/* 

Train Swapping

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int c=0; c<cases; ++c){
    int N;
    cin >> N;
    vector<int> v(N);
    int cswap = 0;
    for(int i=0; i<N; ++i) cin >> v[i];
    //Bubble Sort
    for(int i=N-1; i>0; --i){
      for(int j=i-1; j>=0; --j){
        if(v[i] < v[j]){
          swap(v[i], v[j]);
          ++cswap;
        }
      }
    }
    cout << "Optimal train swapping takes " << cswap << " swaps." << endl;
  }
  return 0;
}
