/* 

Factoring Large Numbers

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

bool criba[1000001];

int main(){
  vector<int> lp;
  memset(criba, true, sizeof(bool)*1000001);
  for(int i=2; i<1000001; ++i){
    if(!criba[i]) continue;
    lp.push_back(i);
    for(int j=i*2; j<1000001; j+=i) criba[j]=false;
  }
  long long int n;
  cin >> n;
  while(n!=-1){
    stack<int> ds;
    for(vector<int>::iterator it=lp.end()-1; it>=lp.begin() && n!=1; --it){
      int p = *it;
      while(n%p==0 && n!=1){
        ds.push(p);
        n = n/p;
      }
    }
    while(!ds.empty()){
      cout << "    " << ds.top() << endl;
      ds.pop();
    }
    if(n!=1) cout << "    " << n << endl;
    cout << endl;
    cin >> n;
  }
}

