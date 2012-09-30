/* 

The Other Two Trees

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  long double x1, y1, x2, y2;
  cout.precision(10);
  cout.setf(ios::fixed,ios::floatfield);
  while(cin >> x1 >> y1 >> x2 >> y2){
    long double xm = (x2+x1)/2;
    long double ym = (y2+y1)/2;
    long double dx = xm-x1;
    long double dy = ym-y1;
    long double x3 = xm - dy;
    long double y3 = ym + dx;
    long double x4 = xm + dy;
    long double y4 = ym - dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  }
}

