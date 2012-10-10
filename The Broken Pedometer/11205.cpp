/* 

The Broken Pedometer

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool test(int* v, int N);
int countsegments(int* v, int N, int P);
void countsegments(int* v, int N, int P, int w, int &c);

int main(){
  int T;
  cin >> T;
  cin.get();
  while(T--){
    int P, N;
    cin >> P >> N;
    int* v = new int[N];
    for(int i=0; i<N; ++i){
      int n = 0;
      for(int j=P-1; j>=0; --j){
        bool d;
        cin >> d;
        if(d) n += (1<<j);
      }
      v[i]=n;
    }
    cout << countsegments(v, N, P) << endl;
  }
}

bool test(int* v, int N){
  vector<int> vo(v, v+N);
  sort(vo.begin(), vo.end());
  for(int i=1; i<N; ++i) if(vo[i-1]==vo[i]) return false;
  return true;
}

int countsegments(int* v, int N, int P){
  int max = 0;
  for(int w=P-1; w>=0; --w){
    int r = 0;
    countsegments(v, N, P, w, r);
    if(r>max) max=r;
    if(max>=w+1) break;
  }
  return P-max;
}

void countsegments(int* v, int N, int P, int w, int &c){
  //Copy and modify
  int* copy = new int[N];
  //   1 1 1 0 1 1 1 & (1 1 1 1 1 1 1 ^ 0 1 0 0 0 0 0)
  // = 1 0 1 0 1 1 1
  int T = ((1<<P)-1);
  for(int i=0; i<N; ++i){
    int r = (1<<w);
    copy[i] = v[i] & (T^r);
  }
  if(!test(copy,N)) return;
  ++c;
  int max = 0;
  for(int nw=w-1; nw>=0; --nw){
    int r = 0;
    countsegments(copy, N, P, nw, r);
    if(r>max) max=r;
    if(max>=nw+1) break;
  }
  c+=max;
}

