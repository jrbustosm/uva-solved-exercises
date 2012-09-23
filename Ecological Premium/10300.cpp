/* 

Ecological Premium

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main ()
{
  int n;
  cin >> n;
  for(int k=0; k<n; ++k){
    int s, sum = 0;
    cin >> s;
    for(int w=0; w<s; ++w){
      int a, g, f;
      cin >> a >> g >> f;
      sum += a*f;
    }
    cout << sum << endl;
  }
  return 0;
}
