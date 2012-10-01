/* 

Evaluating Simple C Expressions

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

bool isLetter(char c);

int main(){
  string exp;
  while(getline(cin, exp)){
    cout << "Expression: " << exp << endl;
    map<char, int> m;
    map<char, int> mpost;
    int acumpre = 0;
    char lastOperator = '\0';
    char lastVariable = '\0';
    ostringstream oss;
    bool flagpre = false;
    for(string::iterator it=exp.begin(); it!=exp.end(); ++it){
      char c = *it;
      if(isLetter(c)){
        if(lastOperator!='\0') oss << lastOperator;
        oss << c;
        if(m.find(c) == m.end()){
          m[c] = int(c-'a')+1;
          mpost[c] = 0;
        }
        m[c] += acumpre;
        if(acumpre!=0){
          flagpre = true;
          lastVariable = '\0';
        }else lastVariable = c; 
        lastOperator = '\0';
        acumpre = 0;
      }else if(c=='+' || c=='-'){
        if(lastOperator != '\0'){
          if(lastOperator == c){
            if(lastVariable == '\0') acumpre = (c=='+')?1:-1;
            else{
              mpost[lastVariable] += (c=='+')?1:-1;
              lastVariable = '\0';
            }
            lastOperator = '\0';
          }else{
            oss << lastOperator;
            lastOperator = c;
            lastVariable = '\0';
          }
        }else{
          if(flagpre){
            oss << c;
            flagpre = false;
          }else lastOperator = c;
        }
      }
    }
    string nexp = oss.str();
    int value = m[nexp[0]];
    for(int i=1; i<nexp.size(); i+=2) value+= (nexp[i]=='+')?m[nexp[i+1]]:-m[nexp[i+1]];
    cout << "    value = " << value << endl;
    for(map<char, int>::iterator it = m.begin(); it!=m.end(); ++it){
      char k = (*it).first;
      cout << "    " << k << " = " << (m[k]+mpost[k]) << endl;
    }
  }
}

bool isLetter(char c){
  return c>='a' && c<='z';
}

