/* 

Searching Quickly

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  map<string, string> ex;         //Exclusion map
  map<string, list<string> > ws;
  string line;
  getline(cin, line);
  while(line!="::"){
    ex[line]=line;
    getline(cin, line);
  }
  while(getline(cin, line)){
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    istringstream iss(line);
    string token;
    map<string, int> tks;
    while(iss >> token){
      if(ex.find(token) != ex.end()) continue; //Excluded if this on the map
      if(ws.find(token) == ws.end()) ws[token] = list<string>(); //add to words map, if no found
      if(tks.find(token) == tks.end()) tks[token] = 1; //count occurrences of the word
      else ++tks[token];
      int pos = -1;
      int ocu = 0;
      //Find position of WORD, to convert
      while(ocu < tks[token]){
        pos = line.find(token, pos+1);
        if(line == token) ++ocu; //word equal to phrase
        else if(pos == 0 && line[token.size()]==' ') ++ocu; //word to begin
        else if(pos == line.size()-token.size() && line[line.size()-token.size()-1]==' ') ++ocu; //word to end
        else if(pos > 0 && pos < line.size()-token.size() && line[pos-1]==' ' && line[pos+token.size()] == ' ') ++ocu; //word to middle
      }
      string aux = line;
      transform(aux.begin()+pos, aux.begin()+pos+token.size(), aux.begin()+pos, ::toupper);
      ws[token].push_back(aux);
    }
  }
  for(map<string, list<string> >::iterator it=ws.begin(); it!=ws.end(); ++it){
    string key = (*it).first;
    list<string> aux = (*it).second;
    for(list<string>::iterator w=aux.begin(); w!=aux.end(); ++w){
      cout << *w << endl;
    }
  }
  return 0;
}
