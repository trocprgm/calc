#include <iostream>
#include <string>

using namespace std;

class Department
{
    private:
        int deptId;
        string name;
        int totalEmp;
    public:
        Department(int d, string n, int t) : deptId(d), name(n), totalEmp(t) {
            cout << "You've used the parametric constructor to make a Department object!\n";
        }
        int operator + (Department& a) {
            return (totalEmp + a.totalEmp);
        }
        int operator - (Department& a) {
            return (totalEmp - a.totalEmp);
        }

};

int main()
{
    Department dept1(100,"COMP",10);
    Department dept2(20,"Math",20);
    cout << (dept1 + dept2) << endl;
    return 0;
}
