/* 

Robot Instructions

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

void exec(int &x, int k);

string vi[100];
int vm[100];

int main(){
  int T;
  cin >> T;
  while(T--){
    int x = 0;
    int n;
    cin >> n;
    for(int k=0; k<n; ++k){
      string i;
      cin >> i;
      vi[k] = i;
      if(i=="SAME"){
        cin >> i; //garbage
        int m;
        cin >> m;
        vm[k] = m-1;
      }
      exec(x, k);
    }
    cout << x << endl;
  }
}

void exec(int &x, int k){
  if(vi[k]=="LEFT") --x;
  else if(vi[k]=="RIGHT") ++x;
  else exec(x, vm[k]);
}

