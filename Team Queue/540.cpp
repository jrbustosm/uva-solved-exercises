/* 

Team Queue

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main(){
  int ts;
  cin >> ts;
  int scenario = 1;
  while(ts!=0){
    cout << "Scenario #" << scenario++ << endl;
    map<int, int> team;
    for(int i=0; i<ts; ++i){
      int invs;
      cin >> invs;
      for(int j=0; j<invs; ++j){
        int inv;
        cin >> inv;
        team[inv] = i;
      }
    }
    vector<queue<int> > qs(ts);
    vector<bool> fqs(ts, false);
    queue<int> qts;
    string cmd;
    cin >> cmd;
    while(cmd != "STOP"){
      if(cmd == "ENQUEUE"){
        int inv;
        cin >> inv;
        int t = team[inv];
        qs[t].push(inv);
        if(!fqs[t]){
          qts.push(t);
          fqs[t] = true;
        }
      }else{
        //DEQUEUE
        int t = qts.front();
        int inv = qs[t].front();
        qs[t].pop();
        cout << inv << endl;
        if(qs[t].empty()){
          qts.pop();
          fqs[t] = false;
        }
      }
      cin >> cmd;
    }
    cout << endl;
    cin >> ts;
  }
}
