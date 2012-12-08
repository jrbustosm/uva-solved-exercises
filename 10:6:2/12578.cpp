/* 

10:6:2 

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int t;
  cin >> t;
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  while(t--){
    double l, r, av;
    cin >> l;
    r = l*2/10;
    av = acos(- 1)*r*r;
    cout << av << " " << l*l*6/10-av << endl;
  }
}
