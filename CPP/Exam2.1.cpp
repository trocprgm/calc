#include <iostream>

using namespace std;

//Exam 2 Problem 1

int sum3(int a[], int size) {
    int running = 0;
    if (size <= 3) {
        for (int i = 0; i < size; i++) {
            running += a[i];
        }
    }
    else if (size > 3) {
        for (int i = 0; i < 3; i++) {
            running += a[i];
        }
    }

    return running;
}

int main() {
    int array[] = {2,1,5,4,3,8}; 
    cout << sum3(array, 6) << endl;
    return 0;
}


