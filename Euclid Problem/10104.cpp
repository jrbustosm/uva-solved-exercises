/* 

Euclid Problem

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

void mcd(int a, int b, vector<int> &r, vector<int> &s, vector<int> &t);

int main(){
  int A, B;
  while(cin >> A >> B){
    vector<int> r, s, t;
    mcd(A, B, r, s, t);
    cout << s[s.size()-2] << " " << t[t.size()-2] << " " << r[r.size()-2]  << endl;
  }
}

void mcd(int a, int b, vector<int> &r, vector<int> &s, vector<int> &t){
  r.push_back(a);
  r.push_back(b);
  s.push_back(1);
  s.push_back(0);
  t.push_back(0);
  t.push_back(1);
  int i = 1;
  while(r[i]!=0){
    int q = r[i-1]/r[i];
    r.push_back(r[i-1]%r[i]);
    s.push_back(s[i-1]-q*s[i]);
    t.push_back(t[i-1]-q*t[i]);
    ++i;
  }
}

