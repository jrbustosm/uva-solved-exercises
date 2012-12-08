/* 

Hajj-e-Akbar

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int t = 1;
  string s;
  cin >> s;
  while(s!="*"){
    cout << "Case " << t++ << ": ";
    if(s=="Hajj") cout << "Hajj-e-Akbar" << endl;
    else cout << "Hajj-e-Asghar" << endl;
    cin >> s;
  }
}
