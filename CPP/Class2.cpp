#include <iostream>

using namespace std;

class Employee
{
    private:
    string* name;
    int deptNo;
    public:
    Employee(string ename, int dept)
    {
        name = new string(ename);
        deptNo = dept;
    };
   

int main() {
    Employee emp1;
    return 0;
}

