/* 

Master-Mind Hints

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N;
  int game = 0;
  cin >> N;
  while(N!=0){
    ++game;
    cout << "Game " << game << ":" << endl;
    vector<int> o(N);
    for(int i=0; i<N; ++i) cin >> o[i];
    while(true){
      vector<int> v(N);
      vector<bool> vf(N);
      for(int i=0; i<N; ++i){
        cin >> v[i];
        vf[i] = true;
      }
      if(v[0]==0) break;
      int fijas = 0, picas = 0; 
      for(int i=0; i<N; ++i){
        if(v[i] == o[i]){
          ++fijas;
          vf[i] = false;
        }else{
          for(int j=0; j<N; ++j){
            if(i==j) continue;
            if(v[i] == o[j] && v[j] != o[j] && vf[j]) {
              //special cases of picas ( ##11 & 1###, ##11 & 11##, ###1 & 11##, ##11, 1#1#)
              ++picas;
              vf[j] = false;
              break;
            }
          }
        }
      }
      cout << "    (" << fijas << "," << picas << ")" << endl;
    }
    cin >> N;
  }
}
