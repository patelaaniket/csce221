#include <iostream>
#include <list>
using namespace std;

list<int> intersection(list<int> l1, list<int> l2) {
    list<int> l3;
    list<int>::iterator i;
    for (i = l1.begin(); i != l1.end(); i++) {
        list<int>::iterator j;
        for (j = l2.begin(); j != l2.end(); j++) {
            if (*i == *j) {
                l3.push_back(*i);
                break;
            }
        }
    }
    return l3;
}

void print_list(list<int> l) {
    list<int>::iterator i;
    for (i = l.begin(); i != l.end(); i++) {
        cout << " " << *i;
    }
}

int main () {
    list<int> l1 = {1, 4, 9, 16, 25};
    list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "List 1: ";
    print_list(l1);
    cout << endl << "List 2: ";
    print_list(l2);
    cout << endl << "Intersection: ";
    print_list(intersection(l1 , l2));
    cout << endl;
    return 0;
}