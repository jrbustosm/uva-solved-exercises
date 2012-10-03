/* 

Tree's a Crowd

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct coord{
  double x;
  double y;
  double z;
  coord(double _x, double _y, double _z){
    x = _x;
    y = _y;
    z = _z;
  }
  double dist(coord* c){
    return sqrt((x-c->x)*(x-c->x)+(y-c->y)*(y-c->y)+(z-c->z)*(z-c->z));
  }
};

int main(){
  int h[10];
  for(int i=0; i<10; ++i) h[i]=0; 
  vector<coord*> v;
  double x, y, z;
  cin >> x >> y >> z;
  while( !(x==0 && y==0 && z==0) ){
    coord* c = new coord(x,y,z);
    v.push_back(c);
    cin >> x >> y >> z;
  }
  for(vector<coord*>::iterator it=v.begin(); it!=v.end(); ++it){
    double min = 10; 
    for(vector<coord*>::iterator it2=v.begin(); it2!=v.end(); ++it2){
      if(it == it2) continue;
      double d = (*it)->dist(*it2);
      if(d<min) min=d;
    }
    if(int(min)<10) h[int(min)]++;
  }
  for(int i=0; i<10; ++i){
    cout.width(4);
    cout.fill(' ');
    cout << h[i];
  }
  cout << endl;
}

