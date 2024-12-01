#include <iostream>

using namespace std;

int LastEle(int a[], int size, int perp) {
    for (int i = size - 1; i >= 0; i--) {
        if (a[i] == perp) return i;
    }
    return -1;
}

int main() {
    int Array[] = {1,2,3,4,5};
    int size = 5;
    cout << LastEle(Array,size,3) << endl;
    return 0;
}



