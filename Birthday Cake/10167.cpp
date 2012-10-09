/* 

Birthday Cake

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>

using namespace std;

struct coord{
  int x;
  int y;
  coord(int _x, int _y){
    x = _x;
    y = _y;
  }
};

int main(){
  int N;
  cin >> N;
  while(N>0){
    vector<coord*> cs;
    for(int j=0; j<2*N; ++j){
      int x, y;
      cin >> x >> y;
      cs.push_back(new coord(x, y));
    }
    bool f = false;
    for(int A=-500; A<=500 && !f; ++A){
      for(int B=-500; B<=500 && !f; ++B){
        int p=0, n=0, c=0;
        for(vector<coord*>::iterator it=cs.begin(); it!=cs.end(); ++it){
          int r = A * (*it)->x + B * (*it)->y;
          if(r<0) n++;
          else if(r>0) p++;
          else c++;
          if(n>N || p>N) break;
          if(c>0) break; //Comment, if the cherries can be divided
        }
        if(n==N && p==N && c==0 /*|| c==2*N*/){ //uncomment, if the cherries can be divided
          f = true;
          cout << A << " " << B << endl;
        }
      }
    }
    cin >> N;
  }
}

