/* 

Circle Through Three Points

Jose Ricardo Bustos Molina

x^2 + y^2 + cx + dy + e = 0

P = -x^2 - y^2

cx + dy + e = P

cx1 + dy1 + e = P1
cx2 + dy2 + e = P2
cx3 + dy3 + e = P3

|x1 y1 1| |c| |P1|
|x2 y2 1|.|d|=|P2|
|x3 y3 1| |e| |P3|

    ||x1 y1 1||
m = ||x2 y2 1||
    ||x3 y3 1||

    ||P1 y1 1||
c = ||P2 y2 1|| / m
    ||P3 y3 1||

    ||x1 P1 1||
d = ||x2 P2 1|| / m
    ||x3 P3 1||

    ||x1 y1 P1||
e = ||x2 y2 P2|| / m
    ||x3 y3 P3||

||M3x3|| = a11 a22 a33 + a12 a23 a31 + a13 a21 a32 - a13 a22 a31 - a12 a21 a33 - a11 a23 a32

*/

#include <iostream>
#include <cmath>

using namespace std;

double det(double a11, double a12, double a13,
         double a21, double a22, double a23,
         double a31, double a32, double a33);

char s(double d);

int main(){
  double x1, y1, x2, y2, x3, y3;
  cout.precision(3);
  cout.setf(ios::fixed,ios::floatfield);
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
    double m, c, d, e, P1, P2, P3;
    P1 = -x1*x1-y1*y1;
    P2 = -x2*x2-y2*y2;
    P3 = -x3*x3-y3*y3;
    m = det(x1, y1, 1, x2, y2, 1, x3, y3, 1);
    c = det(P1, y1, 1, P2, y2, 1, P3, y3, 1) / m;
    d = det(x1, P1, 1, x2, P2, 1, x3, P3, 1) / m;
    e = det(x1, y1, P1, x2, y2, P2, x3, y3, P3) / m;
    double h = c/2;
    double k = d/2;
    double r = sqrt(h*h+k*k-e);
    cout << "(x " 
         << s(h) << " " << abs(h)
         << ")^2 + (y "
         << s(k) << " " << abs(k)
         << ")^2 = " << r << "^2"
         << endl;
    cout << "x^2 + y^2 " 
         << s(c) << " " << abs(c) << "x "
         << s(d) << " " << abs(d) << "y " 
         << s(e) << " " << abs(e) << " = 0" << endl << endl;
  }
}

double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
  return a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a13*a22*a31 - a12*a21*a33 - a11*a23*a32;
}

char s(double d){
  return d<0?'-':'+';
}

