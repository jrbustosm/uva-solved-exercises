/* 

The Decoder

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string l;
  while(getline(cin, l)){
    for(string::iterator it=l.begin(); it!=l.end(); ++it) cout << (char)(*it-7);
    cout << endl;
  }
  return 0;
}
