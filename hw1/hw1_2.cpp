#include <vector>
#include <iostream>
using namespace std;

int num_comp = 0;

template <typename T>
int Binary_Search(vector<T> &v, T x) {
    int mid, low = 0;
    int high = (int) v.size()-1;
    while (low < high) {
        mid = (low+high)/2;
        if (num_comp++, v[mid] < x) low = mid+1;
        else high = mid;
    }
    if (num_comp++, x == v[low]) return low; //OK: found
    throw Unsuccessful_Search(); //exception: not found
}

int main() {
    vector<int> x;
    for (int i = 2; i < 2049; i*=2) {
        for (int j = 1; j < i; j++) {
            x.push_back(j);
        }
        cout << i - 1 << " " << Binary_Search(x, i -1) << " " << num_comp << endl;
        num_comp = 0;
    }
}