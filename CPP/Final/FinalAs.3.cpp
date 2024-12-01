#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>

using namespace std;

class Employee {
    public:
        Employee() {}
        Employee(int I, string n, int d) : Id(I),Name(n),Dept(d) {}
        void print() {
            cout << Id << endl << Name << endl << Dept << endl;
        }
    private:
        int Id;
        string Name;
        int Dept;
};


int main()
{
    ifstream inFile;
    inFile.open("empData.txt");
    string inputID;
    string inputString1;
    string inputDept;
    getline(inFile, inputID, ',');
    getline(inFile, inputString1, ',');
    getline(inFile, inputDept, ',');
    int inID = stoi(inputID);
    Employee Emp1(stoi(inputID),inputString1,stoi(inputDept));
    Emp1.print();

    inFile.close();
    return 0;
}


