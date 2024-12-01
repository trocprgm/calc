#include <iostream>

using namespace std;

//Exam 2 Problem 3

int LastIndex(int a[], int size, int perp) {
    for(int i = size -1; i > -1; i--) {
        //cout << "checking: " << i << endl;
        if(a[i] == perp) return i;
    }
    cout << "Not Found" << endl;
    return -1;
}

int main() {
    int array[5] = {1,2,3,4,2}; 
    cout << LastIndex(array, 5, 2);
    return 0;
}
