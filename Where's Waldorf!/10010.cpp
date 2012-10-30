/* 

Where's Waldorf? 

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

struct tuple{
  int f;
  int c;
  tuple(): f(-1), c(-1){}
  tuple(int _f, int _c){
    f = _f;
    c = _c;
  }
  bool isnull(){
    return f==-1;
  }
};

int dfs[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dcs[] = {-1, 0, 1, -1, 1, -1, 0, 1};

tuple find(string &s, vector<string> &m, int n, int f, int c, int df, int dc, int fils, int cols);
tuple find(string &s, vector<string> &m, int f, int c, int fils, int cols);
tuple find(string &s, vector<string> &m, int fils, int cols);

int main(){
  int cases;
  cin >> cases;
  for(int i=0; i<cases; ++i){
    if(i!=0) cout << endl;
    int fils, cols;
    cin >> fils >> cols;
    cin.get();
    vector<string> m(fils);
    for(int f=0; f<fils; ++f){
      getline(cin, m[f]);
    }
    int nws;
    cin >> nws;
    cin.get();
    for(int w=0; w<nws; ++w){
      string s;
      getline(cin, s);
      tuple t = find(s,m,fils,cols);
      cout << t.f +1 << " " << t.c + 1 << endl;
    }
  }
}

tuple find(string &s, vector<string> &m, int n, int f, int c, int df, int dc, int fils, int cols){
  if(n==s.size()) return tuple(f,c);
  int nf = f+df*n;
  int nc = c+dc*n;
  if(nf<0 || nc<0 || nf >= fils || nc >= cols) return tuple();
  if(toupper(m[nf][nc]) != toupper(s[n])) return tuple();
  return find(s, m, n+1, f, c, df, dc, fils, cols);
}

tuple find(string &s, vector<string> &m, int f, int c, int fils, int cols){
  tuple t;
  for(int i=0; i<8; ++i){
    t = find(s,m,0,f,c,dfs[i],dcs[i],fils,cols);
    if(!t.isnull()) break;
  }
  return t;
}

tuple find(string &s, vector<string> &m, int fils, int cols){
  tuple t;
  for(int f=0; f<fils; ++f){
    for(int c=0; c<cols; ++c){
      if(toupper(s[0]) == toupper(m[f][c])){
        t = find(s,m,f,c,fils,cols);
        if(!t.isnull()) break;
      }
    }
    if(!t.isnull()) break;
  }
  return t;
}

