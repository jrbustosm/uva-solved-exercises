/* 

Hours and Minutes

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int a;
  while(cin >> a){
    bool f = false;
    for(int h=0; h<=11 && !f; ++h){
      for(int m=0; m<=59 && !f; ++m){
        int am = m*360.0/60.0;
        int ah = h*360.0/12.0;
        int da = abs(am-ah);
        da = da<180?da:360-da;
        if(da == a) f = true;
      }
    }
    cout << (f?"Y":"N") << endl;
  }
}

