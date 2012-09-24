/* 

Parentheses Balance

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isValid(string& s);

map<char, char> parentheses;

int main(){
  parentheses[')'] = '(';
  parentheses[']'] = '[';
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for(int i=0; i<n; ++i){
    getline(cin, s);
    cout << (isValid(s)?"Yes":"No") << endl;
  }
}

bool isValid(string& s){
  stack<char> p;
  for(string::iterator it=s.begin(); it<s.end(); ++it){
    char c = *it;
    if(parentheses.find(c) == parentheses.end()){
      p.push(c);
    }else{
      if(p.empty()){
        return false;
      }
      char aux = p.top();
      p.pop();
      if(aux != parentheses[c]){
        return false;
      }
    }
  }
  return p.empty();
}
