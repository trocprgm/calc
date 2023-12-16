#include <iostream>
#include <string>
#include <list>
#include <math.h>
using namespace std;
double TheFunc(double x) {
  double y = sin(x);
  return y;
}

double pi = 3.14159265358979323846;
double FuncSummer() {
  int slices = 5;
  double runningArea = 0;
  float a = 0;
  double b = pi;
  double span = b - a;
  double dx = span / slices;
  //cout << "Dx is:" << dx << "\nA is:" << a << "\nB is:" << b ;

  for (int i = a; i < slices; i++) {
    double index = i * dx;
    //cout << index << "\n";
    //cout << " \n" << TheFunc(index);
    double localTriangle = (dx * ( TheFunc(index + dx) - TheFunc(index) ))/2;
    double localLine = (dx * TheFunc(index));
    //cout << localLine;
    runningArea = runningArea + localLine + localTriangle;
    //cout << localLine << " ";

  }
  return runningArea;
}

int main() {
  cout << FuncSummer();
  return 0;
}
