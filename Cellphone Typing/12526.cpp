/* 

Cellphone Typing

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct node{
  char c;
  int p;
  map<char, node*> m;
  node(char _c){
    c = _c;
    p = 0;
  }
};

int main(){
  int N;
  while(cin >> N){
    node* root = new node('\0');
    stack<string> ws;
    for(int i=0; i<N; ++i){
      string s;
      cin >> s;
      ws.push(s);
      node* actual = root;
      for(string::iterator it=s.begin(); it!=s.end(); ++it){
        if(actual->m.find(*it)==actual->m.end()){
          actual->m[*it] = new node(*it);
        }
        actual = actual->m[*it];
        ++actual->p;
      }
    }
    double sum = 0;
    while(!ws.empty()){
      string s = ws.top();
      ws.pop();
      int c = 1;
      node* actual = root;
      int ant = 0;
      for(string::iterator it=s.begin(); it!=s.end(); ++it){
        actual = actual->m[*it];
        if(ant>actual->p) ++c;
        ant = actual->p;
      }
      sum += c;
    }
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);
    cout << (sum / N) << endl;
  }
}

