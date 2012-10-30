/* 

Artificial Intelligence?

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(){
  char ls[] = {'P', 'I', 'U'};
  string alls[] = {"WmkM", "AmkM", "VmkM"};
  char unds[] = {'W', 'A', 'V'};
  string dats[3]; 
  double ddats[3]; 
  string funds[3]; 
  int cases;
  cin >> cases;
  cin.get();
  for(int c=1; c<=cases; ++c){
    cout << "Problem #" << c << endl;
    string problem;
    getline(cin, problem);

    for(int i=0; i<3; ++i){
      string aux = " ";
      aux += ls[i];
      aux += '=';
      int f = problem.find(aux);
      if(f!=-1) f+=3;
      else if(f==-1 && problem[0]==ls[i] && problem[1]=='=') f=2;
      dats[i] = "";
      ddats[i] = -1;
      funds[i] = "";
      if(f!=-1){
        int f2 = problem.find_first_of(alls[i],f);
        int f3 = problem.find_first_of(unds[i],f2);
        dats[i] = problem.substr(f, f2-f);
        ddats[i] = atof(dats[i].data());
        funds[i] = problem.substr(f2, f3-f2+1);
        if(funds[i].size()>1){
          if(funds[i][0] == 'm') ddats[i] /= 1000;
          else if(funds[i][0] == 'k') ddats[i] *= 1000;
          else if(funds[i][0] == 'M') ddats[i] *= 1000000;
        }
      }
    }
    if(dats[0] == ""){
      double P = ddats[1] * ddats[2];
      cout << "P=" << fixed << setprecision(2) << P << "W" << endl;
    }else if(dats[1] == ""){
      double I = ddats[0] / ddats[2];
      cout << "I=" << fixed << setprecision(2) << I << "A" << endl;
    }else if(dats[2] == ""){
      double U = ddats[0] / ddats[1];
      cout << "U=" << fixed << setprecision(2) << U << "V" << endl;
    }
    cout << endl;
  }
  return 0;
}
