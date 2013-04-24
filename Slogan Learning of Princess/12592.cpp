/* 

Slogan Learning of Princess

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

int main(){
  map<string, string> m;
  int N;
  cin >> N;
  cin.get();
  for(int i=0; i<N; ++i){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    m[s1]=s2;
  }
  int Q;
  cin >> Q;
  cin.get();
  for(int i=0; i<Q; ++i){
    string q;
    getline(cin, q);
    cout << m[q] << endl;
  }
}

