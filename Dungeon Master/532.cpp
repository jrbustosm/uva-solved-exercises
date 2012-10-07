/* 

Dungeon Master

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

struct pos{
  int z;
  int i;
  int j;
  pos(int _z, int _i, int _j){
    z = _z;
    i = _i;
    j = _j;
  }
};

bool findPath(char*** m, int zs, int is, int js, vector<pos*> &v, int &c);

int main(){
  int is, js, zs;
  cin >> zs >> is >> js;
  while(!(zs==0 && is==0 && js==0)){
    char*** m = new char**[zs];
    vector<pos*> v;
    for(int z=0; z<zs; ++z){
      m[z] = new char*[is];
      for(int i=0; i<is; ++i){
        m[z][i] = new char[js];
        for(int j=0; j<js; ++j){
          cin >> m[z][i][j];
          if(m[z][i][j] == 'S') v.push_back(new pos(z, i, j));
        }
      }
    }
    int min = 0;
    if(findPath(m, zs, is, js, v, min)){
      cout << "Escaped in " << min << " minute(s)." << endl;
    }else{
      cout << "Trapped!" << endl;
    }
    cin >> zs >> is >> js;
  }
}

int dz[] = {0,0,0,0,-1,1};
int di[] = {-1,1,0,0,0,0};
int dj[] = {0,0,-1,1,0,0};

bool findPath(char*** m, int zs, int is, int js, vector<pos*> &v, int &c){
  vector<pos*> nv;
  for(vector<pos*>::iterator it=v.begin(); it!=v.end(); ++it){
    if(m[(*it)->z][(*it)->i][(*it)->j] == 'E') return true;
    for(int k=0; k<8; ++k){
      int nz = (*it)->z + dz[k];
      int ni = (*it)->i + di[k];
      int nj = (*it)->j + dj[k];
      if(nz>=0 && ni>=0 && nj>=0 && nz<zs && ni<is && nj<js && m[nz][ni][nj]!='S' && m[nz][ni][nj]!='#'){
        nv.push_back(new pos(nz, ni, nj));
        if(m[nz][ni][nj]=='.')  m[nz][ni][nj] = 'S';
      }
    }
  }
  if(nv.empty()) return false;
  ++c;
  return findPath(m, zs, is, js, nv, c);
}

