/*

Undraw the Trees

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct tuple{
  int first;
  int second;
  tuple(int _f, int _s){
    first = _f;
    second = _s;
  }
};

struct TreeNode {

  char val;
  vector< TreeNode* > children;
  
  TreeNode(char val){
    this->val = val;
  }

  void add(TreeNode *n){
    children.push_back(n);
  }

  bool isLeaf(){
    return children.empty();
  }

  string toString(){
    return "(" + toString(this) + ")";
  }

  string toString(TreeNode *n){
    ostringstream oss;
    oss << n->val;
    if(n->isLeaf()){
      oss << "()";
      return oss.str();
    }
    oss << "(";
    for(vector<TreeNode*>::iterator it=n->children.begin(); it != n->children.end(); ++it) oss << toString(*it);
    oss << ")";
    return oss.str();
  }

};

ostream &operator<<(ostream &out, TreeNode* n){
  out << n->toString();
  return out;
}

int main(){
  int T;
  cin >> T;
  cin.get();
  for(int t=0; t<T; ++t){
    TreeNode* root = NULL;
    string snodes;
    getline(cin,snodes);
    if(snodes != "#"){
      map<string, TreeNode*> mnodes;
      istringstream iss(snodes);
      char c;
      while(iss >> c) if(c!='#' && c!='-' && c!='|') break;
      root = new TreeNode(c);
      ostringstream oss;
      int row = 0;
      oss << c << "-" << row << "-" << snodes.find(c);
      mnodes[oss.str()] = root;
      while(true){
        string sparents, sbraces;
        map<string, tuple*> mbraces;
        getline(cin,sparents);
        if(sparents == "#") break;
        getline(cin,sbraces);
        int p = sparents.find("|");
        while(p!=-1){
          
          int l = p;
          while(l>=0 && sbraces[l]=='-') --l;
          ++l;

          int r = p;
          while(r<sbraces.size() && sbraces[r]=='-') ++r;
          --r;
          
          oss.str("");
          oss << snodes[p] << "-" << row << "-" << p;
          mbraces[oss.str()] = new tuple(l, r);

          p = sparents.find("|", p+1);
        }
        getline(cin,snodes); 
        iss.clear();
        iss.str(snodes);
        ++row;
        p = -1;
        while(iss >> c){
          if(c=='#' || c=='-' || c=='|') continue;
          p = snodes.find(c, p+1);
          for(map<string, tuple*>::iterator it=mbraces.begin() ; it != mbraces.end(); ++it){
            tuple* t = (*it).second;
            if(p>=(t->first) && p<=(t->second)){
              TreeNode* nn = new TreeNode(c);
              mnodes[(*it).first]->add(nn);
              oss.str("");
              oss << c << "-" << row << "-" << p;
              mnodes[oss.str()] = nn;
            }
          }
        }
      }
    }
    if(root==NULL) cout << "()" << endl;
    else cout << root << endl;
  }
}

