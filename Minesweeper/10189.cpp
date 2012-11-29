/* 

Minesweeper

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int di[] = {-1,-1,-1,0,0,1,1,1};
int dj[] = {-1,0,1,-1,1,-1,0,1};

int main(){
  int f, c, t=1;
  char m[100][100];
  cin >> f >> c;
  while(!(f==0 && c==0)){
    if(t>1) cout << endl;
    cout << "Field #" << t++ << ":" << endl;
    for(int i=0; i<f; ++i){
      for(int j=0; j<c; ++j) cin >> m[i][j];
    }
    for(int i=0; i<f; ++i){
      for(int j=0; j<c; ++j){
        if(m[i][j]=='.'){
          int x=0;
          for(int k=0; k<8; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni>=0 && nj>=0 && ni<f && nj<c && m[ni][nj]=='*') ++x;
          }
          cout << (char)(x+'0');
        }else cout << m[i][j];
      }
      cout << endl;
    }
    cin >> f >> c;
  }
}

