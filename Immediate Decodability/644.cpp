/* 

Immediate Decodability

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool decodability(vector<string> &v);

int main(){
  string line;
  vector<string> v;
  int set = 1;
  while(getline(cin, line)){
    if(line == "9"){
      cout << "Set " << set++ << " is";
      if(!decodability(v)) cout << " not";
      cout << " immediately decodable" << endl;
      v.clear();
      continue;
    }
    v.push_back(line);
  }
}

bool decodability(vector<string> &v){
  for(vector<string>::iterator it=v.begin(); it!=v.end(); ++it){
    for(vector<string>::iterator it2=v.begin(); it2!=v.end(); ++it2){
      if(it == it2) continue;
      if((*it).find((*it2))==0) return false;
    }
  }
  return true;
}

