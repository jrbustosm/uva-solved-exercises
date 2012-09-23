/* 

List of Conquests

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  map<string,int> countries;
  for(int i=0; i<n; ++i){
    getline(cin, line);
    istringstream iss(line);
    string country;
    iss >> country;
    if(countries.find(country) == countries.end())
      countries[country]=1;
    else
      countries[country]++;
  }
  vector<string> names;
  
  for (map<string,int>::iterator it=countries.begin() ; it != countries.end(); it++ )
    names.push_back((*it).first);

  sort(names.begin(), names.end());

  for (vector<string>::iterator it=names.begin() ; it != names.end(); it++ )
    cout << *it << " " << countries[*it] << endl;

  return 0;
}
