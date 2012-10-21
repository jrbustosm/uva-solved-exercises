/* 

Bandwidth

Jose Ricardo Bustos Molina

Dijkstra's permutation algorithm

*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct node{
  char c;
  map<char,bool> v;
  node(char _c){
    c = _c;
  }
};

bool next(char* v, int N);
int bandwidth(char* v, map<char, node*> &g, int min);

int main(){
  char line[101];
  scanf("%s", line);
  while(line[0] != '#'){
    map<char, node*> g;
    istringstream iss(line);
    string snode;
    while(getline(iss, snode, ';')){
      if(g.find(snode[0]) == g.end()) g[snode[0]] = new node(snode[0]);
      for(int i=2; i<snode.size(); ++i){
        if(g.find(snode[i]) == g.end()) g[snode[i]] = new node(snode[i]);
        g[snode[0]]->v[snode[i]] = true;
        g[snode[i]]->v[snode[0]] = true;
      }
    }
    int min = INT_MAX;
    char* v = new char[g.size()];
    char* vmin = new char[g.size()];
    int i=0;
    for(map<char,node*>::iterator it=g.begin(); it!=g.end(); ++it) v[i++] = (*it).first;
    sort(v, v+g.size());
    do{
      int bw = bandwidth(v, g, min);
      if(bw<min){
        min = bw;
        copy(v, v+g.size(), vmin);
      }
    }while(next(v, g.size()));
    for(i=0; i<g.size(); ++i) cout << vmin[i] << " ";
    cout << "-> " << min << endl;
    scanf("%s", line);
  }
}

int bandwidth(char* v, map<char, node*> &g, int min){
  int bw = 0;
  for(int i=0; i<g.size(); ++i){
    int max = 0;
    for(map<char,bool>::iterator it=g[v[i]]->v.begin(); it!=g[v[i]]->v.end(); ++it){
      char c = (*it).first;
      int p = int(abs((strchr(v, c)-v)-i));
      if(p>max) max=p;
    }
    if(max > bw){
      bw=max;
      if(max>min) return max; //optimization ;)
    }
  }
  return bw;
}

bool next(char* v, int N){
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

