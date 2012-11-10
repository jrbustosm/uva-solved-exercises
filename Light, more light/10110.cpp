/* 

Light, more light

Jose Ricardo Bustos Molina

perfect square

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  unsigned int n;
  cin >> n;
  while(n!=0){
    unsigned int s = (unsigned int)(sqrt(n));
    cout << (s*s==n?"yes":"no") << endl;
    cin >> n;
  }
}

