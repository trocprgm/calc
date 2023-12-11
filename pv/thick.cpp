#include <iostream>
#include <string>
#include <list>
#include <math.h>
using namespace std;

double InnerDiameter = 0.8;
double WallThickness = 0.1;
double OuterDiameter = InnerDiameter + (2 * WallThickness);
double Pressure = 5000;

/*Units: Kpa m*/
double Membrane(double idia, double thic, double pres) {
    double stress = (pres * idia)/(2* thic);
    return stress;
}
double Barlow(double odia, double thic, double pres) {
    double stress = (pres * odia)/(2* thic);
    return stress;
}

double Lame(double odia, double idia, double thic, double press) {
    double stress = press * (pow(odia,2) + pow(idia,2))/(pow(odia,2) - pow(idia,2)); 
    return stress;
}

double Boardman(double odia, double thic, double pres) {
    double stress = (pres * (odia - (0.8 * thic) ))/(2* thic);
    return stress;
}

double Average(double odia, double thic, double pres) {
    double stress = (pres * (odia - thic ))/(2* thic);
    return stress;
}

int main () {
    cout << "Barlow's Formula\n" << Barlow(OuterDiameter,WallThickness,Pressure) << " Kpa\n\n";
    cout << "Membrane Formula\n" << Membrane(InnerDiameter,WallThickness,Pressure) << " Kpa\n\n";
    cout << "Lame's Formula\n" << Lame(OuterDiameter,InnerDiameter,WallThickness,Pressure) << " Kpa\n\n";
    cout << "Boardman's Formula\n" << Boardman(OuterDiameter,WallThickness,Pressure) << " Kpa\n\n";
    cout << "Average's Formula\n" << Average(OuterDiameter,WallThickness,Pressure) << " Kpa\n\n";
    return 0;
}
