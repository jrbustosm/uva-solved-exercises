/* 

Check The Check

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

bool check(int i, int j, int d);
bool checkKnight(int i, int j, char c);
bool checkPawn(int i, int j, char c);
bool checkPath(int i, int j, char c1, char c2, int* di, int* dj);

char m[8][8];

int diOrtho[] = {-1,1,0,0};
int djOrtho[] = {0,0,-1,1};
int diDiag[] = {-1,-1,1,1};
int djDiag[] = {-1,1,-1,1};
int diKnight[] = {-2,-2,-1,-1,1,1,2,2};
int djKnight[] = {-1,1,-2,2,-2,2,-1,1};

int main(){
  int g = 1;
  while(true){
    int kNi=-1, kNj=-1, kBi=-1, kBj=-1, cB=0;
    for(int i=0; i<8; ++i){
      for(int j=0; j<8; ++j){
        cin >> m[i][j];
        if(m[i][j]=='k'){
          kNi = i;
          kNj = j;
        }else if(m[i][j]=='K'){
          kBi = i;
          kBj = j;
        }else if(m[i][j]=='.') ++cB;
      }
    }
    if(cB==64) break;
    if(kNi!=-1){
      if(check(kNi, kNj, 0)){
        cout << "Game #" << g++ << ": black king is in check." << endl;
        continue;
      }
    }
    if(kBi!=-1){
      if(check(kBi, kBj, 32)){
        cout << "Game #" << g++ << ": white king is in check." << endl;
        continue;
      }
    }
    cout << "Game #" << g++ << ": no king is in check." << endl;
  }
}

bool check(int i, int j, int d){
  return checkKnight(i, j, (char)('N'+d)) ||
         checkPawn(i, j, (char)('P'+d)) ||
         checkPath(i, j, (char)('Q'+d), (char)('R'+d), diOrtho, djOrtho) || 
         checkPath(i, j, (char)('Q'+d), (char)('B'+d), diDiag, djDiag);
}

bool checkKnight(int i, int j, char c){
  for(int k=0; k<8; ++k){
    int ni = i + diKnight[k];
    int nj = j + djKnight[k];
    if(ni>=0 && nj>=0 && ni<8 && nj<8 && m[ni][nj]==c ) return true;
  }
  return false;
}

bool checkPawn(int i, int j, char c){
  if(c=='p' && i>0){
    if(j>0 && m[i-1][j-1]==c) return true; 
    if(j<7 && m[i-1][j+1]==c) return true; 
  }else if(c=='P' && i<7){
    if(j>0 && m[i+1][j-1]==c) return true; 
    if(j<7 && m[i+1][j+1]==c) return true; 
  }
  return false;
}

bool checkPath(int i, int j, char c1, char c2, int* di, int* dj){
  for(int k=0; k<4; ++k){
    int ni = i+di[k];
    int nj = j+dj[k];
    while(ni>=0 && nj>=0 && ni<8 && nj<8){
      if(m[ni][nj]!='.'){
        if(m[ni][nj]==c1 || m[ni][nj]==c2) return true;
        break;
      }
      ni+=di[k];
      nj+=dj[k];
    }
  }
  return false;
}

