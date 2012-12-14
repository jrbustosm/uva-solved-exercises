/* 

Reverse and Add

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(unsigned int N);
unsigned int rotar(unsigned int N);

int main(){
  int T;
  cin >> T;
  while(T--){
    unsigned int N;
    cin >> N;
    int it = 0;
    while(!isPalindrome(N)){
      N += rotar(N);
      ++it;
    }
    cout << it << " " << N << endl;
  }
}

bool isPalindrome(unsigned int N){
  ostringstream oss;
  oss << N;
  string s = oss.str();
  for(int i=0; i<s.size()/2; ++i) if(s[i]!=s[s.size()-1-i]) return false;
  return true;
}

unsigned int rotar(unsigned int N){
  ostringstream oss;
  oss << N;
  string s = oss.str();
  string rs(s.rbegin(), s.rend());
  istringstream iss(rs);
  unsigned int M;
  iss >> M;
  return M;
}

