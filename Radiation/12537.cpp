/* 

Radiation

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct coord{
  double x;
  double y;
  coord(double _x, double _y){
    x = _x;
    y = _y;
  }
};

int find (double* v, double d, int a, int b, int N);

int main(){
  int hs, T=1;
  cin >> hs;
  while(hs!=0){
    cout << "Case " << T++ << ":" << endl;
    coord** vh = new coord*[hs];
    for(int h=0; h<hs; ++h){
      double x, y;
      cin >> x >> y;
      vh[h] = new coord(x, y);
    }
    double ax, ay, bx, by;
    int q;
    cin >> ax >> ay >> bx >> by >> q;
    double* da = new double[hs];
    double* db = new double[hs];
    for(int h = 0; h<hs; ++h){
      da[h] = sqrt((ax-vh[h]->x)*(ax-vh[h]->x) + (ay-vh[h]->y)*(ay-vh[h]->y));
      db[h] = sqrt((bx-vh[h]->x)*(bx-vh[h]->x) + (by-vh[h]->y)*(by-vh[h]->y));
    }
    sort(da, da+hs);
    sort(db, db+hs);
    while(q--){
      double R1, R2;
      cin >> R1 >> R2;
      int c = find(da, R1, 0, hs-1, hs);
      c += find(db, R2, 0, hs-1, hs);
      cout << (hs-c<0?0:hs-c) << endl;
    }
    cin >> hs;
  }
}

int find (double* v, double d, int a, int b, int N){
  if(a==N-1) return a+1;
  if(b==0) return b;
  if(d>=v[a] && d<v[a+1]) return a+1;
  if(d>=v[b-1] && d<v[b]) return b;
  int im = (a+b)/2;
  double m = v[im];
  if(m>d) return find(v, d, a, im, N);
  return find(v, d, im, b, N);
}
