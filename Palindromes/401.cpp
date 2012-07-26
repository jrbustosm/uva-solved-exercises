/* 

Palindromes

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string reverses   = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
map<char,char> mirror;

bool ispalindrome(string);
bool ismirrored(string);

int main(){
  for(string::iterator it=characters.begin(), it2=reverses.begin(); it < characters.end(); ++it, ++it2){
    mirror[*it] = *it2;
  }
  string s;
  while(getline(cin, s)){
    bool ispl = ispalindrome(s);
    bool ismr = ismirrored(s);
    cout << s << " -- ";
    if (ispl && ismr){
      cout << "is a mirrored palindrome.";
    }else if(ispl && !ismr){
      cout << "is a regular palindrome.";
    }else if(ismr && !ispl){
      cout << "is a mirrored string.";
    }else{
      cout << "is not a palindrome.";
    }
    cout << endl << endl;
  }
  return 0;
}

bool ispalindrome(string s){
  string::iterator it = s.begin();
  string::iterator rv = s.begin();
  rv += s.size() - 1;
  while( it < rv  ){
    if(*it == 'O' || *it == '0'){
      if(!(*rv =='0' || *rv =='O')) return false;
    }else if(*it != *rv) return false;
    it++;
    rv--;
  }
  return true;
}

bool ismirrored(string s){
  string::iterator it = s.begin();
  string::iterator rv = s.begin();
  rv += s.size() - 1;
  while( it <= rv ){
    if(*it == 'O' || *it == '0'){
      if(!(*rv =='0' || *rv =='O')) return false;
    }else if(mirror[*it] != *rv) return false;
    it++;
    rv--;
  }
  return true;
}

