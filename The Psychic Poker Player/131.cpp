/* 

The Psychic Poker Player

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool straightflush(vector<string> &v);
bool straight(vector<string> &v);
bool fourofakind(vector<string> &v);
bool fullhouse(vector<string> &v);
bool flush(vector<string> &v);
bool threeofakind(vector<string> &v);
bool twopairs(vector<string> &v);
bool onepair(vector<string> &v);
int bestHand(vector<string> &v);
int bestHand(vector<string> &u, vector<string> &v);
void comb(vector<string> &v, vector<string> u, int k, map<string, bool> &cs);

char suit[] = {'C','D','H','S'};
string hands[] = {"straight-flush", "four-of-a-kind", "full-house", 
                  "flush", "straight", "three-of-a-kind", 
                  "two-pairs", "one-pair", "highest-card"};

int main(){
  string line;
  while(getline(cin, line)){
    istringstream iss(line);
    vector<string> u;
    vector<string> v;
    string token;
    while(iss >> token){
      if(token[0]=='T') token[0] = ':';
      if(token[0]=='J') token[0] = ';';
      if(token[0]=='Q') token[0] = '<';
      if(token[0]=='K') token[0] = '=';
      if(token[0]=='A') token[0] = '>';
      if(u.size()<5) u.push_back(token);
      else v.push_back(token);
    }
    cout << "Hand: " << line.substr(0,14) << " Deck: " << line.substr(15,14) << " Best hand: ";
    cout << hands[bestHand(u, v)];
    cout << endl;
  }
}

void comb(vector<string> &v, vector<string> u, int k, map<string, bool> &cs){
  if(u.size() == k){
    sort(u.begin(), u.end());
    ostringstream oss;
    for(int j=0; j<k; ++j){
      if(j>0) oss << " ";
      oss << u[j];
    }
    cs[oss.str()] = true;
    return;
  }
  for(int i=0; i<v.size(); ++i){
    string s = v[i];
    v.erase(v.begin()+i);
    u.push_back(s);
    comb(v, u, k, cs);
    u.erase(u.end()-1);
    v.insert(v.begin()+i, s);
  }
}

int bestHand(vector<string> &u, vector<string> &v){
  int min = 8;
  for(int i=0; i<=5; ++i){
    map<string, bool> csu;
    comb(u,*(new vector<string>()), i, csu);
    for(map<string,bool>::iterator itu=csu.begin(); itu!=csu.end(); ++itu){
      istringstream iss((*itu).first);
      vector<string> nv;
      string token;
      while(iss >> token) nv.push_back(token);
      for(int j=0; j<5-i; ++j) nv.push_back(v[j]);
      sort(nv.begin(), nv.end());
      int r = bestHand(nv);
      if(r<min){
        min=r;
        if(min==0) return 0;
      }
    }
  }
  return min;
}

int bestHand(vector<string> &v){
  if(straightflush(v)) return 0;
  else if(fourofakind(v)) return 1;
  else if(fullhouse(v)) return 2;
  else if(flush(v)) return 3;
  else if(straight(v)) return 4;
  else if(threeofakind(v)) return 5;
  else if(twopairs(v)) return 6;
  else if(onepair(v)) return 7;
  else return 8;
}

bool straightflush(vector<string> &v){
  return straight(v) && flush(v);
}

bool straight(vector<string> &v){
  int c=0;
  if(v[4][0]=='>') c=1; //is As
  for(int i=0; i<5; ++i){
    if(i==0){
      if(c==1 && v[0][0]=='2') c++;
      else c=1;
    }else{
      if(int(v[i][0]-v[i-1][0])==1) c++;
      else return false;
    }
    if(c==5) return true;
  }
  return false;
}

bool fourofakind(vector<string> &v){
  int c=1;
  for(int i=1; i<5; ++i){
    if(v[i][0] == v[i-1][0]) ++c;
    else c = 1;
    if(c==4) return true;
  }
  return false;
}

bool threeofakind(vector<string> &v){
  int c=1;
  for(int i=1; i<5; ++i){
    if(v[i][0] == v[i-1][0]) ++c;
    else c = 1;
    if(c==3) return true;
  }
  return false;
}

bool onepair(vector<string> &v){
  int c=1;
  for(int i=1; i<5; ++i){
    if(v[i][0] == v[i-1][0]) ++c;
    else c = 1;
    if(c==2) return true;
  }
  return false;
}

bool twopairs(vector<string> &v){
  char fp='\0', fp2='\0';
  int c=1;
  for(int i=1; i<5; ++i){
    if(v[i][0] == v[i-1][0]) ++c;
    else c = 1;
    if(c==2 && fp=='\0') fp=v[i][0];
    else if(c==2) fp2=v[i][0];
    if(fp2!='\0' && fp!='\0') return true;
  }
  return false;
}

bool fullhouse(vector<string> &v){
  char fp='\0', ft='\0';
  int c=1;
  for(int i=1; i<5; ++i){
    if(v[i][0] == v[i-1][0]) ++c;
    else c = 1;
    if(c==2 && fp=='\0') fp=v[i][0];
    else if(c==3){
      ft=v[i][0];
      if(fp==ft) fp='\0';
    }
    if(ft!='\0' && fp!='\0') return true;
  }
  return false;
}

bool flush(vector<string> &v){
  for(int i=1; i<5; ++i){
    if(v[i][1] != v[i-1][1]) return false;
  }
  return true;
}

