/* 

Linear Cellular Automata

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

void print(int* G);

int main(){
  int cases;
  int DNA[10];
  int G[40];
  int T[40];
  cin >> cases;
  for(int c=0; c<cases; ++c){
    if(c!=0) cout << endl;
    for(int i=0; i<10; ++i) cin >> DNA[i]; 
    for(int i=0; i<40; ++i) G[i] = 0;
    G[19] = 1;
    print(G);
    for(int i=0; i<49; ++i){
      T[0] = DNA[G[0] + G[1]];
      T[39] = DNA[G[39] + G[38]];
      for(int j=1; j<39; ++j) T[j] = DNA[G[j-1]+G[j]+G[j+1]];
      for(int j=0; j<40; ++j) G[j] = T[j];
      print(G);
    }
  }
  return 0;
}

void print(int* G){
  for(int i=0; i<40; ++i){
    if(G[i]==0) cout << ' ';
    else if(G[i]==1) cout << '.';
    else if(G[i]==2) cout << 'x';
    else if(G[i]==3) cout << 'W';
  }
  cout << endl;
}
