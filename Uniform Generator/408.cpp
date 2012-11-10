/* 

Uniform Generator

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

using namespace std;

bool m[10000001];

int main(){
  unsigned long int step, mod;
  while(cin >> step >> mod){
    memset(m, false, sizeof(bool)*10000001);
    unsigned long int n = 0, c=0;
    while(!m[n]){
      m[n] = true;
      n = (n+step)%mod;
      ++c;
    }
    cout.fill(' ');
    cout.width(10);
    cout << step;
    cout.fill(' ');
    cout.width(10);
    cout << mod;
    cout << "    " << (c==mod?"Good Choice":"Bad Choice") << endl << endl;
  }
}

