/* 

Birthdates

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  while(cin >> T){
    string max, min;
    int dmin=32, mmin=13, ymin=10000, dmax=-1, mmax=-1, ymax=-1;
    while(T--){
      string name;
      int d, m, y;
      cin >> name >> d >> m >> y;
      if(y < ymin || y==ymin && m<mmin || y==ymin && m==mmin && d<dmin){
        ymin=y;
        mmin=m;
        dmin=d;
        min = name;
      }
      if(y > ymax || y==ymax && m>mmax || y==ymax && m==mmax && d>dmax){
        ymax=y;
        mmax=m;
        dmax=d;
        max = name;
      }
    }
    cout << max << endl << min << endl;
  }
}
