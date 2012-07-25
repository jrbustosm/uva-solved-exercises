// Jose Ricardo Bustos Molina

#include <iostream>

#define MAXS 30000001

using namespace std;

static int longs[MAXS];
long encontrarlong(long);

int main ()
{
  long i, j;

  for(long k=0; k<MAXS; ++k) longs[k] = 0;

  while(cin >> i >> j){

    long o = i;
    long f = j;

    if(i>j){
      o = j;
      f = i;
    }

    long max = encontrarlong(o);
    for(long k=o+1; k<=f; ++k){
      long c = encontrarlong(k);
      if(c>max){
        max = c;
      }
    }
    cout << i << " " << j << " " << max << endl;
  }
  return 0;
}

long encontrarlong(long n){
  if(n<MAXS) if(longs[n] != 0) return longs[n];
  if(n==1) return 1;
  long nn = n/2;
  if(n & 1)
    nn = 3*n+1;
  long res = encontrarlong(nn)+1;
  if(n<MAXS) longs[n] = res;
  return res;
}
