/* 

The Mad Numerologist

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  char vocal[] = {'A', 'U', 'E', 'O', 'I'};
  char consonante[] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
  string v[211];
  string vs;
  string cs;
  int pv = 0;
  int pc = 0;
  for(int i=1; i<211; ++i){
    if(i&1){
      vs += vocal[pv/21];
      ++pv;
    }else{
      cs += consonante[pc/5];
      ++pc;
    }
    sort(vs.begin(), vs.end());
    sort(cs.begin(), cs.end());
    int apv = 0;
    int apc = 0;
    string s = "";
    for(int j=0; j<i; ++j){
      if(j&1) s += cs[j/2];
      else s += vs[j/2];
    }
    v[i-1] = s;
  }
  int N;
  cin >> N;
  for(int c=1; c<=N; ++c){
    int n;
    cin >> n;
    cout << "Case " << c << ": " << v[n-1] << endl;
  }
}
