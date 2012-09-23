/* 

Andy's First Dictionary

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool isletter(char);

int main(){
  string line;
  map<string,int> ws;
  while(getline(cin, line)){
    transform(line.begin(), line.end(), line.begin(), ::tolower);    
    string w = "";
    for(string::iterator it=line.begin(); it<line.end(); ++it){
      if(isletter(*it)) w+=*it;
      else if(w!=""){
        if(ws.find(w) == ws.end()) ws[w] = 1;
        w = "";
      }
    }
    if(w!="" && ws.find(w) == ws.end()) ws[w] = 1;
  }
  for (map<string,int>::iterator it=ws.begin(); it != ws.end(); it++){
    cout << (*it).first << endl;
  }
  return 0;
}

bool isletter(char c){
  return c>='a' && c <='z';
}
