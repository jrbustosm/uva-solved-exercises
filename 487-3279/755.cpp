/* 

487-3279

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string transformar(string s);

map<char,string> ts;

int main(){
  ts['0'] = "0";
  ts['1'] = "1";
  ts['2'] = "2";
  ts['3'] = "3";
  ts['4'] = "4";
  ts['5'] = "5";
  ts['6'] = "6";
  ts['7'] = "7";
  ts['8'] = "8";
  ts['9'] = "9";
  ts['A'] = "2";
  ts['B'] = "2";
  ts['C'] = "2";
  ts['D'] = "3";
  ts['E'] = "3";
  ts['F'] = "3";
  ts['G'] = "4";
  ts['H'] = "4";
  ts['I'] = "4";
  ts['J'] = "5";
  ts['K'] = "5";
  ts['L'] = "5";
  ts['M'] = "6";
  ts['N'] = "6";
  ts['O'] = "6";
  ts['P'] = "7";
  ts['R'] = "7";
  ts['S'] = "7";
  ts['T'] = "8";
  ts['U'] = "8";
  ts['V'] = "8";
  ts['W'] = "9";
  ts['X'] = "9";
  ts['Y'] = "9";
  int cases;
  cin >> cases;
  for(int c=0; c<cases; ++c){
    if(c!=0) cout << endl;
    int N;
    cin >> N;
    cin.get();
    map<string,int> m;
    for(int i=0; i<N; ++i){
      string line;
      getline(cin, line);
      line = transformar(line);
      if(m.find(line) == m.end()) m[line] = 1;
      else m[line]++;
    }
    int c = 0;
    for(map<string,int>::iterator it=m.begin(); it != m.end(); ++it){
      if((*it).second > 1) {
        cout << (*it).first << " " << (*it).second << endl;
        ++c;
      }
    }
    if(c == 0){
      cout << "No duplicates." << endl;
    }
  }
}

string transformar(string s){
  string o = "";
  int c = 0;
  for(int i=0; i<s.size(); ++i){
    if(ts.find(s[i]) != ts.end()){
      o += ts[s[i]];
      ++c;
      if(c==3) o += '-';
    }
  }
  return o;
}

