/* 

Slash Maze

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

using namespace std;

struct tuple{
  int max;
  int N;
  tuple(int _max, int _N){
    max = _max;
    N = _N;
  }
};

void maxcycle(bool** mb, tuple* r, int w, int h);
bool findcycle(bool** mb, int w, int h, int i, int j, int& s);

int main(){
  int w, h, maze=1;
  cin >> w >> h;
  cin.get();
  while(!(w==0 && h==0)){
    if(w==0 || h==0){
      cout << "Maze #" << maze++ << ":" << endl;
      cout << "There are no cycles." << endl;
      cout << endl;
      cin >> w >> h;
      continue;  
    }
    bool** mb = new bool*[h*3];
    for(int i=0; i<h; ++i){
      for(int k=0; k<3; ++k){
        mb[i*3+k] = new bool[w*3];
        memset(mb[i*3+k], false, sizeof(bool)*w*3);
      }
      for(int j=0; j<w; ++j){
        char c;
        cin >> c;
        if(c=='\\'){
          mb[i*3][j*3] = true;
          mb[i*3+1][j*3+1] = true;
          mb[i*3+2][j*3+2] = true;
        }else{ // character '/'
          mb[i*3][j*3+2] = true;
          mb[i*3+1][j*3+1] = true;
          mb[i*3+2][j*3] = true;
        }
      }
    }
    cout << "Maze #" << maze++ << ":" << endl;
    tuple* t = new tuple(0,0);
    maxcycle(mb, t, w*3, h*3);
    if(t->N > 0) cout << t->N << " Cycles; the longest has length " << (t->max/3) << "." << endl;
    else cout << "There are no cycles." << endl;
    cout << endl;
    cin >> w >> h;
  }
}

void maxcycle(bool** mb, tuple* r, int w, int h){
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      int s=0;
      if(!mb[i][j] && findcycle(mb, w, h, i, j, s)){
        ++r->N;
        if(s > r->max) r->max = s;
      }
    }
  }
}

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

bool findcycle(bool** mb, int w, int h, int i, int j, int& s){
  if(i<0 || j<0 || i>=h || j>=w) return false;
  if(mb[i][j]) return true;
  mb[i][j] = true;
  ++s;
  bool f = true;
  for(int k=0; k<4; ++k) f &= findcycle(mb, w, h, i+di[k], j+dj[k], s);
  return f;
}

