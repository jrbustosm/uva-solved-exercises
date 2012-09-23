/* 

Searching for Nessy

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0; i<cases; ++i){
    int fils, cols;
    cin >> fils >> cols;
    int N = (fils/3) * (cols/3);
    cout << N << endl;
  }
  return 0;
}
