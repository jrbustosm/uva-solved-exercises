/* 

Scarecrow

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    int N, c=0;
    string s;
    cin >> N >> s;
    bool f=false;
    for(string::iterator i=s.begin(); i<s.end(); ++i){
      if(f){
        f=false;
        ++c;
        ++i;
      }else if(*i=='.') f=true;
    }
    if(f) ++c;
    cout << "Case " << t << ": " << c << endl;
  }
}
