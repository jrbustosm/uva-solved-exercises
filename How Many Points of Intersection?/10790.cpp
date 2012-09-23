/* 

How Many Points of Intersection?

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  long long A, B;
  cin >> A >> B;
  int c = 0;
  while(A!=0){
    ++c;
    cout << "Case " << c << ": " << A*(A-1)*B*(B-1)/4 << endl;
    cin >> A >> B;
  }
  return 0;
}
