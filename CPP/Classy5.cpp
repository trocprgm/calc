#include <iostream>

using namespace std;

int lastIndex(int a[], int size, int Perp) {
    for (int i = (size - 1); i > 0; i--) {
        if (a[i] == Perp) return i;
    }
    return -1;
}

int main() {
    int Arry[] = {1,2,4,4,5};
    //int Arry[] = {1,2,3,2,5};
    const int Size = 5;
    cout << lastIndex(Arry, Size, 4) << endl;
    return 0;
}


