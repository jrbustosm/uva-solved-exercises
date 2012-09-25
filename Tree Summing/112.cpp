/* 

Tree Summing

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {

  bool flag;
  int val;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  
  TreeNode(int val, TreeNode *parent){
    this->flag = false;
    this->val = val;
    this->parent = parent; 
    this->left = NULL; 
    this->right = NULL; 
  }

  bool isLeaf(){
    return this->left==NULL && this->right==NULL;
  }
};

bool verificar(TreeNode *n, int acum, int v);

int main(){
  int N;
  while(cin >> N){
    int sum = 0;
    string s;
    string aux;
    TreeNode* actual = NULL;
    while(true){
      char c;
      cin >> c;
      if(c=='('){
        ++sum;
        if(aux != ""){
          int value;
          istringstream( aux ) >> value;
          TreeNode* nuevo = new TreeNode(value, actual);
          if(actual != NULL){
            if(actual->flag) actual->right = nuevo;
            else{
              actual->left = nuevo;
              actual->flag = true;
            }
          }
          actual = nuevo;
          aux = "";
        }
      }
      else if(c==')'){
        if(actual != NULL){
          if(s[s.size()-1] != '('){
            if(actual->parent != NULL) actual = actual->parent;
          }else actual->flag = true;
        }
        --sum;
      }
      else aux += c;
      s += c;
      if(sum == 0) break;
    }
    if(actual == NULL) cout << "no" << endl;
    else{
      cout << (verificar(actual,0,N)?"yes":"no") << endl;
    }
  }
  return 0;
}

bool verificar(TreeNode *n, int acum, int v){
  if(n->isLeaf()) return acum+n->val == v;
  bool f = false;
  if(n->left != NULL) f |= verificar(n->left, acum+n->val, v);
  if(!f && n->right != NULL) f |= verificar(n->right, acum+n->val, v);
  return f;
}

