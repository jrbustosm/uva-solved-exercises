/* 

Triangle Wave

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main ()
{
  int n;
  cin >> n;
  for(int k=0; k<n; ++k){
    int a, f;
    cin >> a >> f;
    for(int w=0; w<f; ++w){
      for(int i=1; i<=a; ++i){
        for(int j=1; j<=i; ++j){
          cout << i;
        }
        cout << endl;
      }
      for(int i=a-1; i>=1; --i){
        for(int j=1; j<=i; ++j){
          cout << i;
        }
        cout << endl;
      }
      if(!(w==f-1 && k==n-1)) cout << endl;
    }
  }
  return 0;
}
