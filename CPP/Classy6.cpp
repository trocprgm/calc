#include <iostream>

using namespace std;

void RshiftPrint(int a[], int size) {
    cout << "Right Shift:\n";
    cout << a[size -1] << endl;
    for (int i = 0; i < (size - 1); i++) cout << a[i] << endl;
}

void LshiftPrint(int a[], int size) {
    cout << "Left Shift:\n";
    for (int i = 1; i < size; i++) cout << a[i] << endl;
    cout << a[0] << endl;
}
int main() {
    int Arr[] = {4,3,2,1};
    int Size = 4;
    RshiftPrint(Arr,Size);
    LshiftPrint(Arr,Size);
    return 0;
}
