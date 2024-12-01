#include <iostream>

using namespace std;

void sort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int k = 0; k< size - 1; k++) {
           if(array[k] < array[k + 1]) {
               int temp = array[k];
               array[k] = array[k+1];
               array[k+1] = temp;
           }
        }
    }
}

void printarr(int array[], int size) {
    cout << "#strt#" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }
    cout << "####" << endl << endl;
}


int main() {
    int arrus[5] = {1,4,5,6,0};
    printarr(arrus,5);
    sort(arrus,5);
    printarr(arrus,5);
    return 0;
}

