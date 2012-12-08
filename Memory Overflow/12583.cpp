/* 

Memory Overflow

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int c=0;
    for(int i=1; i<n; ++i){
      int j = i-k;
      if(j<0) j=0;
      for(;j<i;++j){
        if(s[i]==s[j]){
          ++c;
          break;
        }
      }
    }
    cout << "Case " << t << ": " << c << endl;
  }
}
