// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DLList; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode {
  T obj;
  DLListNode<T> *prev, *next;
  // constructor
  DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList {
private:
  DLListNode<T> header, trailer;
public:
  DLList<T>() : header(DLListNode<T>(T())), trailer(DLListNode<T>(T())) {
        header.next = &trailer;
        trailer.prev = &header;
  }
  DLList<T>(const DLList<T>& dll) {
        DLListNode<T> *curr = dll.header.next;
        header.next = &trailer;
        trailer.prev = &header;
        while (curr != dll.after_last_node()) {
            this->insert_last(curr->obj);
            curr = curr->next;
        }
  }
  DLList<T>(DLList<T>&& dll) {
        if (dll.is_empty()) {
            header.next = &trailer;
            trailer.prev = &header;
        }
        else {
            header.next = dll.header.next;
            header.next->prev = &header;
            trailer.prev = dll.trailer.prev;
            trailer.prev->next = &trailer;
            dll.header.next = &dll.trailer;
            dll.trailer.prev = &dll.header;
        }
  }
  ~DLList<T>() {
        DLListNode<T> *prev, *curr = header.next;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        header.next = &trailer;
        trailer.prev = &header;
  }
  DLList<T>& operator=(const DLList<T>& dll) {
        if (&dll != this) {
            if (!this->is_empty()) {
                this->~DLList();
            }
            DLListNode<T> *curr = dll.first_node();
            header.next = &trailer;
            trailer.prev = &header;
            while (curr != dll.after_last_node()) {
                insert_last(curr->obj);
                curr = curr->next;
            }
        }
        return *this;
  }
  DLList<T>& operator=(DLList<T>&& dll) {
        if (&dll != this) {
            this->~DLList();
            if (dll.is_empty()) {
                header.next = &trailer;
                trailer.prev = &header;
            } else {
                header.next = dll.header.next;
                header.next->prev = &header;
                trailer.prev = dll.trailer.prev;
                trailer.prev->next = &trailer;
                dll.header.next = &dll.trailer;
                dll.trailer.prev = &dll.header;
            }
        }
        return *this;
  }
  DLListNode<T>* first_node() const {
      return header.next;
  }
  const DLListNode<T>* after_last_node() const {
      return &trailer;
  }
  bool is_empty() const {
      return (header.next == &trailer);
  }
  T first() const {
        if (this->is_empty()) {throw "List is Empty";}
        return header.next->obj;
  }
  T last() const {
        if (this->is_empty()) {throw "List is Empty";}
        return trailer.prev->obj;
  }
  void insert_first(T obj) {
        DLListNode<T> *x = new DLListNode<T>(obj);
        header.next->prev = x;
        x->next = header.next;
        header.next = x;
        x->prev = &header;
  }
  T remove_first() {
        if (this->is_empty()) {throw "List is Empty";}
        DLListNode<T> *x = header.next;
        header.next = x->next;
        x->next->prev = &header;
        T y = x->obj;
        delete x;
        return y;
  }
  void insert_last(T obj) {
        DLListNode<T> *x = new DLListNode<T>(obj);
        trailer.prev->next = x;
        x->prev = trailer.prev;
        trailer.prev = x;
        x->next = &trailer;
  }
  T remove_last() {
        if (this->is_empty()) {throw "List is Empty";}
        DLListNode<T> *x = trailer.prev;
        x->prev->next = &trailer;//switch next line
        trailer.prev = x->prev;
        T y = x->obj;
        delete x;
        return y;
  }
  void insert_after(DLListNode<T> &p, T obj) {
        if (this->is_empty()) {throw "List is Empty";}
        DLListNode<T> *x = new DLListNode<T>(obj);
        p.next->prev = x;
        x->next = p.next;
        x->prev = &p;
        p.next = x;
  }
  void insert_before(DLListNode<T> &p, T obj) {
        if (this->is_empty()) {throw "List is Empty";}
        DLListNode<T> *x = new DLListNode<T>(obj);
        p.prev->next = x;
        x->prev = p.prev;
        x->next = &p;
        p.prev = x;
  }
  T remove_after(DLListNode<T> &p) {
        if (this->is_empty()) {throw "List is Empty";}
        if (&trailer == p.next) {throw "Not possible to remove trailer node";}
        DLListNode<T> *x = p.next;
        x->next->prev = &p;
        p.next = x->next;
        T y = x->obj;
        delete x;
        return y;
  }
  T remove_before(DLListNode<T> &p) {
        if (this->is_empty()) {throw "List is Empty";}
        if (&header == p.prev) {throw "Not possible to remove trailer node";}
        DLListNode<T> *x = p.prev;
        x->prev->next = &p;
        p.prev = x->prev;
        T y = x->obj;
        delete x;
        return y;
  }
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll) {
    try {
        if (!dll.is_empty()) {
            DLListNode<T> *x = dll.first_node();
            while (x != dll.after_last_node()) {
                out << x->obj << ", ";
                x = x->next;
            }
        }
        else {
            throw "List is Empty";
        }
    }
    catch (const char *e) {
        cout << e << endl;
    }
    return out;
}


#endif