#include <iostream>

using namespace std;
//Problem 3 Exam 1

void shiftPrint(int a[], int size) {
    cout << a[size - 1] << endl;
    for(int i = 0; i < size -1; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    shiftPrint(arr, 10);
    return 0;
}
