/* 

Big Chocolate

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int M, N;
  while(cin >> M >> N){
    if(M > N) swap(M, N);
    cout << (M-1) + (N-1)*M << endl; 
  }
}

