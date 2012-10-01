/* 

Myacm Triangles

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct coord{
  int x;
  int y;
  char name;
  coord(int _x, int _y, char _name){
    x = _x;
    y = _y;
    name = _name;
  }
};

double area(coord c1, coord c2, coord c3);

int main(){
  int N;
  cin >> N;
  while(N!=0){
    char name;
    int x, y;
    vector<coord*> v;
    for(int i=0; i<N; ++i){
      cin >> name >> x >> y;
      coord* c = new coord(x,y,name);
      v.push_back(c);
    }
    double max = -1;
    char trg[] = {'\0', '\0', '\0'};
    for(int i=0; i<v.size(); ++i){
      for(int j=i+1; j<v.size(); ++j){
        for(int k=j+1; k<v.size(); ++k){
          double a = area(*v[i], *v[j], *v[k]);
          if(a > max){
            bool flag = true;
            for(int h=0; h<v.size() && flag; ++h){
              if(h==i || h==j || h==k) continue;
              double a1 = area(*v[i], *v[j], *v[h]);
              double a2 = area(*v[i], *v[h], *v[k]);
              double a3 = area(*v[h], *v[j], *v[k]);
              if(a1+a2+a3 == a) flag = false;
            }
            if(flag){
              max = a;
              trg[0] = v[i]->name;
              trg[1] = v[j]->name;
              trg[2] = v[k]->name;
            }
          }
        }
      }
    }
    cout << trg[0] << trg[1] << trg[2] << endl;
    cin >> N;
  }
}

double area(coord c1, coord c2, coord c3){
  return abs(double((c3.y - c1.y)*(c2.x - c1.x) - (c2.y - c1.y)*(c3.x - c1.x))/2.0);
}

