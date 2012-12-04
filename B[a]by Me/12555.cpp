/* 

B[a]by Me

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; ++t){
    int a, b=0;
    cin >> a;
    string s;
    cin >> s;
    if(s.size()>3) b = (int)s[3] - '0';
    cout << "Case " << t << ": " << ((float)a)*0.5 + ((float)b)*0.05 << endl;
  }
}
