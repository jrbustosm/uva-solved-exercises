/* 

Calculating Yuan Fen

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

#define MAX 10000

using namespace std;

int yuanfen(string s, int st);
int yuanfen(int* v, int N);
int* t(string s, int st, int &N);

int main(){
  string s;
  while(getline(cin, s)){
    int i=1;
    while(i<=MAX){
      if(yuanfen(s, i)==100) break;
      ++i;
    }
    if(i==MAX+1) cout << ":(" << endl;
    else cout << i << endl;
  }
}

int* t(string s, int st, int &N){
  ostringstream oss;
  for(string::iterator i=s.begin(); i!=s.end(); ++i) oss << (int)((*i)-'A'+st);
  string o = oss.str();
  int* v = new int[o.size()];
  N = o.size();
  for(string::iterator i=o.begin(); i!=o.end(); ++i) v[i-o.begin()] = (*i)-'0';
  return v;
}

int yuanfen(string s, int st){
  int N=0;
  int *v = t(s,st,N);
  return yuanfen(v, N);
}

int yuanfen(int* v, int N){
  while(N>2){
    for(int i=0; i<N-1; ++i) v[i]=(v[i]+v[i+1])%10;
    --N;
    if(N==3 && v[0]==1 && v[1]==0 && v[2]==0) return 100;
  }
  return 0;
}

