/* 

Zapping

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  while(!(a==-1 && b==-1)){
    int ma = (a>b)?a:b;
    int me = (a<b)?a:b;
    int d1 = ma-me;
    int d2 = 100-ma+me;
    cout << (d1<d2?d1:d2) << endl;
    cin >> a >> b;
  }
}

