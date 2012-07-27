/* 

Rotating sentences

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  vector<string> lines;
  string line;
  while(getline(cin, line)){
    lines.insert(lines.begin(),line);
  }
  int max = lines[0].size();
  for(vector<string>::iterator it=lines.begin()+1; it!=lines.end(); ++it)
    if(it->size() > max) max = it->size();
  for(int i=0; i<max; ++i){
    for(vector<string>::iterator it=lines.begin(); it!=lines.end(); ++it){
      if(i<it->size()) cout << it->at(i);
      else cout << " ";
    }
    cout << endl;
  }
  return 0;
}
