#include "DLList.h"

DLList::DLList() : header(DLListNode(0)), trailer(DLListNode(0)) {
    header.next = &trailer;
    trailer.prev = &header;
}

DLList::DLList(const DLList& dll) {
    DLListNode *curr = dll.header.next;
    header.next = &trailer;
    trailer.prev = &header;
    while (curr != dll.after_last_node()) {
        this->insert_last(curr->obj);
        curr = curr->next;
    }
}
DLList::DLList(DLList&& dll) {
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
DLList::~DLList() {
    DLListNode *prev, *curr = header.next;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    header.next = &trailer;
    trailer.prev = &header;
}
DLList& DLList::operator=(const DLList& dll) {
    if (&dll != this) {
		if (!this->is_empty()) {
            this->~DLList();
		}
        DLListNode *curr = dll.first_node();
		header.next = &trailer;
		trailer.prev = &header;
		while (curr != dll.after_last_node()) {
			insert_last(curr->obj);
			curr = curr->next;
		}
	}
	return *this;
}
DLList& DLList::operator=(DLList&& dll) {
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
DLListNode* DLList::first_node() const {
    return header.next;//cleared
}
const DLListNode* DLList::after_last_node() const {
    return &trailer;//cleared
}
bool DLList::is_empty() const {
    return (header.next == &trailer);//cleared
}
int DLList::first() const {
    if (this->is_empty()) {throw "List is Empty";}
    return header.next->obj;//cleared
}
int DLList::last() const {
    if (this->is_empty()) {throw "List is Empty";}
    return trailer.prev->obj;
}
void DLList::insert_first(int obj) {
    DLListNode *x = new DLListNode(obj);
    header.next->prev = x;
    x->next = header.next;
    header.next = x;
    x->prev = &header;//cleared
}
int DLList::remove_first() {
    if (this->is_empty()) {throw "List is Empty";}
    DLListNode *x = header.next;
    header.next = x->next;
    x->next->prev = &header;
    int y = x->obj;
    delete x;
    return y;//cleared
}
void DLList::insert_last(int obj) {
    DLListNode *x = new DLListNode(obj);
    trailer.prev->next = x;
    x->prev = trailer.prev;
    trailer.prev = x;
    x->next = &trailer;//cleared
}
int DLList::remove_last() {
    if (this->is_empty()) {throw "List is Empty";}
    DLListNode *x = trailer.prev;
    x->prev->next = &trailer;//switch next line
    trailer.prev = x->prev;
    int y = x->obj;
    delete x;
    return y;
}
void DLList::insert_after(DLListNode &p, int obj) {
    if (this->is_empty()) {throw "List is Empty";}
    DLListNode *x = new DLListNode(obj);
    p.next->prev = x;
    x->next = p.next;
    x->prev = &p;
    p.next = x;//cleared
}
void DLList::insert_before(DLListNode &p, int obj) {
    if (this->is_empty()) {throw "List is Empty";}
    DLListNode *x = new DLListNode(obj);
    p.prev->next = x;
    x->prev = p.prev;
    x->next = &p;
    p.prev = x;//cleared
}
int DLList::remove_after(DLListNode &p) {
    if (this->is_empty()) {throw "List is Empty";}
    if (&trailer == p.next) {throw "Not possible to remove trailer node";}
    DLListNode *x = p.next;
    x->next->prev = &p;
    p.next = x->next;
    int y = x->obj;
    delete x;
    return y;//cleared
}
int DLList::remove_before(DLListNode &p) {
    if (this->is_empty()) {throw "List is Empty";}
    if (&header == p.prev) {throw "Not possible to remove trailer node";}
    DLListNode *x = p.prev;
    x->prev->next = &p;
    p.prev = x->prev;
    int y = x->obj;
    delete x;
    return y;
}
ostream& operator<<(ostream& out, const DLList& dll) {
    try {
        if (!dll.is_empty()) {
            DLListNode *x = dll.first_node();
            while (x != dll.after_last_node()) {
                out << x->obj << " ";
                x = x->next;
            }
            out << endl;
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