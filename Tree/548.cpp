/* 

Tree

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct tuple{
  int f;
  int s;
  tuple(): f(-1), s(-1){}
  tuple(int _f, int _s){
    f = _f;
    s = _s;
  }
  int first(){
    return f;
  }
  int second(){
    return s;
  }
};

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

tuple* minLeaf(TreeNode *n, int acum);
TreeNode* build(vector<int> &vinorden, vector<int> &vpostorden, map<int, int> &mapIndex, int left, int right, int offset);

int main(){
  string inorden;
  string postorden;
  while(getline(cin, inorden)){
    getline(cin, postorden);
    //Read the tree
    int i;
    istringstream iss(inorden);
    vector<int> vinorden;
    while(iss >> i) vinorden.push_back(i);
    iss.clear();
    iss.str(postorden);
    vector<int> vpostorden;
    while(iss >> i) vpostorden.push_back(i);

    map<int, int> mapIndex;
    for(int k=0; k<vinorden.size(); ++k) mapIndex[vinorden[k]] = k;
    
    TreeNode *n = build(vinorden, vpostorden, mapIndex, 0, vinorden.size()-1, 0);
    //end read
    cout << minLeaf(n,0)->first() << endl;
  }
  return 0;
}

TreeNode* build(vector<int> &vinorden, vector<int> &vpostorden, map<int, int> &mapIndex, int left, int right, int offset){
  if(vinorden.empty()) return NULL;
  if(left>right) return NULL;
  if(left < 0 || right < 0 || left>=vinorden.size() || right>=vinorden.size()) return NULL;
  int val = vpostorden[right];
  TreeNode* node = new TreeNode(val);
  int m = mapIndex[val];
  node->left = build(vinorden, vpostorden, mapIndex, left, m-1-offset, offset);
  node->right = build(vinorden, vpostorden, mapIndex, m-offset, right-1, offset+1);
  return node;
}

tuple* minLeaf(TreeNode *n, int acum){
  int nacum = acum + n->val;
  if(n->isLeaf()){
    return new tuple(n->val, nacum);
  }else{
    tuple* left = NULL;
    tuple* right = NULL;
    if (n->left != NULL) left = minLeaf(n->left, nacum);
    if (n->right != NULL) right = minLeaf(n->right, nacum);
    if (left == NULL) return right;
    if (right == NULL) return left;
    if (left->second() < right->second()) return left;
    else if (left->second() > right->second()) return right;
    else if (left->first() < right->first()) return left;
    else return right;
  }
}

