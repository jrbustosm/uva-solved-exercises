/* 

Generating Fast, Sorted Permutation

Jose Ricardo Bustos Molina

Dijkstra's permutation algorithm

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

bool next(string &v, int N);

int main(){
  int N;
  cin >> N;
  cin.get();
  ostringstream oss;
  for(int n=0; n<N; ++n){
    char cline[11];
    scanf("%s", cline);
    string line(cline);
    sort(line.begin(), line.end());
    oss << line << endl;
    while(next(line, line.size())) oss << line << endl;
    oss << endl;
  }
  cout << oss.str();
}

bool next(string &v, int N){
  int i=N-1;
  int j=N;
  while(v[i-1]>=v[i]) --i;
  while(v[j-1]<=v[i-1]) --j;
  if(i==0 && j==N) return false;
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

