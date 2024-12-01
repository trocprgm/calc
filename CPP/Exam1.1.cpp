#include <iostream>

using namespace std;

//Problem 1 Exam 1

void OddPrint(int a[], int size) {
    for(int i = 1; i < size; i += 2) {
        cout << a[i] << endl;
    }
}

int main() {
    int SampArr[] = {0,1,2,3,4,5};
    OddPrint(SampArr,6);
    return 0;
}
