/* 

Shortest Names

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct node{
  char v;
  int i;
  map<char, node*> h;
  node(char _v){
    v = _v;
    i = 1;
  }
};

int main(){
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    node* root = new node('\0');
    stack<node*> p;
    for(int i=0; i<n; ++i){
      string s;
      cin >> s;
      node* a = root;
      for(string::iterator c = s.begin(); c!=s.end(); ++c){
        if(a->h.find(*c) == a->h.end()){
          a->h[*c] = new node(*c);
          p.push(a->h[*c]);
        }else (a->h[*c]->i)++;
        a = a->h[*c];
      }
    }
    int k = n;
    while(!p.empty()){
      if(p.top()->i>1) k += p.top()->i;
      p.pop();
    }
    cout << k << endl;
  }
}

