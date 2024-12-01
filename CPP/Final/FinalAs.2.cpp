#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& array, int size) {
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

void printarr(vector<int> array, int size) {
    cout << "#strt#" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }
    cout << "####" << endl << endl;
}

float centAv(vector<int> a, int size) {
    sort(a, size);
    //printarr(a,size);
    float running = 0;
    if (size > 2) { 
        for (int i = 1; i < size - 1; i++) {
            running += a[i];
        }   
    }
    else if (size <= 2) {
        cout << "Not enough elements for centered average, mean returned\n";
        for (int i = 0; i < size; i++) {
            running += a[i];
        }   
        return running/size;

    }
    return running/(size-2);
}

int main() {
    vector<int> vecy = {5,2,3,4,5};
    const int size = 5;
    vector<int> vecys = {1,2};
    const int sizes = 2;
    //printarr(vecy,size);
    cout << centAv(vecy,size) << endl;
    //printarr(vecy,size);

    return 0;
}

