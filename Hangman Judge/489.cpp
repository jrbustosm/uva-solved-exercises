/* 

Jose Ricardo Bustos Molina

*/

#include <iostream>

using namespace std;

int main(){
  int r;
  cin >> r;
  cin.get();
  while(r!=-1){
    string w, s;
    bool v[255];
    for(int i=0; i<255; ++i) v[i] = false;
    getline(cin,w);

    int nl = 0;
    for(string::iterator it=w.begin(); it < w.end(); ++it){
      if(!v[(int)*it]) ++nl;
      v[(int)*it] = true;
    }

    getline(cin,s);
    int error = 0, acierto=0;
    for(string::iterator it=s.begin(); it < s.end(); ++it){
      if(v[(int)*it]){
        ++acierto;
        if(nl==acierto) break;
        v[(int)*it] = false;
      }
      else {
        ++error;
        if(error>=7) break;
      }
    }

    cout << "Round " << r << endl;    
    if(nl==acierto && error<7) cout << "You win." << endl;
    else if(error<7) cout << "You chickened out." << endl;
    else cout << "You lose." << endl;

    cin >> r;
    cin.get();
  }
  return 0;
}
