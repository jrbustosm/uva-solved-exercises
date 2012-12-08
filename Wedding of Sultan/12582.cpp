/* 

Wedding of Sultan 

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

struct node{
  char k;
  int c;
  node* p;
  node* l;
  node* r;
  node(char _k, node* _p){
    k = _k;
    p = _p;
    l = NULL;
    r = NULL;
    c = 1;
  }
};

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    cout << "Case " << t << endl;
    string s;
    cin >> s;
    map<char, node*> m;
    node* root = new node(s[0], NULL);
    m[s[0]] = root;
    node* actual = root;
    for(string::iterator i=s.begin()+1; i<s.end()-1; ++i){
      if(actual->k == *i){
        actual = actual->p;
        ++actual->c;
      }else{
        if(actual->l == NULL){
          actual->l = new node(*i, actual);
          actual = actual->l;
        }else{
          actual->r = new node(*i, actual);
          actual = actual->r;
        }
        m[actual->k] = actual;
      }
    }
    --root->c;
    for(map<char,node*>::iterator i=m.begin(); i!=m.end(); ++i)
      cout << (*i).first << " = " << (*i).second->c << endl;
  }
}
