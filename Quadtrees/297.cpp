/* 

Quadtrees

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>

using namespace std;

struct QuadTreeNode {

  bool val;
  QuadTreeNode *first;
  QuadTreeNode *second;
  QuadTreeNode *third;
  QuadTreeNode *fourth;
  
  QuadTreeNode(bool val){
    this->val = val;
    this->first = NULL; 
    this->second = NULL; 
    this->third = NULL;
    this->fourth = NULL;
  }

  bool isLeaf(){
    return this->first==NULL && this->second==NULL && this->third==NULL && this->fourth==NULL;
  }

  string toString(){
    return toString(this);
  }

  string toString(QuadTreeNode* n){
    if(n->isLeaf()) return n->val?"f":"e";
    return "p" + toString(n->first) + toString(n->second) + toString(n->third) + toString(n->fourth);
  }

  int blackPixels(){
    return blackPixels(this, 1024);
  }

  int blackPixels(QuadTreeNode* n, int c){
    if(n->isLeaf()) return n->val?c:0;
    return blackPixels(n->first, c/4) + blackPixels(n->second, c/4) + blackPixels(n->third, c/4) + blackPixels(n->fourth, c/4);
  }
};

ostream &operator<<(ostream &out, QuadTreeNode* n){
  out << n->toString();
  return out;
}

QuadTreeNode* sumar(QuadTreeNode* a, QuadTreeNode* b);
QuadTreeNode* build(string s);
QuadTreeNode* build(string s, int& i);

int main(){
  int N;
  cin >> N;
  for(int i=0; i<N; ++i){
    string streeA, streeB;
    cin >> streeA >> streeB;

    QuadTreeNode* treeA = build(streeA);
    QuadTreeNode* treeB = build(streeB);
    QuadTreeNode* treeC = sumar(treeA, treeB);
    cout << "There are " << treeC->blackPixels() << " black pixels." << endl;
  }
}

QuadTreeNode* build(string s){
  int i = 0;
  return build(s, i);
}

QuadTreeNode* build(string s, int& i){
  if(s[i]=='e' || s[i]=='f') return new QuadTreeNode(s[i]=='f');
  QuadTreeNode* n = new QuadTreeNode(false);
  ++i;
  n->first = build(s, i);
  ++i;
  n->second = build(s, i);
  ++i;
  n->third = build(s, i);
  ++i;
  n->fourth = build(s,i);
  return n;
}

QuadTreeNode* sumar(QuadTreeNode* a, QuadTreeNode* b){
  if(a->isLeaf() && b->isLeaf()) return new QuadTreeNode(a->val || b->val);
  if(a->isLeaf()) return a->val?a:b;
  if(b->isLeaf()) return b->val?b:a;
  QuadTreeNode* n = new QuadTreeNode(false);
  n->first = sumar(a->first, b->first);
  n->second = sumar(a->second, b->second);
  n->third = sumar(a->third, b->third);
  n->fourth = sumar(a->fourth, b->fourth);
  return n;
}

