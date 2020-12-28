#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>
using namespace std;

class Record {
private:
    //member variables
    string title;
    string author;
    string isbn;
    string year;
    string edition;
public:
    void set_title(string t);
    string get_title() const;
    void set_author(string a);
    string get_author() const;
    void set_ISBN(string i);
    string get_ISBN() const;
    void set_year(string y);
    string get_year() const;
    void set_edition(string e);
    string get_edition() const;
    //accessor/mutator functions
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
#endif