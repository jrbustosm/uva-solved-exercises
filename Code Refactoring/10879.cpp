/* 

Code Refactoring

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N;
  cin >> N;
  for(int n=1; n<=N; ++n){
    int K, A, B, C, D;
    cin >> K;
    bool f = true;
    for(int i=2; i<=sqrt(K); ++i){
      if(K%i==0){
        if(f){
          A = i;
          B = K/i;
          f = false;
        }else{
          if(i!=A && i!=B){
            C = i;
            D = K/i;
            break;
          }
        }
      }
    }
    cout << "Case #" << n <<": " << K << " = " << A << " * " << B << " = " << C << " * " << D << endl;
  }
}

