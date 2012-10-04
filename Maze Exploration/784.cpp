/* 

Maze Exploration

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};

void exploration(vector<string> &m, int i, int j);

int main(){
  int n;
  cin >> n;
  cin.get();
  for(int k=0; k<n; ++k){
    vector<string> lines;
    string line;
    getline(cin, line);
    int r = 0, ri = -1, ci=-1;
    while(line[0]!='_'){
      lines.push_back(line);
      if(line.find('*')!=-1){
        ci = line.find('*');
        ri = r;
      }
      getline(cin, line);
      ++r;
    }
    exploration(lines, ri, ci);
    for(vector<string>::iterator it=lines.begin(); it!=lines.end(); ++it) cout << (*it) << endl;
    cout << line << endl;
  }
}

void exploration(vector<string> &m, int i, int j){
  if(i<0 || j<0 || i>=m.size() || j>=m[i].size()) return;
  if(m[i][j]=='X' || m[i][j]=='#') return;
  m[i][j] = '#';
  for(int k=0; k<4; ++k) exploration(m,i+di[k],j+dj[k]);
}

