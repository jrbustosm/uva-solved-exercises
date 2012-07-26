/* 

Excuses, Excuses!

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int contar(string &k, string &w);
bool isletter(string &s, int i);

int main(){
  int nks, nexs;
  int cases = 0;
  while(cin >> nks >> nexs){
    ++cases;
    cout << "Excuse Set #" << cases << endl;
    cin.get();
    vector<string> ks(nks);
    for(int i=0; i<nks; ++i){
      getline(cin, ks[i]);
      transform(ks[i].begin(), ks[i].end(), ks[i].begin(), ::toupper);
    }
    int max = -1;
    vector<string> maxs;
    for(int i=0; i<nexs; ++i){
      string line;
      getline(cin, line);
      string linec = line.substr(0,line.size());
      transform(linec.begin(), linec.end(), linec.begin(), ::toupper);
      int c = 0;
      for(vector<string>::iterator it=ks.begin(); it<ks.end(); ++it){
        c += contar(*it, linec);
      }
      if(c>max){
        max = c;
        maxs.clear();
        maxs.push_back(line);
      }else if(c==max) maxs.push_back(line);
    }
    for(vector<string>::iterator it=maxs.begin(); it<maxs.end(); ++it){
      cout << *it << endl;
    }
    cout << endl;
  }
}

int contar(string &k, string &w){
  int c = 0;
  int p = w.find(k);
  while (p!=-1){
    if(!isletter(w,p-1) && !isletter(w,p+k.size())) ++c;
    p = w.find(k, p+1);
  }
  return c;
}

bool isletter(string &s, int i){
  if (i<0 || i>=s.size()) return false;
  char c = s[i];
  return c>='A' && c<='Z';
}
