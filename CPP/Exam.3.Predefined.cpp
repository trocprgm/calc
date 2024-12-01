#include <iostream>
#include <vector>

using namespace std;

int max(vector<int> vec) {
    int max = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max) max = vec[i];
    }
    return max;
}

int min(vector<int> vec) {
    int min = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < min) min = vec[i];
    }
    return min;
}

float cenAv(vector<int> vec) {
    float dyn = 0;
    for (int i = 0; i < vec.size(); i++) dyn += vec[i];
    dyn = (dyn - max(vec) - min(vec)) /(vec.size() -2);
    return dyn;
}


int main() {
    vector<int> vec= {5,3,3,4,8};
    cout << cenAv(vec) << endl;
    return 0;
}




