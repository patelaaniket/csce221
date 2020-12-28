#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

class Empty_Collection{};

template<typename Obj, typename F1, typename F2>
class Collection{
    Obj* array;
    int size;
    int capacity;
    void resize() {
        if (array == nullptr) {
            capacity = 1;
            array = new Obj[1];
        }
        else {
            capacity *= 2;
            Obj *temp = new Obj[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
    }
public:
Collection<Obj, F1, F2>() {
    size = 0;
    capacity = 0;
    array = nullptr;
}
Collection<Obj, F1, F2>(int cap) : size(0), capacity(cap), array(new Obj[cap]) {}
Collection<Obj, F1, F2>(const Collection& c) : size(c.size), capacity(c.capacity), array(new Obj[c.capacity]) {
    std::copy(c.array, c.array + c.size, array);
}
Collection<Obj, F1, F2>& operator=(const Collection& c) {
    if (this != &c) {
        delete[] array;
        size = c.size;
        capacity = c.capacity;
        array = new Obj[c.capacity];
        std::copy(c.array, c.array + c.size, array);
      }
      return *this;
}
~Collection<Obj, F1, F2>() {
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}
Collection<Obj, F1, F2>(Collection<Obj, F1, F2>&& c) : size(c.size), capacity(c.capacity) {
    if (!array)
        delete[] array;
    array = std::move(c.array);
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;
}
Collection<Obj, F1, F2>& operator=(Collection&& c) {
    size = c.size;
    capacity = c.capacity;
    if (!array)
        delete[] array;
    array = std::move(c.array);
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;
    return *this;
}
void insert_item(const Obj& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
}
bool contains(const Obj& sb) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}
Obj remove_any_item() {
    if (size == 0) {
        throw "Size of array is 0";
    }
    else {
        srand(time(NULL));
        int r = rand() % size;
        Obj x(array[r].get_color(), array[r].get_size());
        for (int i = r; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        return x;
    }
}
void remove_this_item(const Obj& sb) {
    if (size == 0) {
        throw "Size of array is 0";
    }
    else {
        int idx = -1;
        for (int i = 0; i < size; i++) {
            if (array[i] == sb) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            for (int i = idx; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
        
    }
}
void make_empty() {
    this->~Collection();
}
bool is_empty() const {
    return (size == 0);
}
int total_items() const {
    return size;
}
int total_items(F2 s) const {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_size() == s) {
            cnt++;
        }
    }
    return cnt;
}
int total_items(F1 t) const {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_color() == t) {
            cnt++;
        }
    }
    return cnt;
}
void print_items() const {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << std::endl;
    }
}
Obj& operator[](int i) {
    return array[i];
}
const Obj& operator[](int i) const {
    return array[i];
}
};

template<typename Obj, typename F1, typename F2>
ostream& operator <<(ostream& os, const Collection<Obj, F1, F2>& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << c[i] << std::endl;
    }
    return os;
}
template<typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> c3;
    for (int i = 0; i < c1.total_items(); i++) {
        c3.insert_item(c1[i]);
    }
    for (int i = 0; i < c2.total_items(); i++) {
        c3.insert_item(c2[i]);
    }
    return c3;
}
template<typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> c3(c2);
    c2 = c1;
    c1 = c3;
}
template<typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort) {
    int size = c.total_items();
    switch (sort) {
        case Sort_choice::bubble_sort:
            bool swap;
            for (int i = 0; i < size - 1; i++) {
                swap = false;
                for (int j = 0; j < size - i - 1; j++) {
                    if (c[j].get_size() > c[j + 1].get_size()) {
                        Obj temp(c[j + 1]);
                        c[j + 1] = c[j];
                        c[j] = temp;
                        swap = true;
                    }
                }
                if (!swap) {break;}
            }
        case Sort_choice::insertion_sort:
            for (int i = 0; i < size; i++) {
                Obj key(c[i]);
                int j = i - 1;
                while (j > -1 && c[j].get_size() > key.get_size()) {
                    c[j + 1] = c[j];
                    j -= 1;
                }
                c[j + 1] = key;
            }
        case Sort_choice::selection_sort:
            for (int i = 0; i < size - 1; i++) {
                int idx = i;
                for (int j = i + 1; j < size; j++) {
                    if (c[j].get_size() < c[idx].get_size()) {
                        idx = j;
                    }
                }
                Obj temp(c[i]);
                c[i] = c[idx];
                c[idx] = temp;
            }
    }
}

#endif