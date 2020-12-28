#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
public:
    T remove_min() {
        return elements.remove_min();
    }
    T min() {
        return elements.min();
    }
    bool is_empty() {
        return elements.is_empty();
    }
    void insert(const T& data) {
        elements.insert(data);
    }

private:
    BinaryHeap<T> elements;
};

#endif