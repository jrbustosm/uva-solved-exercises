/* 

The Falling Leaves

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

struct TreeNode {

  int val;
  TreeNode *left;
  TreeNode *right;
  
  TreeNode(int val){
    this->val = val;
    this->left = NULL; 
    this->right = NULL; 
  }

  bool isLeaf(){
    return this->left==NULL && this->right==NULL;
  }
};

void build(TreeNode* n);
void fallingLeaves(TreeNode *n, map<int, int> &m, int offset);

int main(){
  int n;
  int k = 1;
  while(cin >> n && n!=-1){
    cout << "Case " << k++ << ":" << endl;
    TreeNode* root = new TreeNode(n);
    build(root);
    map<int, int> m;
    fallingLeaves(root, m, 0);
    for (map<int,int>::iterator it=m.begin() ; it != m.end(); ++it ){
      if(it != m.begin()) cout << " ";
      cout << (*it).second;
    }
    cout << endl << endl;
  }
}

void fallingLeaves(TreeNode *n, map<int, int> &m, int offset){
  m[offset] += n->val;
  if(n->left != NULL) fallingLeaves(n->left, m, offset-1);   
  if(n->right != NULL) fallingLeaves(n->right, m, offset+1);   
}

void build(TreeNode* n){
  int l, r;
  cin >> l;
  if(l!=-1){
    n->left = new TreeNode(l);
    build(n->left);
  }
  cin >> r;
  if(r!=-1){
    n->right = new TreeNode(r);
    build(n->right);
  }
}

