/* 

Interval Products

Jose Ricardo Bustos Molina

*/

#include <stdio.h>
#include <cmath>

#define MAX 100001

using namespace std;

int e[MAX];
int v[MAX];
int z[MAX];

void update(int *v, int a, int d, int N, int T);
int count(int *v, int l, int r, int T);
int count(int *v, int x, int T);

int main(){
  int N, K;
  while(scanf("%d %d",&N,&K) != EOF){
    int T = (int)(sqrt(N));
    int h = 0;
    int g = 0;
    v[0] = 0;
    z[0] = 0;
    for(int i=1; i<=N; ++i){
      scanf("%d", &e[i-1]);
      if(e[i-1]<0) ++h;
      else if(e[i-1]==0) ++g;
      if(i%T==0){
        v[i] = v[i-T]+h;
        z[i] = z[i-T]+g;
        h=0;
        g=0;
      }else{
        v[i] = h;
        z[i] = g;
      }
    }
    while(K--){
      char c[2];
      int a, b;
      scanf("%s %d %d",c,&a,&b);
      if(c[0]=='C'){
        if(b<0 && e[a-1]>=0) update(v, a, 1, N, T);
        else if(b>=0 && e[a-1]<0) update(v, a, -1, N, T);
        if(b==0 && e[a-1]!=0) update(z, a, 1, N, T);
        else if(e[a-1]==0 && b!=0) update(z, a, -1, N, T);
        e[a-1] = b;
      }
      else{
        if(count(z,a,b,T)) printf("0");
        else{
          if(count(v,a,b,T)&1) printf("-");
          else printf("+");
        }
      }
    }
    puts("");
  }
}

int count(int *v, int l, int r, int T){
  return count(v,r,T)-count(v,l-1,T);
}

int count(int *v, int x, int T){
  return v[x] + (x%T==0?0:v[x/T*T]);
}

void update(int *v, int a, int d, int N, int T){
  for(int* i=v+a; i<v+(((a-1)/T+1)*T) && i<=v+N; ++i) (*i)+=d;
  for(int* i=v+(((a-1)/T+1)*T); i<=v+N; i+=T) (*i)+=d;
}

