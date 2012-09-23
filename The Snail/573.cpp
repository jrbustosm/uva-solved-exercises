/* 

The Snail

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  double H, U, D, F;
  cin >> H >> U >> D >> F;
  while(H!=0){
    int day = 1;
    double h = 0;
    while(true){
      double delta = F*(day-1);
      if(delta > 100) delta = 100;
      h += U*(100.0-delta)/100.0;
      if(h > H){
        cout << "success on day " << day << endl;
        break;
      }
      h -= D;
      if(h < 0){
        cout << "failure on day " << day << endl;
        break;
      }
      ++day;
    }
    cin >> H >> U >> D >> F;
  }
  return 0;
}
