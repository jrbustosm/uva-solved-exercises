/* 

Save Setu

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int T;
  while(cin >> T){
    int s = 0;
    while(T--){
      string c;
      cin >> c;
      if(c[0]=='d'){
        int v;
        cin >> v;
        s+=v;
      }else cout << s << endl;
    }
  }
}

