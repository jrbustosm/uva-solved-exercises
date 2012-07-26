/* 

Power of Cryptography

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  long double n, p;
  while(cin >> n >> p) cout << fixed << setprecision(0) << exp(log(p)/n) << endl;
}
