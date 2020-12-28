#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"
using namespace std;

/*
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
public:
    T remove_min() {
        if (elements.size() != 0) {
            T min = elements[0];
            int idx = 0;
            for (int i = 1; i < elements.size(); i++) {
                if (elements[i] < min) {
                    min = elements[i];
                    idx = i;
                }
            }
            elements.erase(elements.begin() + idx);
            return min;
        }
        throw "Empty Heap";
    }
    T min() {
        if (elements.size() != 0) {
            T min = elements[0];
            for (int i = 1; i < elements.size(); i++) {
                if (elements[i] < min) {
                    min = elements[i];
                }
            }
            return min;
        }
        throw "Empty Heap";
    }
    bool is_empty() {
        return (elements.size() == 0);
    }
    void insert(const T& data) {
        elements.push_back(data);
    }

private:
    vector<T> elements;
};

#endif