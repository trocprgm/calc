#include <iostream>
#include <string>

using namespace std;

class Employee
{
    private:
        int num;
        string *name;
    public:
        Employee () {}
        Employee (const Employee &samp) {
            name = samp.name;
            num = samp.num;
        }
        void printData() {
            cout << *name << endl << num << endl;
        }

        void setEmpData(string namey,int numy) {
            name = new string(namey);
            num = numy;
        }
};

int main() {
    Employee Lee;
    Lee.setEmpData("Lee",10);
    Employee Low(Lee);
    Low.setEmpData("Low",20);
    Low.printData();
    Lee.printData();
    return 0;
}

