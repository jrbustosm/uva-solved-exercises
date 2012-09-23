/* 

The Collatz Sequence

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

long long collatz(long long n);

int main(){
  long long A, max;
  int cont = 1;
  cin >> A >> max;
  while(A>=0 && max>=0){
    long long original = A;
    long c=1;
    while(A!=1){
      A = collatz(A);
      if(A>max){
        break;
      }
      ++c;
    }
    cout << "Case " << cont << ": A = " << original << ", limit = " << max << ", number of terms = " << c << endl;
    cin >> A >> max;
    ++cont;
  }
  return 0;
}

long long collatz(long long n){
  if(n & 1) return 3*n+1;
  else return n/2;
}
