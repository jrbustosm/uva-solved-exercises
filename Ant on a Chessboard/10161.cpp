/* 

Ant on a Chessboard

Jose Ricardo Bustos Molina

Serie 1: 1 4 9 16 25 ... n^2

serie 2: 1 3 7 13 21 ....

T1 = 1
T2 = 3
T3 = 7
T4 = 13
T5 = 21
T6 = 31

T2 - T1 = 2 => U1
T3 - T2 = 4 => U2
T4 - T5 = 6 => U3
T5 - T4 = 8 => U4
T6 - T5 = 10 => U5

U2 - U1 = 2
U3 - U2 = 2
U4 - U3 = 2
U5 - U4 = 2

so

Un - U(n-1) = 2

as, U(n-1) = Tn - T(n-1)

then, Un = T(n+1) - Tn

therefore, Un - U(n-1) = T(n+1) - Tn - Tn + T(n-1) = 2

T(n+1) - 2Tn + T(n-1) = 2
T(n+1) = 2 + 2Tn - T(n-1) <= recursive definition 

T(n) = 2 + 2T(n-1) - T(n-2)
T(1) = 1
T(2) = 3

*/

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int T(int n);

map<int, int> cache;

int main(){
  cache[1] = 1;
  cache[2] = 3;
  int n;
  cin >> n;
  while(n!=0){
    int s = int(sqrt(n-1))+1;
    int t = T(s);
    int f=0, c=0;
    if(s%2==0){
      if(t<n){
        c = s;
        f = s - (n-t);
      }else{
        f = s;
        c = s - (t-n);
      }
    }else{
      if(t<n){
        f = s;
        c = s - (n-t);
      }else{
        c = s;
        f = s - (t-n);
      }
    }
    cout << c << " " << f << endl;
    cin >> n;
  }
}

int T(int n){
  if(cache.find(n) != cache.end()) return cache[n];
  int r = 2 + 2*T(n-1) - T(n-2);
  cache[n] = r;
  return r;
}

