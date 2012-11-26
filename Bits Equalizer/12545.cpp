/* 

Bits Equalizer

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <stack>

using namespace std;

int min(string S, string T);

int main(){
  int N;
  cin >> N;
  for(int k=1; k<=N; ++k){
    string S,T;
    cin >> S >> T;
    cout << "Case " << k << ": " << min(S,T) << endl;
  }
}

int min(string S, string T){
  int c = 0;
  stack<int> p1, p0, pi1, pi0;
  for(int i=0; i<S.size(); ++i){
    if(T[i]=='1' && S[i]=='0') p0.push(i);
    else if(T[i]=='1' && S[i]=='?') pi0.push(i);
    else if(T[i]=='0' && S[i]=='1') p1.push(i);
    else if(T[i]=='0' && S[i]=='?') pi1.push(i);
  }
  while(!p1.empty()){
    if(p0.empty() && pi0.empty()) return -1;
    if(!p0.empty()){
      p0.pop();
      ++c;
    }else{
      pi0.pop();
      c+=2;
    }
    p1.pop();
  }
  return c + p0.size() + pi0.size() + pi1.size();
}

