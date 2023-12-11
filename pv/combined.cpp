#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <thread>
using namespace std;
using namespace std::this_thread;

string method(int meth) {
    switch (meth) 
    {
        case 0:
            return "Membrane Formula";
        case 1:
            return "Barlow's Formula";
        case 2:
            return "Lame's Formula";
        case 3:
            return "Boardman's Formula";
        case 4:
            return "Average Formula";
        default:
            return 0;
     }
}

double stress(double odia, double idia, double thic, double pres, int meth) {
    double Membrane = (pres * idia)/(2* thic);
    double Barlow = (pres * odia)/(2* thic);
    double Lame = pres * (pow(odia,2) + pow(idia,2))/(pow(odia,2) - pow(idia,2)); 
    double Boardman = (pres * (odia - (0.8 * thic) ))/(2* thic);
    double Average = (pres * (odia - thic ))/(2* thic);
    switch (meth) 
    {
        case 0:
            return Membrane;
        case 1:
            return Barlow;
        case 2:
            return Lame;
        case 3:
            return Boardman;
        case 4:
            return Average;
        default:
            return 0;
    }
}

double pressure(double odia, double idia, double thic, double stres, int meth) {
    double Membrane = (stres *(2*thic))/idia;
    double Barlow = (stres *(2*thic))/odia;
    double Lame = (stres *(pow(odia,2) - pow(idia,2))/ (pow(odia,2) + pow(idia,2))); 
    double Boardman = (stres * (2*thic)/(odia - (0.8 * thic)));
    double Average = (stres * (2*thic)/(odia - thic));
    switch (meth) 
    {
        case 0:
            return Membrane;
        case 1:
            return Barlow;
        case 2:
            return Lame;
        case 3:
            return Boardman;
        case 4:
            return Average;
        default:
            return 0;
    }
}
double oneish (double idia, double thic, double pres, double stres) {
    double odia = idia + 2* thic;
    return (stres/pres)*((pow(odia,2) - pow(idia,2))/ (pow(odia,2) + pow(idia,2)));
}
double bestGuess (double idia, double pres, double stres, int n) {
    double low = (idia*pres)/(2*stres);
    double high = (idia * pres)*1.5 / (2 * (stres - pres)) ;
    double step = (high-low)/n;
    double besthic = 0;
    double besone = 0;
    for (int i = 0; i < n; i++) {
        double tic = low + (i*step);
        double locone = oneish(idia, tic, pres, stres);
        if (abs(1-besone) > abs(1-locone)) {
            besthic = tic;
            besone = locone;
        }
    }
    return besthic;
}
double wallthickness(double idia, double pres, double stres, int meth) {
    double Membrane = (idia*pres)/(2*stres);
    double Barlow = (idia * pres) / (2 * (stres - pres)) ;
    double Lame = bestGuess(idia, pres, stres, 100); 
    double Boardman = (pres*idia)/(2*stres - 1.2* pres);
    double Average = (pres*idia)/(2*stres - pres);
    switch (meth) 
    {
        case 0:
            return Membrane;
        case 1:
            return Barlow;
        case 2:
            return Lame;
        case 3:
            return Boardman;
        case 4:
            return Average;
        default:
            return 0;
    }
}
int HoopInterface() {
    /*Syntax Reminder: double stress(double odia, double idia, double thic, double pres, int meth)*/
    double Pressure = 0;
    int IDOD = -1;
    double OutsideDiameter = 0;
    double InsideDiameter = 0;
    double WallThickness = 0;
    cout << "\nStress\n+++++++++++\n\n";
    cout << "Wall Thickness(meters): ";
    cin >> WallThickness;
    cout << "\n\n1:Inside Diameter\n2:Outside Diameter\n\nEnter 1-2: ";
    cin >> IDOD;
    switch (IDOD)
    {
        case 1:
            cout << "\n\nInside Diameter(meters): ";
            cin >> InsideDiameter;
            OutsideDiameter = InsideDiameter + 2 * WallThickness;
            break;
        case 2:
            cout << "\n\nOutside Diameter(meters): ";
            cin >> OutsideDiameter;
            InsideDiameter = OutsideDiameter - 2 * WallThickness;
            break;
        default:
            cout << "\nIt looks like something went wrong :(\n";
    }
    bool thinWall = ((OutsideDiameter/WallThickness) >= 12);
    cout << "\n\nPressure(Kpa): ";
    cin >> Pressure;
    /*cout << OutsideDiameter << " Meters\n" << InsideDiameter << " Meters\n" << WallThickness << " Meters\n" << Pressure << "Kpa\n";*/
    cout << "\n\n\n";
    if (thinWall) {
        cout << "This is a thin walled pressure vessel. All of the following calculations are coinsidered to be within tolerance.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n\n";
    }
    else if (thinWall == false) {
        cout << "This is NOT a thin walled pressure vessel. The following calculations(with the possible exception of Lames Formula) are coinsidered out of tolerance, and should only be used for educational purposes.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n" ; 
    }
    cout << "OD= " << OutsideDiameter << "(m)  ID= " <<  InsideDiameter << "(m)  t= " <<  WallThickness << "(m)  P= " << Pressure << "(Kpa)\n\n";
    sleep_for(2s);
    cout << "\nStress\n+++++++++++\n\n";
    for (int i=0;i<5;i++){
        cout << method(i) << "\n''''''''''''''''\n" << stress(OutsideDiameter, InsideDiameter, WallThickness, Pressure, i) << " Kpa\n\n";
    }

    return 0;
}

int PressureInterface() {
    double Stress = 0;
    int IDOD = -1;
    double OutsideDiameter = 0;
    double InsideDiameter = 0;
    double WallThickness = 0;
    cout << "\nPressure\n+++++++++++\n\n";
    cout << "Wall Thickness(meters): ";
    cin >> WallThickness;
    cout << "\n\n1:Inside Diameter\n2:Outside Diameter\n\nEnter 1-2: ";
    cin >> IDOD;
    switch (IDOD)
    {
        case 1:
            cout << "\n\nInside Diameter(meters): ";
            cin >> InsideDiameter;
            OutsideDiameter = InsideDiameter + 2 * WallThickness;
            break;
        case 2:
            cout << "\n\nOutside Diameter(meters): ";
            cin >> OutsideDiameter;
            InsideDiameter = OutsideDiameter - 2 * WallThickness;
            break;
        default:
            cout << "\nIt looks like something went wrong :(\n";
    }
    bool thinWall = ((OutsideDiameter/WallThickness) >= 12);
    cout << "\n\nStress(Kpa): ";
    cin >> Stress;
    cout << "\n\n\n";
    if (thinWall) {
        cout << "This is a thin walled pressure vessel. All of the following calculations are coinsidered to be within tolerance.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n\n";
    }
    else if (thinWall == false) {
        cout << "This is NOT a thin walled pressure vessel. The following calculations(with the possible exception of Lames Formula) are coinsidered out of tolerance, and should only be used for educational purposes.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n\n" ; 
    }
    cout << "OD= " << OutsideDiameter << "(m)  ID= " <<  InsideDiameter << "(m)  t= " <<  WallThickness << "(m)  S= " << Stress << "(Kpa)\n\n";
    sleep_for(2s);
    cout << "\nPressure\n+++++++++++\n\n";
    for (int i=0;i<5;i++){
        cout << method(i) << "\n''''''''''''''''\n" << pressure(OutsideDiameter, InsideDiameter, WallThickness, Stress, i) << " Kpa\n\n";
    }

    return 0;
}

int WallInterface() {
    /*Syntax Reminder: double stress(double odia, double idia, double thic, double pres, int meth)*/
    double Stress = 0;
    double Pressure = 0;
    double InsideDiameter = 0;
    cout << "\nWall Thickness\n+++++++++++\n\n";
    cout << "\n\nInside Diameter(meters): ";
    cin >> InsideDiameter;
    cout << "\n\nStress(Kpa): ";
    cin >> Stress;
    cout << "\n\nPressure(Kpa): ";
    cin >> Pressure;
    double WallThickness = wallthickness(InsideDiameter, Pressure, Stress, 2);
    double OutsideDiameter = (InsideDiameter + 2*WallThickness);
    bool thinWall = ((OutsideDiameter/WallThickness) >= 12);
    cout << "\n\n\n";
    if (thinWall) {
        cout << "This is a thin walled pressure vessel. All of the following calculations are coinsidered to be within tolerance.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n\n";
    }
    else if (thinWall == false) {
        cout << "This is NOT a thin walled pressure vessel. The following calculations(with the possible exception of Lames Formula) are coinsidered out of tolerance, and should only be used for educational purposes.\n D/t = " << (OutsideDiameter/WallThickness) << "\n\n" ; 
    }
    cout << "OD= " << OutsideDiameter << "(m)  ID= " <<  InsideDiameter << "(m)  P= " <<  Pressure << "(Kpa)  S= " << Stress << "(Kpa)\n\n";
    sleep_for(2s);
    cout << "\nWall Thickness\n+++++++++++\n\n";
    for (int i=0;i<5;i++){
        cout << method(i) << "\n''''''''''''''''\n" << wallthickness(InsideDiameter, Pressure, Stress, i) << " M\n\n";
    }

    return 0;
}


int interface() {
    int userinput1;
    cout << "\n\nTo begin, select the desired calculation from the options below.";
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "\n1:Hoop stress(Kpa) <-- Pressure(Kpa), Inside/Outside Diameter(M), Wall Thickness(M)\n";
    cout << "\n2:Pressure(Kpa) <-- Hoop Stress(Kpa), Inside/Outside Diameter(M), Wall thickness(M)\n";
    cout << "\n3:Wall Thickness(M) <-- Pressure(Kpa), Hoop Stress(Kpa), Inside Diameter(M)\n\n";
    cout << "Enter 1-3:";
    cin >> userinput1;
    cin.ignore(100, '\n');
    switch (userinput1)
    {
        case 1:
            HoopInterface();
            break;
        case 2:
            PressureInterface();
            break;
        case 3:
            WallInterface();
            break;
        default:
            cout << "\nIt looks like something went wrong. Invalid input can cause the program to end prematurely. \n";
            cin.clear();
            cin.ignore(10000, '\n');
            return 1;
    }

    return 1;
}


int main () {
    string lzy;
    cout << "\n                                                                     @                                                          " ;
    cout << "\n                                                                     @@                                                         " ;
    cout << "\n                                                                     @                                                          " ;
    cout << "\n                                                         @@@@@@@@@@@@@@@@@@@@@@@@@                                              " ;
    cout << "\n                                                   @@@@@    @@    @@     @@    @@   @@@@                                        " ;
    cout << "\n                                              @@@@@    @@@    @@    @@@   @@@    @@    @@@@@@                                   " ;
    cout << "\n                                           @@@@    @@    @@     @@@@@@@@@@  @@     @@    @@  @@@                                " ;
    cout << "\n                                        @@    @@     @@  @@@@        @@       @@@@@ @@     @@    @@                             " ;
    cout << "\n                                     @@@  @@    @@@@@@@  @@         @@@         @@  @@@@@    @@    @@@                          " ;
    cout << "\n                                   @@@@@    @@ @@@       @@@@      @@@@@       @@@       @@@  @@@    @@@                        " ;
    cout << "\n                                 @@    @@   @@@@         @@@@@     @@@@@     @@@@@         @@@@ @@     @@@                      " ;
    cout << "\n                               @@  @@    @@@   @@@       @@@@        @@       @@@@       @@@@  @@@@@    @@@@                    " ;
    cout << "\n                              @@    @@@@@      @@@@@       @@        @@       @@       @@@@@      @@@@    @@@@                  " ;
    cout << "\n                            @@  @@   @@        @@@@@        @@       @@      @@@        @@@@        @@@@    @@@                 " ;
    cout << "\n                           @@@    @@@@@@          @@@       @@       @@      @@        @@          @@@@@@     @@                " ;
    cout << "\n                         @@  @@@  @@  @@@@@@       @@@       @@      @@     @@@       @@        @@@@@  @@@@@    @@              " ;
    cout << "\n                        @@@    @@@     @@@@@        @@@      @@      @@     @@      @@@         @@@@     @@@@    @@             " ;
    cout << "\n                       @@  @@  @@       @@@@@        @@@      @@     @@     @@      @@        @@@ @       @@ @@   @@            " ;
    cout << "\n                      @@    @@@@            @@@       @@@     @@     @     @@     @@@       @@@             @  @@  @@           " ;
    cout << "\n                     @@ @@   @@@@@@           @@@      @@@           @           @@@       @@            @@@@@   @@ @@          " ;
    cout << "\n                     @    @@@@ @@@@@@           @@       @           @@          @@      @@@            @@@@  @   @@ @@         " ;
    cout << "\n                    @@@    @@    @@@@@@          @@@                 @                 @@@          @@@@      @@    @@@         " ;
    cout << "\n                   @@  @@  @          @@@@         @@                                 @@         @@@@          @@@    @@        " ;
    cout << "\n                   @@    @@               @@@                                                  @@               @ @@   @        " ;
    cout << "\n                  @@@@@  @@                 @@@@@                    @@               @@@   @@                   @ @@   @       " ;
    cout << "\n                  @   @@@@@@@@@@@               @         @@@@@      @@              @@@                  @@@@@@@@@  @@ @       " ;
    cout << "\n                 @@@    @@  @@@@@@@@@@                   @@  @@                      @@               @@@@@@@@@  @@    @@@      " ;
    cout << "\n                 @  @@  @@     @    @@@@@@@@             @@@@@       @                         @@@@@@@@    @      @@     @      " ;
    cout << "\n                 @   @@@@                  @@@@          @                    @@@@          @@@@@                 @@@@@  @      " ;
    cout << "\n                 @@    @@                                            @@     @@@                                   @@  @@ @@     " ;
    cout << "\n                 @ @@  @@     @                                      @@  @@                                 @     @@    @@@     " ;
    cout << "\n             @@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@     @@@     @@@@ @@@ @@@@    @@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@  @@@" ;
    cout << "\n\nThis analysis tool can approximate Stress, Pressure, and Wall Thickness in various boiler, pressure vessel, and piping applications.\nIt provides the 5 most common analysis formulas, and allows the user to compare them side by side. Barlow's, Membrane, Lame's, Average, and boardmans formulas are utalized. Lame being the most accurate.\n\n Benjamin Morgan-Butcher for phys250";
    int good = 1;
    while (good == 1) {
        good = interface();
        cout << "\nEnter any key: ";
        cin >> lzy;
        } 
    return 0;
}
