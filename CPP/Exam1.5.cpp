#include <iostream>

using namespace std;

//Problem 5 exam 1

bool has5(int a[], int size) {
    for(int i = 0; i < size; i++) {
        if(a[i] == 5) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[10] = {0,1,2,3,4,5,7,8,9,10};
    if(has5(arr,10) == 1) {
        cout << "Array has 5\n";
    }
    else {
        cout << "Array does not have 5\n";
    }
    return 0;
}





