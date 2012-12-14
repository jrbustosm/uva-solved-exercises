/* 

What's Cryptanalysis?

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

bool ordenar(const pair<char,int> &c1, const pair<char,int> &c2){
  if(c1.second > c2.second) return true;
  if(c1.second == c2.second) return c1.first<c2.first;
  return false;
}

int main(){
  int T;
  cin >> T;
  cin.get();
  map<char, int> m;
  for(char c='A'; c<='Z'; ++c) m[c]=0;
  while(T--){
    string line;
    getline(cin, line);
    transform(line.begin(), line.end(), line.begin(), ::toupper);
    for(string::iterator i=line.begin(); i!=line.end(); ++i)
      if((*i)>='A' && (*i)<='Z') ++m[*i];
  }
  vector<pair<char, int> > v;
  for(map<char,int>::iterator i=m.begin(); i!=m.end(); ++i)
    if((*i).second>0) v.push_back(make_pair((*i).first,(*i).second));
  sort(v.begin(), v.end(), ordenar);
  for(vector<pair<char, int> >::iterator i=v.begin(); i!=v.end(); ++i)
    cout << (*i).first << " " << (*i).second << endl;
}

