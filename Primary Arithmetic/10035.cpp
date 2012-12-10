/* 

Primary Arithmetic

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  string A, B;
  cin >> A >> B;
  while(!(A=="0" && B=="0")){
    int i=A.size()-1;
    int j=B.size()-1;
    int c = 0, cc=0;
    while(i>=0 && j>=0 || c!=0){
      int nA = 0;
      if(i>=0) nA = A[i]-'0';
      int nB = 0;
      if(j>=0) nB = B[j]-'0';
      if(nA+nB+c>9){
        ++cc;
        c = 1;
      }else c = 0;
      --i;
      --j;
    }
    if(cc==0) cout << "No carry operation." << endl;
    else if(cc==1) cout << "1 carry operation." << endl;
    else cout << cc << " carry operations." << endl;
    cin >> A >> B;
  }
}
