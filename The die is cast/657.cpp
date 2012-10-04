/* 

The die is cast

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findDice(char** &m, vector<int> &v, int w, int h);
int findDie(char** &m, int i, int j, int w, int h);
void deleteDot(char** &m, int i, int j, int w, int h);

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

int main(){
  int w, h, t=1;
  cin >> w >> h;
  while(!(w==0 || h==0)){
    char** m = new char*[h];
    for(int i=0; i<h; ++i) m[i] = new char[w];
    for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) cin >> m[i][j];
    vector<int> v;
    findDice(m, v, w, h);
    sort(v.begin(), v.end());
    cout << "Throw " << t++ << endl;
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
      if(it!=v.begin()) cout << " ";
      cout << (*it);
    }
    cout << endl << endl;
    cin >> w >> h;
  }
}

void findDice(char** &m, vector<int> &v, int w, int h){
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      if(m[i][j]=='*' || m[i][j]=='X'){
        v.push_back(findDie(m, i, j, w, h));
      }
    }
  }
}

int findDie(char** &m, int i, int j, int w, int h){
  if(i<0 || j<0 || i>=h || j>=w) return 0;
  if(m[i][j] == '.') return 0;
  if(m[i][j] == 'X'){
    deleteDot(m, i, j, w, h);
    return 1 + findDie(m, i, j, w, h);
  }
  m[i][j] = '.';
  int c = 0;
  for(int k=0; k<4; ++k) c+=findDie(m, i+di[k], j+dj[k], w, h);
  return c;
}

void deleteDot(char** &m, int i, int j, int w, int h){
  if(i<0 || j<0 || i>=h || j>=w) return;
  if(m[i][j] == '.' || m[i][j] =='*') return;
  m[i][j] = '*';
  for(int k=0; k<4; ++k) deleteDot(m, i+di[k], j+dj[k], w, h);
}

