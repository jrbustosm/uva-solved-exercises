/* 

Decode the tape

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int T(char c, int p);

int main(){
  string line;
  while(getline(cin, line)){
    if(line == "___________") continue;
    int i = 0;
    int p = 0;
    for(int k=9; k>0; --k){
      if(k==6) continue;
      i += T(line[k], p++);
    }
    cout << (char)i;
  }
}

int T(char c, int p){
  return c==' '?0:int(pow(2,p));
}

