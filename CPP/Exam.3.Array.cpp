#include <iostream> 
#include <string>

using namespace std;

void ShiftRight(int a[], int size) {
    cout << a[(size -1)] << " " ;
    for (int i = 0;i < (size -1); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ShiftLeft(int a[], int size) {
    for (int i = 1;i < (size); i++) {
        cout << a[i] << " ";
    }
    cout << a[(0)] << " " ;
    cout << endl;
}


int main() {
    int array[] = {4,2,3,1};
    int size = 4;
    ShiftRight(array,size);
    ShiftLeft(array,size);
    return 0;
}


