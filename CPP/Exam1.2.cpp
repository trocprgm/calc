#include <iostream>

using namespace std;

//Problem 2 Exam 1

int sum17(int a[], int size) {
    int Sum = 0;

    for(int i = 0; i<size; i++) {
        if((a[i] != 17 ) and (a[i-1] != 17)) {
            Sum += a[i];
        }
    }
    return Sum;
}

int main() {
    int arr[5] = {1,2,17,100,2};
    cout << sum17(arr,5);
    return 0;
}


