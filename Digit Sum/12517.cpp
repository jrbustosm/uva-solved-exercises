/* 

Digit Sum

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

long ds(long N);
long ds(int n, int b);

long s[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

int main(){
  long a, b;
  cin >> a >> b;
  while(!(a==0 && b==0)){
    cout << ds(b) - ds(a-1) << endl;
    cin >> a >> b;
  }
}

long ds(long N){
  string s;
  ostringstream oss;
  oss << N;
  s = oss.str();
  long c = 0;
  for(int i = 0; i<s.size(); ++i){
    int n = s[i]-'0';
    int b = s.size()-i;
    c += ds(n, b) + n*(N%((long)pow(10,b-1)));
  }
  return c;
}

long ds(int n, int b){
  if(n==0) return 0;
  if(b==1) return s[n];
  return (b-1) * n * s[9] * ((long)pow(10,b-2)) + s[n-1] * ((long)pow(10,b-1)) + n;
}

