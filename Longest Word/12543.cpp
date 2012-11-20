/* 

ID Codes

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool isC(char c);

int main(){
  string max = "";
  ostringstream oss;
  char c;
  while(cin >> noskipws >> c){
    if(isC(c)){
      oss << c; 
    }else{
      string w = oss.str();
      oss.str("");
      if(w.size() > max.size()) max = w;
      if(w=="E-N-D"){
        transform(max.begin(), max.end(), max.begin(), ::tolower);
        cout << max << endl;
        max = "";
      }
    }
  }
  transform(max.begin(), max.end(), max.begin(), ::tolower);
  cout << max;
}

bool isC(char c){
  return c>='a' && c<='z' || c>='A' && c<='Z' || c=='-';
}
