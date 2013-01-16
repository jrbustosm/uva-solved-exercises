/* 

Decoding

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; ++i){
    string s;
    cin >> s;
    istringstream iss(s);
    char c;
    cout << "Case " << i << ": ";
    while(iss >> c){
      int n;
      iss >> n;
      cout << string(n, c);
    }
    cout << endl;
  }
}
