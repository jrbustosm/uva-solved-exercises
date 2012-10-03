/* 

Cube painting

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int p[24][6] = {
  {1,2,3,4,5,6},
  {1,4,2,5,3,6},
  {1,5,4,3,2,6},
  {1,3,5,2,4,6},
  {2,3,1,6,4,5},
  {2,6,3,4,1,5},
  {2,4,6,1,3,5},
  {2,1,4,3,6,5},
  {3,1,2,5,6,4},
  {3,2,6,1,5,4},
  {3,6,5,2,1,4},
  {3,5,1,6,2,4},
  {4,5,6,1,2,3},
  {4,1,5,2,6,3},
  {4,2,1,6,5,3},
  {4,6,2,5,1,3},
  {5,6,4,3,1,2},
  {5,3,6,1,4,2},
  {5,1,3,4,6,2},
  {5,4,1,6,3,2},
  {6,5,3,4,2,1},
  {6,4,5,2,3,1},
  {6,2,4,3,5,1},
  {6,3,2,5,4,1}
};

bool isSame(string &a, string &b);

int main(){
  string line;
  while(getline(cin, line)){
    string c1 = line.substr(0,6);
    string c2 = line.substr(6);
    if(isSame(c1, c2)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;
  }
}

bool isSame(string &a, string &b){
  for(int i=0; i<24; ++i){
    ostringstream oss;
    for(int j=0; j<6; ++j) oss << a[p[i][j]-1];
    if(oss.str() == b) return true;
  }
  return false;
}

