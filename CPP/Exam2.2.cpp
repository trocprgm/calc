#include <iostream>

using namespace std;

// Exam 2 Problem 2


void sort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int k = 0; k< size - 1; k++) {
           if(array[k] > array[k + 1]) {
               int temp = array[k];
               array[k] = array[k+1];
               array[k+1] = temp;
           }
        }
    }
}

void printarr(int array[], int size) {
    cout << "####" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }
    cout << "####" << endl << endl;
}

int main() {
    int array[] = {2,1,5,4,3,8};
    int size = 6;
    printarr(array,size);
    sort(array,size);
    printarr(array,size);
    return 0;
}

