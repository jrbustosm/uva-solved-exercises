/* 

Longest Common Subsequence

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int m[1000][1000];

int main(){

  string a, b;
  memset(m, 0, sizeof(int)*1000*1000);
  while(getline(cin,a) && getline(cin,b)){
    int c = 0;
    for(int i=0; i<a.size(); ++i){
      for(int j=0; j<b.size(); ++j){
        if(a[i]==b[j]){
          if(i>0 && j>0){
            if(m[i-1][j-1]==c) m[i][j] = ++c;
            else m[i][j] = m[i-1][j-1]+1;
          }
          else if(i==0){
            if(c==0) m[i][j] = ++c;
            else m[i][j] = m[i][j-1];
          }else{
            if(m[i-1][j]==0){
              m[i][j] = 1;
              if(c==0) c=1;
            }else m[i][j] = m[i-1][j];
          }
        }
        else{
          if(i>0 && j>0) m[i][j] = max(m[i-1][j], m[i][j-1]);
          else if(i==0 && j==0) m[i][j] = 0;
          else if(i==0) m[i][j] = m[i][j-1];
          else m[i][j] = m[i-1][j];
        }
      }
    }
    cout << c << endl;
  }
}

