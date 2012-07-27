/* 

Machined surface

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

using namespace std;

int count(string);

int main(){
  int lines;
  cin >> lines;
  while(lines!=0){
    vector<int> v;
    int min = numeric_limits<int>::max(); 
    string line;
    getline(cin, line);
    for(int i=0; i<lines; ++i){
      getline(cin, line);
      int l = count(line);
      if(l < min) min = l;
      v.push_back(l);
    }
    int s = 0;
    for(vector<int>::iterator it=v.begin(); it < v.end(); ++it){
      s+= *it - min;
    }
    cout << s << endl;
    cin >> lines;
  }
  return 0;
}

int count(string s){
  int c = 0;
  for (string::iterator it=s.begin() ; it < s.end(); ++it){
    if(*it==' ') ++c;
  }
  return c;
}
