#include <iostream>

using namespace std;

//Exam 2 Problem 6

void reverse(int a[], int size) {
    for(int i = size -1; i > -1; i--) {
        cout << a[i] << endl;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    const int size = 5;
    reverse(arr,size);
    return 0;
}

