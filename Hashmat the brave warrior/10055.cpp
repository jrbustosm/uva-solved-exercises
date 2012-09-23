/* 

Hashmat the Brave Warrior

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main ()
{
  unsigned long n, m;
  while(cin >> n >> m){
    unsigned long diff = n-m;
    if(n < m) diff = m-n;
    cout << diff << endl;
  }
  return 0;
}
