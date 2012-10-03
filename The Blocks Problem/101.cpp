/* 

The Blocks Problem

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int> > m;
vector<int> pos;

void move_onto(int a, int b);
void move_over(int a, int b);
void pile_onto(int a, int b);
void pile_over(int a, int b);
void remove(int e);

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; ++i){
    stack<int> p;
    p.push(i);
    m.push_back(p);
    pos.push_back(i);
  }
  string cmd;
  cin.get();
  cin >> cmd;
  while(cmd != "quit"){
    int a, b;
    string scmd;
    cin >> a >> scmd >> b;
    if(!(a==b || pos[a] == pos[b])){
      if(cmd=="move" && scmd=="onto") move_onto(a, b);
      else if(cmd=="move" && scmd=="over") move_over(a, b);
      else if(cmd=="pile" && scmd=="onto") pile_onto(a, b);
      else if(cmd=="pile" && scmd=="over") pile_over(a, b);
    }
    cin >> cmd;
  }
  int i=0;
  for(vector<stack<int> >::iterator it=m.begin(); it!=m.end(); ++it){
    cout << i++ <<  ":";
    stack<int> q;
    while(!(*it).empty()){
      q.push((*it).top());
      (*it).pop();
    }
    while(!q.empty()){
      cout << " " << q.top();
      q.pop();
    }
    cout << endl;
  }
}

void move_onto(int a, int b){
  remove(a);
  remove(b);
  move_over(a,b);
}

void move_over(int a, int b){
  remove(a);
  int x = pos[a];
  m[x].pop();
  int y = pos[b];
  m[y].push(a);
  pos[a] = y;
}

void pile_onto(int a, int b){
  remove(b);
  pile_over(a,b);
}

void pile_over(int a, int b){
  int x = pos[a];
  int y = pos[b];
  stack<int> p;
  while(m[x].top() != a){
    p.push(m[x].top());
    m[x].pop();
  }
  p.push(m[x].top());
  m[x].pop();
  while(!p.empty()){
    pos[p.top()] = y;
    m[y].push(p.top());
    p.pop();
  }
}

void remove(int e){
  int x = pos[e];
  while(m[x].top() != e){
    int r = m[x].top();
    m[x].pop();
    m[r].push(r);
    pos[r] = r;
  }
}

