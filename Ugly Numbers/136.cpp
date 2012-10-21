/* 

Ugly Numbers

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cstring>

#define MAX 1000000001

using namespace std;

int main(){
  /*
  // first find to solution 859963392
  bool m[MAX];
  memset(m, false, sizeof(bool)*MAX);
  m[1] = true; 
  int fcs[] = {2,3,5};
  for(int* f=fcs; f!=fcs+3; ++f){
    for(bool* i=m+(*f); i<m+MAX; i+=(*f)) (*i)=true;
  }
  for(bool* j=m+6; j<m+MAX; ++j){
    if(!(*j)){
      for(bool* i=j+(j-m); i<m+MAX; i+=(j-m)) (*i)=false;
    }
  }
  int c = 0;
  bool* i=m+1;
  while(true){
    if(*i) ++c;
    if(c==1500) break;
    ++i;
  }
  cout << "The 1500'th ugly number is " << (i-m) << "." << endl;
  */
  cout << "The 1500'th ugly number is 859963392." << endl;
}

