/* 

Pseudo-Random Numbers

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <map>

using namespace std;

int main(){
  int Z, I, M, L, t=1;
  cin >> Z >> I >> M >> L;
  while(!(Z==0 && I==0 && M==0 && L==0)){
    map<int,int> m;
    int c = 0;
    do{
      m[L] = c;
      L = (Z*L+I)%M;
      ++c;
    }while(m.find(L)==m.end());
    cout << "Case " << t++ << ": " << c - m[L] << endl;
    cin >> Z >> I >> M >> L;
  }
}

