/* 

Febrary 29

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

bool leap(int a);

int main(){
  string vms[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  map<string, int> ms;
  for(string* m=vms; m<vms+12; ++m) ms[*m]=m-vms;
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    char garbage;
    int d1, m1, a1, d2, m2, a2;
    string sm1, sm2;
    cin >> sm1 >> d1 >> garbage >> a1 >> sm2 >> d2 >> garbage >> a2;
    m1 = ms[sm1];
    m2 = ms[sm2];
    if(leap(a1)){
      if(m1>1) ++a1;
      else --a1;
    }
    if(leap(a2)){
      if(m2>1 || m2==1&&d2==29) ++a2;
      else --a2;
    }
    cout << "Case " << t << ": " << (a2/4-a2/100+a2/400)-(a1/4-a1/100+a1/400)  << endl;
  }
}

bool leap(int a){
  return (a%4==0 && a%100!=0) || a%400==0;
}

