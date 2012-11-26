/* 

Ecological Bin Packing

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <climits>

using namespace std;

int main(){
  int p[9];
  string s[6]={"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
  int c[6][6] = {
                 {1, 2, 3, 4, 6, 8},
                 {1, 2, 3, 5, 6, 7},
                 {0, 1, 4, 5, 6, 8},
                 {0, 1, 3, 5, 7, 8},
                 {0, 2, 4, 5, 6, 7},
                 {0, 2, 3, 4, 7, 8}
                };
  while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> p[6] >> p[7] >> p[8]){
    int imin = -1, min = INT_MAX;
    for(int i=0; i<6; ++i){
      int sum = 0;
      for(int j=0; j<6; ++j) sum+=p[c[i][j]];
      if(sum<min){
        min = sum;
        imin = i;
      }
    }
    cout << s[imin] << " " << min << endl;
  }
}

