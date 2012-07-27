/* 

Kindergarten counting game

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countwords(string);
bool isletter(char);

int main ()
{
  string line;
  while(getline(cin, line)){
    cout << countwords(line) << endl;
  }
  return 0;
}

int countwords(string word){
  int c=0;
  if(isletter(word[0])) ++c;
  for(int i=1; i<word.size(); ++i)
    if(isletter(word[i]) && !isletter(word[i-1])) ++c;
  return c; 
}

bool isletter(char c){
  return c>='a' && c <='z' || c>='A' && c<='Z';
}
