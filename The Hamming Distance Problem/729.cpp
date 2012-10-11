/* 

The Hamming Distance Problem

Jose Ricardo Bustos Molina

Dijkstra's permutation algorithm

*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

bool next(bool* v, int N);

int main(){
  ostringstream oss;
  int T;
  cin >> T;
  for(int t=0; t<T; ++t){
    int N, H;
    cin >> N >> H;
    bool* line = new bool[N];
    memset(line, false, sizeof(bool)*N);
    for(int i=N-1; i>=N-H; --i) line[i] = true;
    if(t>0) oss << endl;
    for(int i=0; i<N; ++i) oss << line[i];
    oss << endl;
    while(next(line, N)){
      for(int i=0; i<N; ++i) oss << line[i];
      oss << endl;
    }
  }
  cout << oss.str();
}

bool next(bool* v, int N){
  int i=N-1;
  int j=N;
  while(v[i-1]>=v[i]) --i;
  while(v[j-1]<=v[i-1]) --j;
  if(i==0 || j==0) return false;
  swap(v[i-1], v[j-1]);
  ++i;
  j=N;
  while(i<j){
    swap(v[i-1],v[j-1]);
    ++i;
    --j;
  }
  return true;
}

