/* 

Knight Moves

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct pos{
  int i;
  int j;
  pos(string &s){
    i = int(s[0] - 97);
    j = int(s[1] - 49);
  }
  pos(int _i, int _j){
    i = _i;
    j = _j;
  }

  bool isSame(pos* p){
    return i == p->i && j == p->j;
  }
};

int findMin(vector<pos*> p, pos* end, bool m[8][8]);

int main(){
  string start, end;
  while(cin >> start >> end){
    bool board[8][8];
    memset(board, false, sizeof(bool)*8*8);
    vector<pos*> p;
    pos* pstart = new pos(start);
    board[pstart->i][pstart->j] = true;
    p.push_back(pstart);
    int m = findMin(p, new pos(end), board);
    cout << "To get from " << start << " to " << end << " takes " << m << " knight moves." << endl;
  }
}

int di[] = {-2,-2,-1,-1,1,1,2,2};
int dj[] = {-1,1,-2,2,-2,2,-1,1};

int findMin(vector<pos*> p, pos* end, bool m[8][8]){
  vector<pos*> np;
  for(vector<pos*>::iterator it=p.begin(); it!=p.end(); ++it){
    if((*it)->isSame(end)) return 0;
    for(int k=0; k<8; ++k){
      int ni = (*it)->i + di[k];
      int nj = (*it)->j + dj[k];
      if(ni>=0 && nj>=0 && ni<8 && nj<8 && !m[ni][nj]){
        m[ni][nj] = true;
        np.push_back(new pos(ni, nj));
      }
    }
  }
  return 1 + findMin(np, end, m);
}

