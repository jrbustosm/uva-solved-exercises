/* 

Excessive Space Remover

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int f(int max);

int main(){
  string line;
  while(getline(cin, line)){
    int max = 0, c=0;
    for(string::iterator i = line.begin(); i!=line.end(); ++i){
      if(*i == ' '){
        ++c;
        if(c>max) max = c;
      }else c=0;
    }
    cout << f(max) << endl;
  }
}

int f(int max){
  if(max<=1) return 0;
  if(max==2) return 1;
  return 1 + f(max/2+max%2);
}

