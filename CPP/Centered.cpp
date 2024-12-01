
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

float centered(int a[], int size) {
    float run = 0;
    for (int i = 1; i < size-1;i++) run += a[i];
    run = run / (size - 2);
    return run;
}

int main() {
    int arrus[5] = {1,2,3,4,5};
    sort(arrus, 5);
    cout << centered(arrus,5);
    return 0;
}

    

