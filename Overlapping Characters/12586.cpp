/* 

Overlapping Characters

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;
  string cs;
  cin >> cs;
  map<char, char*> mcs;
  int size = 17*43;
  for(int i=0; i<N; ++i){
    char* m = new char[size];
    for(int j=0; j<size; ++j) cin >> m[j];
    mcs[cs[i]] = m;
  }
  for(int i=1; i<=Q; ++i){
    cout << "Query " << i << ": "; 
    string sq;
    cin >> sq;
    char o[size];
    memset(o, '.', sizeof(char)*size);
    map<char, bool> r;
    for(int j=0; j<size; ++j){
      for(int k=0; k<sq.size(); ++k){
        char* aux = mcs[sq[k]];
        if(aux[j]!='.'){
          if(o[j]=='.') o[j] = sq[k];
          else if(o[j]!=sq[k]){
            o[j] = '.';
            break;
          }
        }
      }
      if(o[j]!='.') r[o[j]] = true;
    }
    for(string::iterator c=sq.begin(); c!=sq.end(); ++c) cout << (r.find(*c)!=r.end()?"Y":"N");
    cout << endl;
  }
}
