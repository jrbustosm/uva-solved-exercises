/* 

Friends

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int countfriends(int, set<int>*);

vector<bool> friends;

int main ()
{
  int S;
  //Leemos el número de casos de prueba
  cin >> S;
  for(int k=0; k<S; ++k){
    int N, M;
    //Para cada caso de prueba leemos el número de ciudadanos y la cantidad de
    //parejas de amigos
    cin >> N >> M;
    //Inicializamos la lista de adyacencia del grafo
    set<int>* ladj = new set<int>[N];
    //Llenanmos la lista de adyacencia con los datos del caso de pruebas
    for(int p=0; p<M; ++p){
      int p1, p2;
      cin >> p1 >> p2;
      ladj[p1-1].insert(p2-1);
      ladj[p2-1].insert(p1-1);
    }
    //Encontramos el grupo mas grande de amigos
    friends = vector<bool>(N,false);
    int max = countfriends(0, ladj);
    for(int i=1; i<N; ++i){
      if(max==N || max>=M+1) break;
      if(!friends[i]){
        int c = countfriends(i, ladj);
        if(c > max) max = c;
      }
    }
    cout << max << endl;
    //Eliminamos el espacio de memoria reservado
    delete [] ladj;
  }
  return 0;
}

int countfriends(int i, set<int>* ladj){
  if(friends[i]){
    return 0;
  }
  int c = 1;
  friends[i] = true;
  for(set<int>::iterator it=ladj[i].begin(); it!=ladj[i].end(); ++it){
    c += countfriends(*it, ladj);
  }
  return c;
}
