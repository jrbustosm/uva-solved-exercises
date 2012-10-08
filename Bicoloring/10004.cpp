/* 

Bicoloring

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

struct node{
  int val;
  vector<node*> v;
  node(){
    val = -1;
  }
};

bool isBicoloring(vector<node*> v, int d);

int main(){
  int n;
  cin >> n;
  while(n>0){
    vector<node*> ns;
    for(int i=0; i<n; ++i) ns.push_back(new node());
    int a;
    cin >> a;
    for(int i=0; i<a; ++i){
      int u, v;
      cin >> u >> v;
      ns[u]->v.push_back(ns[v]);
      ns[v]->v.push_back(ns[u]);
    }
    vector<node*> vi;
    vi.push_back(ns[0]);
    if(isBicoloring(vi, 0)) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
    cin >> n;
  }
}

bool isBicoloring(vector<node*> v, int d){
  if(v.empty()) return true;
  vector<node*> nv;
  for(vector<node*>::iterator it=v.begin(); it!=v.end(); ++it){
    if((*it)->val == -1){
      (*it)->val = d;
      for(vector<node*>::iterator it2=(*it)->v.begin(); it2!=(*it)->v.end(); ++it2) nv.push_back(*it2);
    }else if((*it)->val != d) return false;
  }
  return isBicoloring(nv, (d==0)?1:0);
}

