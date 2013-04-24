/* 

Nice Licence Plates

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int conv(string &s);

int main(){
  int N;
  string s;
  cin >> N;
  getline(cin, s);
  while(N--){
    getline(cin, s, '-');
    int c = conv(s);
    int d;
    cin >> d;
    getline(cin, s);
    cout << (abs(c-d)<=100?"nice":"not nice") << endl;;
  }
}

int conv(string &s){
  return (s[0]-'A')*26*26 + (s[1]-'A')*26 + (s[2]-'A');
}

