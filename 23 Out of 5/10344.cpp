/* 

23 Out of 5

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>

using namespace std;

bool test(int* v);
int calc(int* v, int* ops);
int calc(int a, int b, int op);
bool next(int* v, int N);

int main(){
  int v[5];
  cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
  while(!(v[0]==0 && v[1]==0 && v[2]==0 && v[3]==0 && v[4]==0)){
    cout << (test(v)?"Possible":"Impossible") << endl;
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
  }
}

bool test(int* v){
  sort(v, v + 5);
  do{
    for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
        for(int k=0; k<3; ++k){
          for(int l=0; l<3; ++l){
            int ops[] = {i,j,k,l};
            int r=calc(v, ops);
            if(r==23) return true;
          }
        }
      }
    }
  }while(next(v, 5));
  return false;
}

int calc(int* v, int* ops){
  int r = v[0];
  for(int k=0; k<=3; ++k) r = calc(r,v[k+1],ops[k]);
  return r;
}

int calc(int a, int b, int op){
  if(op==0) return a+b;
  if(op==1) return a-b;
  return a*b;
}

bool next(int* v, int N){
  int i=N-1;
  int j=N;
  while(v[i-1]>=v[i]) --i;
  while(v[j-1]<=v[i-1]) --j;
  if(i==0 || j==0) return false;
  swap(v[i-1], v[j-1]);
  ++i;
  j=N;
  while(i<j){
    swap(v[i-1],v[j-1]);
    ++i;
    --j;
  }
  return true;
}

