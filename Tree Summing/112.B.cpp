/* 

Tree Summing

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

using namespace std;

bool build(bool &f, int N, int sum, bool first);

int main(){
  int N;
  while(cin >> N){
    bool f = false;
    build(f, N, 0, true);
    cout << (f?"yes":"no") << endl;
  }
}

bool build(bool &f, int N, int sum, bool first){
  char c;
  if(first) cin >> c; // reading character '('
  cin >> c;
  if(c==')'){
    cin >> c; // reading character '(' or ')'
    return true;
  }
  ostringstream oss; // reading a number
  while(c!='('){
    oss << c;
    cin >> c;
  }
  istringstream iss(oss.str());
  int v;
  iss >> v;
  bool leaf = build(f, N, sum+v, false);
  leaf &= build(f, N, sum+v, false);
  if(leaf) f |= (N==sum+v);
  if(!first) cin >> c; // reading character ')'
  return false;
}

