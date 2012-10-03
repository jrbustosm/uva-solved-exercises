/* 

Automatic Editing

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.get();
  while(n!=0){
    vector<string> keys;
    vector<string> vals;
    for(int i=0; i<n; ++i){
      string k, v;
      getline(cin, k);
      keys.push_back(k);
      getline(cin, v);
      vals.push_back(v);
    }
    string line;
    getline(cin, line);
    for(int i=0; i<keys.size(); ++i){
      int p = line.find(keys[i]);
      while(p!=-1){
        line.replace(line.begin()+p, line.begin()+p+keys[i].size(), vals[i]);
        p = line.find(keys[i]);
      }
    }
    cout << line << endl;
    cin >> n;
    cin.get();
  }
}

