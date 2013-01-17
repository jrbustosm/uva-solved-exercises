/* 

Google is Feeling Lucky

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <queue>

using namespace std;

void clear( queue<string> &q );

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    int max = -1;
    queue<string> q;
    for(int i=0; i<10; ++i){
      string s;
      int N;
      cin >> s >> N;
      if(N>max){
        max = N;
        clear(q);
        q.push(s);
      }else if(N==max) q.push(s);
    }
    cout << "Case #" << t << ":" << endl;
    while(!q.empty()){
      cout << q.front() << endl;
      q.pop();
    }
  }
}

void clear( queue<string> &q ){
  queue<string> empty;
  swap(q, empty );
}
