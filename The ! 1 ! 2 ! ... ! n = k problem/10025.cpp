/* 

The ? 1 ? 2 ? ... ? n = k problem

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

long int t(long int n);

int main(){
  int N;
  cin >> N;
  while ( N-- ){
    long int in;
    cin >> in;
    cout << t(in) << endl;
    if(N!=0) cout << endl;
  }
  return 0;
}

long int t(long int n){
  if(n==0) return 3;
  if(n<0) n=-n;
  long int d = 1;
  //Numeros Triangulares
  while(n > d*(d+1)/2) ++d;
  while((n&1) != ((d*(d+1)/2)&1)) ++d;
  return d;
}
