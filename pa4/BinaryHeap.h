#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        void insert(const T& data) {
            elements.push_back(data);
            up_heap(size);
            size++;
        }
        bool is_empty() {
            return (size == 0);
        }
        T min() {
            if (size != 0) {
                //T min = *min_element(elements.begin(), elements.end());
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
        T remove_min() {
            if (size != 0) {
                T min = elements[0];
                elements[0] = elements[--size];
                elements.erase(--elements.end());
                down_heap(0);
                return min;
            }
            throw "Empty Heap";
        }
    private:
        std::vector<T> elements;
        int size = 0;
        void down_heap(int i);
        void up_heap(int i);

        //Pre-implemented helper functions
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        int right_child(int i) {return 2*i + 2;}
        int left_child(int i) {return 2*i + 1;}
        int parent(int i) {return floor((i-1)/2);}
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i) {
    while (i > 0 && elements[i] < elements[parent(i)]) { 
        swap(parent(i), i); 
        i = parent(i); 
    } 
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i) {
    int r = right_child(i);
    int l = left_child(i);
    int idx = i; 
    if (l <= size && elements[l] < elements[idx]) { 
        idx = l; 
    } 
    if (r <= size && elements[r] < elements[idx]) { 
        idx = r; 
    } 
    if (i != idx) { 
        swap(i, idx); 
        down_heap(idx); 
    } 
}
#endif
