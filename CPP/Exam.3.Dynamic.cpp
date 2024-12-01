#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Employee {
    public:
        Employee() {}
        Employee(int I, string n, int d) : Id(I),Name(n),Dept(d) {}
        Employee(const Employee& empl) {
            Id = empl.Id;
            //Name = new string(*empl.Name);
            Name = empl.Name;
            Dept = empl.Dept;
        }
        void print() {
            cout << Id << endl << Name << endl << Dept << endl << endl;
        }
        void SetEmpData(int I, string n, int d) {
            Id = I;
            Name = n;
            Dept = d;
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
    inFile.close();

    Employee Emp1(stoi(inputID),inputString1,stoi(inputDept));
    Emp1.print();
    Employee Emp2(Emp1);
    Emp2.SetEmpData(1,"Rob",30);

    Emp2.print();
    Emp1.print();

    return 0;
}


