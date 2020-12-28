#include <iostream>
using namespace std;

int getMax(int a[], int s) {
    if (s != 1) {
        return max(a[s - 1], getMax(a, s - 1));
    }
    return a[0];
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Max value for a1: " << getMax(a1, 10) << endl;

    int a2[] = {1, 2, 3, 4, 25, 6, 7, 8, 10};
    cout << "Max value for a2: " << getMax(a2, 9) << endl;

    int a3[] = {1000, 2, 10};
    cout << "Max value for a3: " << getMax(a3, 3) << endl;
}