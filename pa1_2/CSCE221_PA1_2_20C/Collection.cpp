#include "Collection.h"
#include "Stress_ball.h"
#include <string>
#include <fstream>

void Collection::resize() {
    if (array == nullptr) {
        capacity = 1;
        array = new Stress_ball[1];
    }
    else {
        capacity *= 2;
        Stress_ball *temp = new Stress_ball[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
}
Collection::Collection() {
    size = 0;
    capacity = 0;
    array = nullptr;
}
Collection::Collection(int cap) : size(0), capacity(cap), array(new Stress_ball[cap]) {}
Collection::Collection(const Collection& c) : size(c.size), capacity(c.capacity), array(new Stress_ball[c.capacity]) {
    std::copy(c.array, c.array + c.size, array);
}
Collection& Collection::operator=(const Collection& c) {
    if (this != &c) {
        delete[] array;
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[c.capacity];
        std::copy(c.array, c.array + c.size, array);
      }
      return *this;
}
Collection::~Collection() {
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}
Collection::Collection(Collection&& c) : size(c.size), capacity(c.capacity) {
    if (!array)
        delete[] array;
    array = std::move(c.array);
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;
}
Collection& Collection::operator=(Collection&& c) {
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
void Collection::insert_item(const Stress_ball& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
}
bool Collection::contains(const Stress_ball& sb) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}
Stress_ball Collection::remove_any_item() {
    if (size == 0) {
        throw "Size of array is 0";
    }
    else {
        srand(time(NULL));
        int r = rand() % size;
        Stress_ball x(array[r].get_color(), array[r].get_size());
        for (int i = r; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        return x;
    }
}
void Collection::remove_this_item(const Stress_ball& sb) {
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
void Collection::make_empty() {
    this->~Collection();
}
bool Collection::is_empty() const {
    return (size == 0);
}
int Collection::total_items() const {
    return size;
}
int Collection::total_items(Stress_ball_sizes s) const {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_size() == s) {
            cnt++;
        }
    }
    return cnt;
}
int Collection::total_items(Stress_ball_colors t) const {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_color() == t) {
            cnt++;
        }
    }
    return cnt;
}
void Collection::print_items() const {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << std::endl;
    }
}
Stress_ball& Collection::operator[](int i) {
    return array[i];
}
const Stress_ball& Collection::operator[](int i) const {
    return array[i];
}

istream& operator>>(istream& is, Collection& c) {
    string x;
    while (getline(is, x)) {
        int idx = x.find(" ");
        string colour = x.substr(0, idx);
        string size = x.substr(idx + 1);

        Stress_ball_colors col;
        Stress_ball_sizes sz;
        if (colour == "red") {col = Stress_ball_colors::red;}
        else if (colour == "blue") {col = Stress_ball_colors::blue;}
        else if (colour == "green") {col = Stress_ball_colors::green;}
        else {col = Stress_ball_colors::yellow;}
        if (size == "small") {sz = Stress_ball_sizes::small;}
        else if (size == "medium") {sz = Stress_ball_sizes::medium;}
        else {sz = Stress_ball_sizes::large;}

        c.insert_item(Stress_ball(col, sz));
    }
    return is;
}
ostream& operator <<(ostream& os, const Collection& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << c[i] << std::endl;
    }
    return os;
}
Collection make_union(const Collection& c1, const Collection& c2) {
    Collection c3;
    for (int i = 0; i < c1.total_items(); i++) {
        c3.insert_item(c1[i]);
    }
    for (int i = 0; i < c2.total_items(); i++) {
        c3.insert_item(c2[i]);
    }
    return c3;
}
void swap(Collection& c1, Collection& c2) {
    Collection c3(c2);
    c2 = c1;
    c1 = c3;
}
void sort_by_size(Collection& c, Sort_choice sort) {
    int size = c.total_items();
    switch (sort) {
        case Sort_choice::bubble_sort:
            bool swap;
            for (int i = 0; i < size - 1; i++) {
                swap = false;
                for (int j = 0; j < size - i - 1; j++) {
                    if (c[j].get_size() > c[j + 1].get_size()) {
                        Stress_ball temp(c[j + 1]);
                        c[j + 1] = c[j];
                        c[j] = temp;
                        swap = true;
                    }
                }
                if (!swap) {break;}
            }
        case Sort_choice::insertion_sort:
            for (int i = 0; i < size; i++) {
                Stress_ball key(c[i]);
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
                Stress_ball temp(c[i]);
                c[i] = c[idx];
                c[idx] = temp;
            }
    }
}