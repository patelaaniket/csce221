#include "Library.h"
#include "TemplatedDLList.h"
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

vector<Record> Library::search(string title) {
    string y = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int idx = y.find(title.substr(0, 1));
    vector<Record> list;
    DLListNode<Record> *curr = book_db[idx].first_node();
    while (curr) {
        if (curr->obj.get_title() == title) {
            list.push_back(curr->obj);
            curr = curr->next;
        }
        curr = curr->next;
    }
    return list;
}
int Library::import_database(std::string filename) {
    int cnt = 0;
    ifstream is(filename);
    if (is.is_open()) {
        while (!is.eof()) {
            Record newRec;
            is >> newRec;
            if (newRec.get_title() != "") {
                vector<Record> y = search(newRec.get_title());
                bool dup = false;
                for (int i = 0; i < y.size(); i++) {
                    if (newRec == y[i]) {
                        dup = true;
                    }
                }
                if (!dup) {
                    add_record(newRec);
                    cnt++;
                } 
            }
                  
        }
    }
    return cnt;
}
int Library::export_database(std::string filename) {
    int cnt = 0;
    ofstream os(filename);
    if (os.is_open()) {
        for (int i = 0; i < book_db.size(); i++) {
            if (!book_db[i].is_empty()) {
                os << book_db[i];
                cnt++;
            }
        }
    }
    return cnt;
}
void Library::print_database() {
    for (int i = 0; i < book_db.size(); i++) {
        cout << book_db[i];
    }
}
bool Library::add_record(Record book) {
    string y = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int idx = y.find(book.get_title().substr(0, 1));
    //DLListNode<Record> *curr = book_db[idx].first_node()->next;
    book_db[idx].insert_last(book);
    // while (curr) {
    //     if (curr->obj == book) {
    //         return false;
    //     }
    //     Record temp = curr->obj;
    //     if (temp.get_title() == book.get_title()) {
    //         if (temp.get_author() == book.get_title()) {
    //             if (temp.get_ISBN() > book.get_ISBN()) {
    //                 book_db[idx].insert_after(*curr, book);
    //                 break;
    //             }
    //         }
    //         else if (temp.get_author() > book.get_author()) {
    //             book_db[idx].insert_after(*curr, book);
    //             break;
    //         }
    //     }
    //     else if (temp.get_title() > book.get_title() && curr->next && book.get_title() > curr->next->obj.get_title()) {
    //         book_db[idx].insert_after(*curr, book);
    //         break;
    //     }
    //     curr = curr->next;
    // }
    return true;
}
void Library::remove_record(Record book) {
    string y = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int idx = y.find(book.get_title().substr(0, 1));
    DLListNode<Record> *curr = book_db[idx].first_node();
    while (curr) {
        if (curr->obj == book) {
            book_db[idx].remove_after(*curr->prev);
        }
        curr = curr->next;
    }
}
char Library::prompt_yes_no() {
    char in;
    do {
        cout << "Please enter either \"y\" or \"n\"";
        cin >> in;
    }
    while (!cin.fail() && in != 'y' && in != 'n' && in != 'Y' && in != 'N');
    if (in == 'y') {return 'Y';}
    if (in == 'n') {return 'N';}
    return in;
}
int Library::prompt_menu(std::vector<std::string> v) {
    int n;
    cout << "Please select an option (type the number before your option): " << endl;
    int i;
    for (i = 0; i < v.size(); i++) {
        cout << i + 1 << ". " << v[i] << endl;
    }
    cout << i + 1 << "Select a valid number" << endl;
    cin >> n;
    while (!n <= i && !n >= 1) {
        cout << "Select a valid number" << endl;
        cin >> n;
    }
    return n-1;
}
Record Library::prompt_record() {
    Record rec;
    string in = prompt_string("Please enter a title: ");
    rec.set_title(in);
    cout << endl;
    in = prompt_string("Please enter author: ");
    rec.set_author(in);
    cout << endl;
    in = prompt_string("Please enter ISBN: ");
    rec.set_ISBN(in);
    cout << endl;
    in = prompt_string("Please enter year: ");
    rec.set_year(in);
    cout << endl;
    in = prompt_string("Please enter edition: ");
    rec.set_edition(in);
    cout << endl;
    return rec;
}
string Library::prompt_title() {
    return prompt_string("Enter the book title: ");
}
string Library::prompt_string(std::string prompt) {
    string in;
    getline(cin, in);
    return in;
}