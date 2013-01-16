/* 

Automatic Answer

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << abs(((n*567/9+7492)*235/47-498)%100/10) << endl;
  }
}
