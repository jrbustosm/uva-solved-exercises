/* 

WERTYU

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

int main(){
  map<char, char> m;
  string w = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ ";
  string q = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. ";
  for(int i=0; i<44; ++i) m[w[i]] = q[i];
  string s;
  while(getline(cin, s)){
    for(string::iterator it = s.begin(); it!=s.end(); ++it) cout << m[*it];
    cout << endl;
  }
}

