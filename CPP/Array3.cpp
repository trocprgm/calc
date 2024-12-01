#include <iostream>

using namespace std;

int indexLook(int a[], int size, int perp) {
    //int result;
    for(int i = 0; i < size; i++) {
        if(a[i] == perp) return i;
    }
    cout << "Not Found" << endl;
    return 0;
}

int main() {
    int array[5] = {1,2,3,4,5};
    cout << indexLook(array, 5, 20);
    return 0;
}

