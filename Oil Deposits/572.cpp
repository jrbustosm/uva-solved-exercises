/* 

Oil Deposits

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int df[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

int deposits(char** m, int fs, int cs);
void mark(char** m, int f, int c, int fs, int cs);
 
int main(){
  int m, n;
  cin >> m >> n;
  while(!(m==0 || n==0)){
    char** map = new char*[m];
    for(int i=0; i<m; ++i){
      map[i] = new char[n];
      for(int j=0; j<n; ++j){
        cin >> map[i][j];
      }
    }
    cout << deposits(map, m, n) << endl;
    delete[] map;
    cin >> m >> n;
  }
}

int deposits(char** m, int fs, int cs){
  int c = 0;
  for(int i=0; i<fs; ++i){
    for(int j=0; j<cs; ++j){
      if(m[i][j]=='@'){
        ++c;
        mark(m, i, j, fs, cs);
      }
    }
  }
  return c;
}

void mark(char** m, int f, int c, int fs, int cs){
  if(f<0 || c<0 || f>=fs || c>=cs) return;
  if(m[f][c] != '@') return;
  m[f][c] = 'X';
  for(int k=0; k<8; ++k) mark(m, f+df[k], c+dc[k], fs, cs);
}

