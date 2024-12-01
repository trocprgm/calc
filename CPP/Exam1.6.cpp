#include <iostream>

using namespace std;


int Min(const int Myarray[],const int MyarraySize) {
    int min = Myarray[0];
    for (int i = 0; i<MyarraySize; i++) {
        if (Myarray[i] < min) {
           min = Myarray[i];
        }
    }
    return min;
}
int Max(const int Myarray[],const int MyarraySize) {
    int max = Myarray[0];
    for (int i = 0; i<MyarraySize; i++) {
        if (Myarray[i] > max) {
           max = Myarray[i];
        }
    }
    return max;
}
int Sum(const int Myarray[],const int MyarraySize) {
    int Sum = 0;
    for (int i = 0; i<MyarraySize; i++) {
        Sum += Myarray[i];
    }
    return Sum;
}

void printarr(int array[], int size) {
    cout << "#strt#" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }
    cout << "####" << endl << endl;
}

void ArrCin(int a[], int size) {
    cout << "Input " << size << " Elements\n" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": ";
        cin >> a[i];
        cout << endl;
    }
}

int main() {
    int Arr[5], size = 5;
    ArrCin(Arr,size);
    cout << "Sum: " << Sum(Arr,size) << endl;
    cout << "Min: " << Min(Arr,size) << endl;
    cout << "Max: " << Max(Arr,size) << endl;
    //printarr(Arr,size);
    return 0;
}




