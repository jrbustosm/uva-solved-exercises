/* 

ID Codes

Jose Ricardo Bustos Molina

Dijkstra's permutation algorithm

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool next(char* v, int N);

int main(){
  char line[51];
  scanf("%s", line);
  while(line[0] != '#'){
    if(next(line, strlen(line))) cout << line << endl;
    else cout << "No Successor" << endl;
    scanf("%s", line);
  }
}

bool next(char* v, int N){
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

