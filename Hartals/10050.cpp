/* 

Hartals

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=0; t<T; ++t){
    int N, P;
    cin >> N >> P;
    map<int, bool> m;
    for(int p=0; p<P; ++p){
      int hi;
      cin >> hi;
      for(int day=hi; day<=N; day+=hi){
        if(!((day+1)%7==0 || day%7==0)){
          m[day] = true;
        }
      }
    }
    cout << m.size() << endl;
  }
}
