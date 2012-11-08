/* 

Skew Binary

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  string s;
  getline(cin, s);
  while(s!="0"){
    long n=0;
    for(int i=0; i<s.size(); ++i) n+= (s[i]-'0') * (pow(2,s.size()-i)-1);
    cout << n << endl;
    getline(cin, s);
  }
}

