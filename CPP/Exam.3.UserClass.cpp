#include <iostream>
#include <string>

using namespace std;

class Department {
    private:
        int ID;
        string name;
        int totalEmployess;

    public:
        Department() {}
        Department(int i,string n, int t) : ID(i), name(n), totalEmployess(t) {}
        int operator + (Department a) {
            return a.totalEmployess + totalEmployess;
        }
};

int main() {

    Department dept1(100,"COMP",10); 
    Department dept2(20,"MATH", 20);
    cout<<dept1 + dept2;
    return 0;
}

