/* 

Firetruck

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cstring>
#include <sstream>

using namespace std;

struct node{
  int v;
  map<int, node*> s;
  node(int _v){
    v = _v;
  }
};

void findPaths(stack<node*> &path, node* last, vector<stack<node*> > &paths, map<int,bool> &f);

int main(){
  int last, T=1;
  ostringstream oss;
  while(cin >> last){
    oss << "CASE " << T++ << ":" << endl;
    map<int, node*> ns;
    int u, v;
    cin >> u >> v;
    map<int, bool> f;
    while(!(u==0 && v==0)){
      if(ns.find(u) == ns.end()){
        ns[u] = new node(u);
        f[u] = false;
      }
      if(ns.find(v) == ns.end()){
        ns[v] = new node(v);
        f[v] = false;
      }
      ns[u]->s[v] = ns[v]; 
      ns[v]->s[u] = ns[u]; 
      cin >> u >> v;
    }
    vector<stack<node*> > paths;
    if(ns.find(1)!=ns.end() && ns.find(last)!=ns.end()){
      stack<node*> initial;
      initial.push(ns[1]);
      findPaths(initial, ns[last], paths, f);
    }
    for(vector<stack<node*> >::iterator it=paths.begin(); it!=paths.end(); ++it){
      stack<node*> s = *it;
      stack<node*> ns;
      while(!s.empty()){
        ns.push(s.top());
        s.pop();
      }
      while(!ns.empty()){
        int d = ns.top()->v;
        ns.pop();
        oss << d;
        if(!ns.empty()) oss << " ";
      }
      oss << endl;
    }
    oss << "There are " << paths.size() << " routes from the firestation to streetcorner " << last << "." << endl;
  }
  cout << oss.str();
}

void findPaths(stack<node*> &path, node* last, vector<stack<node*> > &paths, map<int,bool> &f){
  node* n = path.top();
  if(last->v == n->v){
    paths.push_back(path);
    return;
  }
  if(f[n->v]) return;
  f[n->v] = true;
  for(map<int, node*>::iterator it=n->s.begin(); it!=n->s.end(); ++it){
    path.push((*it).second);
    findPaths(path, last, paths, f);
    path.pop();                     //Backtraking
  }
  f[n->v] = false;           //Backtraking
}

