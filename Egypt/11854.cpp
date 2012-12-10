/* 

Egypt

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  double h, a, b;
  cin >> h >> a >> b;
  while(!(h==0 && a==0 && b==0)){
    if(a>h) swap(a, h);
    if(b>h) swap(b, h);
    cout << (h == sqrt(a*a+b*b)?"right":"wrong") << endl;
    cin >> h >> a >> b;
  }
}
