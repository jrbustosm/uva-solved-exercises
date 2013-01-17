/* 

Exact Sum

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>

using namespace std;

int v[10000];

int main(){
  int N;
  while(cin >> N){
    for(int i=0; i<N; ++i) cin >> v[i];
    int M;
    cin >> M;
    int A=-1, B=-1;
    for(int i=0; i<N-1; ++i){
      for(int j=i+1; j<N; ++j){
        if(v[i]+v[j]==M && (A==-1 || abs(v[i]-v[j])<B-A)){
          A = v[i]<v[j]?v[i]:v[j];
          B = v[i]<v[j]?v[j]:v[i];
        }
      }
    }
    cout << "Peter should buy books whose prices are " << A << " and " << B << "." << endl << endl;
  }
}
