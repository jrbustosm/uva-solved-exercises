/* 

Box of Bricks

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N;
  int c = 0;
  cin >> N;
  while(N!=0){
    vector<int> v(N);
    int sum = 0;
    for(int i=0; i<N; ++i){
      cin >> v[i];
      sum += v[i];
    }
    int w = sum / N;
    int r = 0;
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it) if(*it>w) r+=(*it-w);
    ++c;
    cout << "Set #" << c << endl;
    cout << "The minimum number of moves is " << r << "." << endl << endl;
    cin >> N;
  }
}
