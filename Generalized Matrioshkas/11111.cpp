/* 

Generalized Matrioshkas

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

bool isValid(queue<long int>& p);
bool isValid(queue<long int>& p, long int find, long int acum);

int main(){
  string s;
  while(getline(cin, s)){
    queue<long int> p;
    istringstream iss;
    iss.str(s);
    long int token;
    while( iss >> token) p.push(token);
    cout << (isValid(p)?":-) Matrioshka!":":-( Try again.") << endl;
  }
}

bool isValid(queue<long int>& p){
  if(p.empty()) return true;
  long int first = p.front();
  p.pop();
  return isValid(p, first, 0);;
}

bool isValid(queue<long int>& p, long int find, long int acum){
  if(p.empty()) return false;
  long int first = p.front();
  p.pop();
  if(first > 0){
    if(-find <= acum) return false;
    return find == -first;
  }else{
    if(isValid(p, first, 0)){
      return isValid(p, find, acum-first);
    }else{
      return false;
    }
  }
}
