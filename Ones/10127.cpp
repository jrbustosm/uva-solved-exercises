/* 

Ones

Jose Ricardo Bustos Molina

3 ---> 111

N= 1 +
N=11%3=2 +
N=21%3=0 +

41 ---> 11111

N=1 +
N=11%41=11 +
N=111%41=29 +
N=291%41=4 +
N=41%41=0 +

*/

#include <iostream>
#include <map>

using namespace std;

map<int, int> cache;

int ones(int in);

int main(){
  cache[1]=1;
  int in;
  while(cin >> in) cout << ones(in) << endl;
}

int ones(int in){
  if(cache.find(in)!=cache.end()) return cache[in];
  int one = 1;
  for(int N=1; N!=0; ++one) N = (10*N+1)%in;
  cache[in] = one;
  return one;
}

