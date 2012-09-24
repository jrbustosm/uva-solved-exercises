/* 

ShellSort

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int K;
  cin >> K;
  for(int k=0; k<K; ++k){
    int N;
    cin >> N;
    vector<string> v(N);
    vector<string> o(N);
    cin.get();
    for(int n=0; n<N; ++n) getline(cin,v[n]);
    for(int n=0; n<N; ++n) getline(cin,o[n]);
    int count = 0;
    for(int i=o.size()-1; i>=count; --i){
      while(v[i] != o[i]){
        v.insert(v.begin(), v[i]);
        v.erase(v.begin()+i+1);
        ++count;
        if(i<count) break;
      }
    }
    for(vector<string>::iterator it=o.begin()+count-1; it>=o.begin(); --it) cout << *it << endl;
    cout << endl;
  }
}

