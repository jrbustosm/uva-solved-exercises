/* 

Beat the Spread!

Jose Ricardo Bustos Molina

s = a+b
r = a-b

a = s-b
r = s-b-b
r = s-2b
b = (s-r)/2

*/

#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  while(N--){
    int s, r, a, b;
    cin >> s >> r;
    b = (s-r)/2;
    a = s-b;
    if(a<0 || b<0 || a-b!=r) cout << "impossible" << endl;
    else cout << a << " " << b << endl;
  }
}
