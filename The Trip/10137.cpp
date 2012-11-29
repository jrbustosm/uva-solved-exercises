/* 

The Trip

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <iomanip>

using namespace std;

double o(double d);

int main(){
  int n;
  double v[1000];
  cin >> n;
  while(n!=0){
    double s = 0;
    for(int i=0; i<n; ++i){
      cin >> v[i];
      s+=v[i];
    }
    s/=n;
    double c1 = 0;
    double c2 = 0;
    for(int i=0; i<n; ++i){
      double diff = o(v[i]-s);
      if(diff<0) c1-= diff;
      else c2+= diff;
    }
    if(c2>c1) c1=c2;
    cout << "$"  << fixed << setprecision(2) << c1 << endl; 
    cin >> n;
  }
}

double o(double d){
  return (double)(long)(d*100)/100;
}
