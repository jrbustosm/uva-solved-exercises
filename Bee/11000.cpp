/* 

Bee

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <utility>
#include <map>

using namespace std;

map< int, pair<long int, long int>* > m;

pair<long int, long int> *bee(int N);

int main(){
  m[0] = new pair<long int,long int>(1,0);
  int N;
  cin >> N;
  while(N!=-1){
    pair<long int, long int> *p = bee(N);
    cout << p->second << " " << p->first + p->second << endl;
    cin >> N;
  }
}

pair<long int, long int> *bee(int N){
  if(m.find(N) != m.end()) return m[N];
  pair<long int, long int> *b = bee(N-1);
  pair<long int, long int> *p = new pair<long int,long int>(b->second+1, b->first + b->second);
  m[N]= p; 
  return p;
}
