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

void EvenPrint(const int Myarray[], const int MyarraySize) {
    cout << "Evens: ";
    for (int i = 0; i<MyarraySize; i += 2) cout << Myarray[i] << ", ";
    cout << endl;
}

void OddPrint(const int Myarray[], const int MyarraySize) {
    cout << "Odds: ";
    for (int i = 1; i<MyarraySize; i += 2) cout << Myarray[i] << ", ";
    cout << endl;
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
    //int Arr[5] = {1,2,3,4,5};
    const int MyarraySize = 5;
    const int Myarray[MyarraySize] = {1,2,3,4,5};
    cout << "Sum: " <<  Sum(Myarray,MyarraySize) << endl;
    cout << "Min: " << Min(Myarray,MyarraySize) << endl;
    cout << "Max: " << Max(Myarray,MyarraySize) << endl;
    EvenPrint(Myarray,MyarraySize);
    OddPrint(Myarray,MyarraySize);

    cout << endl << endl;
    int Arry[10];
    ArrCin(Arry,10);
    printarr(Arry,10);
}

