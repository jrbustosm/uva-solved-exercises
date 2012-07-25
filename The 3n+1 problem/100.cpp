/* 

the 3n+1 problem

Jose Ricardo Bustos Molina

*/

#include <iostream>

//Tamaño máximo del cache
#define MAXS 30000001

using namespace std;

//Maximim size of chache
static int longs[MAXS];

long findlong(long);

int main ()
{
  long i, j;

  //cache initialization
  for(long k=0; k<MAXS; ++k) longs[k] = 0;

  while(cin >> i >> j){

    long o = i;
    long f = j;

    if(i>j){
      o = j;
      f = i;
    }

    //Assume that the maximum cycle length is left value of interval
    long max = findlong(o);
    for(long k=o+1; k<=f; ++k){
      long c = findlong(k);
      if(c>max){
        max = c; //if find one higher, then replace
      }
    }
    cout << i << " " << j << " " << max << endl;
  }
  return 0;
}

//this function find the cycle length, using the algoritgm 3n+1 
long findlong(long n){
  if(n<MAXS) if(longs[n] != 0) return longs[n];
  if(n==1) return 1;
  long nn = n/2;
  if(n & 1)
    nn = 3*n+1;
  long res = findlong(nn)+1;
  if(n<MAXS) longs[n] = res;
  return res;
}

