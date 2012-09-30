/* 

ClockHands

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int h, m;
  char garbage;
  cout.precision(3);
  cout.setf(ios::fixed,ios::floatfield);
  cin >> h >> garbage >> m;
  while(!(h==0 && m==0)){
    double am = double(m)*360.0/60.0;
    double ah = double(h%12)*360.0/12.0+360.0*(double(m)/60.0)/12.0;
    double da = abs(am-ah);
    da = da<180?da:360-da;
    cout << da << endl;
    cin >> h >> garbage >> m;
  }
}

