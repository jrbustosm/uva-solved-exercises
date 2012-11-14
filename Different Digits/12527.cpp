/* 

Different Digits

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  int N, M;
  while(cin >> N >> M){
    int c = 0;
    for(int i=N; i<=M; ++i){
      ostringstream oss;
      oss << i;
      string s = oss.str();
      sort(s.begin(), s.end());
      bool f = true;
      for(string::iterator it=s.begin()+1; it!=s.end() && f; ++it){
        if(*it == *(it-1)) f = false;
      }
      if(f) ++c;
    }
    cout << c << endl;
  }
}

