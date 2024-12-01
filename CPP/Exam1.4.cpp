#include <iostream> 

using namespace std;

//Problem 4 exam 1

void printarr(int array[], int size) {
    cout << "#strt#" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }
    cout << "####" << endl << endl;
}

void kill8(int a[], int size) {
    int list[size];
    int run = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] != 8) {
            list[run] = a[i];
            run++;
        }
    }
    for(int i = run; i < size; i++) {
        list[i] = 0;
    }
    printarr(list, size);

}

int main() {
    int arr[10] = {0,1,2,8,4,5,6,7,8,8};
    int size = 10;
    printarr(arr,size);
    kill8(arr,size);
}

                       


