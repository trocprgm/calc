#include <iostream>

using namespace std;

//Exam 2 Problem 5

void post8(int a[], int size) {
    int last8 = -1;
    for(int i = size -1; i > -1; i--) {
        //cout << "checking: " << i << endl;
        if(a[i] == 8) last8 = i;
    }
    for(int i = last8 + 1; i < size; i++) {
        cout << a[i] << endl;
    }

}

int main() {
    int arr[] = {1,2,3,4,8,5,6,7,3,4};
    const int size = 10;
    post8(arr, size);
    return 0;
}


