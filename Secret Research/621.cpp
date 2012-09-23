/* 

Secret Research

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  cin.get();
  for(int i=0; i<N; ++i){
    string s;
    getline(cin, s);
    int M = s.size()-1;
    if(s=="1" || s=="4" || s=="78") cout << '+' << endl;
    else if(s[M-1] == '3' && s[M] == '5') cout << '-' << endl;
    else if(s[0] == '9' && s[M] == '4') cout << '*' << endl;
    else if(s[0] == '1' && s[1] == '9' && s[2] == '0') cout << '?' << endl;
  }
  return 0;
}
