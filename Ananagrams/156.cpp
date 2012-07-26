/* 

Ananagrams

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool issame(string s1, string s2);

int main(){
  vector<string> ws;
  string w;
  while (w!="#"){
    if(w!=""){
      ws.push_back(w);
    }
    cin >> w;
  }
  vector<bool> wsf(ws.size());
  for(int i=0; i<wsf.size(); ++i) wsf[i] = true; //assume all as ananagrams
  for(int i=0; i<ws.size(); ++i){
    if(!wsf[i]) continue;
    for(int j=0; j<ws.size(); ++j){
      if(i==j || !wsf[j]) continue;
      if(issame(ws[i], ws[j])){ //if two words is equals, then this not is ananagrams
        wsf[i] = false; 
        wsf[j] = false; 
      }
    }
  }
  vector<string> anang;
  for(int i=0; i<wsf.size(); ++i) if(wsf[i]) anang.push_back(ws[i]);
  sort(anang.begin(), anang.end());
  for(vector<string>::iterator w=anang.begin(); w!=anang.end(); ++w) cout << *w << endl;
}

//check if two words have the same letters
bool issame(string s1, string s2){
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  return s1 == s2;
}
