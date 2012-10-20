/* 

The Sultan's Successors

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void eightqueens(int m[8][8], vector<int*> &sls, int i);
void marcar(int m[8][8], int i, int j, int c);

int main(){
  //Find 92 solutions
  int m[8][8];
  memset(m, 0, sizeof(int)*8*8);
  vector<int*> sls;
  eightqueens(m, sls, 0);
  int k;
  cin >> k;
  for(int w=0; w<k; ++w){
    int c[8][8];
    for(int i=0; i<8; ++i){
      for(int j=0; j<8; ++j){
        cin >> c[i][j];
      }
    }
    int max = 0;
    for(vector<int*>::iterator it = sls.begin(); it!=sls.end(); ++it){
      int* s = *it;
      int p = 0;
      for(int k=0; k<16; k+=2){
        p += c[s[k]][s[k+1]];
      }
      if(p>max) max=p;
    }
    cout.width(5);
    cout.fill(' ');
    cout << max << endl;
  }
}

int di[] = {-1,-1,-1,0,0,1,1,1};
int dj[] = {-1,0,1,-1,1,-1,0,1};

void eightqueens(int m[8][8], vector<int*> &sls, int i){
  if(i==8){
    int* ns = new int[16];
    int k = 0;
    for(int i=0; i<8; ++i){
      for(int j=0; j<8; ++j){
        if(m[i][j]==1){
          ns[k] = i;
          ns[k+1] = j;
          k += 2;
        }
      }
    }
    sls.push_back(ns);
    return;
  }
  for(int j=0; j<8; ++j){
    if(m[i][j] == 0){
      marcar(m, i, j, 1);
      eightqueens(m, sls, i+1);
      marcar(m, i, j, -1);
    }
  }
}

void marcar(int m[8][8], int i, int j, int c){
  m[i][j] += c;
  for(int k=0; k<8; ++k){
    int ni = i+di[k];
    int nj = j+dj[k];
    while(ni>=0 && nj>=0 && ni<8 && nj<8){
      m[ni][nj] += c;
      ni += di[k];
      nj += dj[k];
    }
  }
}

