/* 

Marvelous Mazes

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  char c;
  int s = 0;
  while(cin.get(c)){
    if(c>='0' && c<='9') s+=(int)(c-'0');
    else if (c=='!' || c=='\n') cout << endl;
    else{
      for(int i=0; i<s; ++i) cout << (c=='b'?' ':c);
      s=0;
    }
  }
  return 0;
}
