/* 

What is the Median?

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long n;
  vector<long> v;
  while(cin >> n){
    vector<long>::iterator it = lower_bound(v.begin(), v.end(), n);
    v.insert(it, n);      
    if(v.size()%2==0) cout << (v[v.size()/2]+v[v.size()/2-1])/2 << endl;
    else cout << v[v.size()/2] << endl;
  }
}
