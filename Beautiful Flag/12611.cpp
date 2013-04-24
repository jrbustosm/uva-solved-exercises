/* 

Beautiful Flag

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    cout << "Case " << t << ":" << endl;
    int R;
    cin >> R;
    cout << (-R*45/20) << " " << (R*30/20) << endl;
    cout << (R*55/20) << " " << (R*30/20) << endl;
    cout << (R*55/20) << " " << (-R*30/20) << endl;
    cout << (-R*45/20) << " " << (-R*30/20) << endl;
  }
}

