#include <iostream>
#include <string>

using namespace std;

class Employee
{
    public:
        string name;
        int sal;
        Employee() {}
        Employee(string namey, int saly) {
            sal = saly;
            name = namey;
        }
        const int operator + (const Employee& a) {
            return sal + a.sal;
        } 
};

int main() {
    Employee Lee("Lee",123);
    Employee Low("Low",123);
    cout << (Low + Lee) << endl;
    return 0;
}
