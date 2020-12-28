#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <iostream>
#include <stdexcept>
#include <list>
#include "MPQ.h"
using namespace std;

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
public:
    T remove_min() {
        if (!elements.empty()) {
            T min = elements.front();
            elements.pop_front();
            return min;
        }
        else {
            throw "Empty Heap";
        }
    }
    T min() {
        if (!elements.empty()) {
            return elements.front();
        }
        throw "Empty Heap";
    }
    bool is_empty() {
        return elements.empty();
    }
    void insert(const T& data) {
        if (!elements.empty()) {
            typename list<T>::iterator i; 
            bool added = false;
            for(i = elements.begin(); i != elements.end(); i++) {
                if (data < *i) {
                    elements.insert(i, data);
                    added = true;
                    break;
                }
            }
            if (!added) {
                elements.push_back(data);
            }
        }
        else {
            elements.push_back(data);
        }
    }

private:
    list<T> elements;
};

#endif