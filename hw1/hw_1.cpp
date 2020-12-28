#include <vector>
using namespace std;

/*  O(n)
    The comparision and assignment are considered operations.
    The best case would be if the first two elements are odd. O(2). The first odd element would turn odd true, and the second would make the program return true.
    Ex: {1, 3, 2, 3, 4, 5, 6, 7}
    The worst case would be if the second odd element is at the end of the vector. O(n). This would mean that the function would have to go through every element
    vector.
    Ex: {1, 2, 4, 6, 8, 10, 12, 3}
*/
bool oddProduct1(vector<int> x) {
    bool odd = false;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] % 2 != 0) {
            if (!odd) odd = true;
            else return true;
        }
    }
    return false;
}
/*  O(n^2)
    The comparision and assignemnts are considered operations.
    The best case would be if the first two elements are odd. O(2). It takes the j for-loop 2 iterations to get to the 2nd element and the i for-loop 1 iteration 
    to get to the 1st element. 2 * 1 = 2.
    Ex: {1, 3, 2, 3, 4, 5, 6, 7}
    The worst case would be if the only two odd elements are in the last two positions in the vector. This means that it would take the i for-loop n-1 iterations 
    and the j for-loop n iterations. n(n - 1) = n^2 - n.
    Ex: {2, 4, 6, 8, 10, 12, 1, 3}
*/
bool oddProduct2(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            if (i != j && (x[i] * x[j]) % 2 != 0) {
                return true;
            }
        }
    }
    return false;
}
