/* 

Maximum Product

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int v[18];

int main(){
  int N, T=1;
  while(cin >> N){
    long int max = 0;
    for(int i=0; i<N; ++i) cin >> v[i];
    for(int i=0; i<N; ++i){
      long int P = 1;
      for(int j=i; j<N; ++j){
        P*=v[j];
        if(P>max) max=P;
      }
    }
    cout << "Case #" << T++ << ": The maximum product is " << max << "." << endl << endl;
  }
}
