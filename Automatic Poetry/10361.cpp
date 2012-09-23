/* 

Automatic Poetry

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  cin.get();
  for(int i=0; i<N; ++i){
    string l1, l2;
    getline(cin, l1);
    int ini = l1.find_first_of('<');
    int fin = l1.find_first_of('>');
    int finw = l1.find_first_of('<', fin);
    string s1 = l1.substr(ini+1,fin-ini-1);
    string s2 = l1.substr(fin+1,finw-fin-1);
    int ini2 = l1.find_last_of('<');
    int fin2 = l1.find_last_of('>');
    int finw2 = l1.size();
    string s3 = l1.substr(ini2+1,fin2-ini2-1);
    string s4 = l1.substr(fin2+1,finw2-fin2-1);
    l1 = l1.erase(fin2,1);
    l1 = l1.erase(ini2,1);
    l1 = l1.erase(fin,1);
    l1 = l1.erase(ini,1);
    cout << l1 << endl;
    getline(cin, l2);
    l2 = l2.erase(l2.size()-3, 3);
    cout << l2 << s3 << s2 << s1 << s4 << endl;
  }
}
